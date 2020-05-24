#!/usr/local/bin/python3

import collections
import os
import random
import statistics
import subprocess
import sys

class Test:

    def __init__(self, program, args, res, opers=None):
        self.program = program
        self.args = args.split() if type(args) is str else args
        self.opers = opers if opers else list()
        
        if res.capitalize() == "Error":
            self.out = ""
            self.err = "Error\n"
        elif res.upper() == "OK":
            self.out = "OK\n"
            self.err = ""
        elif res.upper() == "KO":
            self.out = "KO\n"
            self.err = ""
        elif res == "":
            self.out = ""
            self.err = ""
        else:
            raise ValueError
        
        if '/' not in self.program:
            self.program = f"./{self.program}"
        if type(self.opers) is str:
            self.opers = self.opers.split()
            
    def run(self):
        p = subprocess.Popen(
            [self.program] + self.args,
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE
        )

        for oper in self.opers:
            p.stdin.write(oper.encode() + '\n'.encode())
        p.stdin.close()
    
        p.wait()
        self.actual_out = p.stdout.read().decode()
        self.actual_err = p.stderr.read().decode()
        
        return (
            self.actual_out == self.out and
            self.actual_err == self.err
        )

class PipeTest:
    
    def __init__(self, args, max_noper=float("inf"), min_noper=0):
        self.args = args.split() if type(args) is str else args
        self.max_noper = max_noper
        self.min_noper = min_noper
    
    def run(self):
        self.actual_noper = 0

        push_swap = subprocess.Popen(
            ["./push_swap"] + self.args,
            stdout=subprocess.PIPE,
        )
        checker = subprocess.Popen(
            ["./checker"] + self.args,
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE
        )
    
        push_swap.wait()
    
        while True:
            oper = push_swap.stdout.readline()
            if not oper:
                break
            
            checker.stdin.write(oper)
            self.actual_noper += 1
        
        checker.stdin.close()
        checker.wait()

        self.actual_out = checker.stdout.read().decode()
        self.actual_err = checker.stderr.read().decode()
        
        return (
            self.actual_err == "" and
            self.actual_out == "OK\n" and
            self.actual_noper <= self.max_noper and
            self.actual_noper >= self.min_noper
        )

class Suite:
    
    suites = list()

    def __init__(self, name):
        self.name = name
        self.tests = list()
        self.nsuccess = 0
        Suite.suites.append(self)
    
    def add(self, test):
        self.tests.append(test)
    
    def run(self):
        print (f"Running '{self.name}': ")
    
        for test in self.tests:
            if test.run() is False:
                print('✗', end="")
                for _ in range(len(self.tests) - 1 - self.nsuccess):
                    print('⚬', end="")
            
                print("\n\nTrace:")
                print(f"    {test.program} {' '.join(test.args)}")
                print(f"    stdout: {repr(test.actual_out):9s} (expected {repr(test.out)})")
                print(f"    stderr: {repr(test.actual_err):9s} (expected {repr(test.err)})")
                print()
                return False
            
            print(u'✓', end='')
            self.nsuccess += 1
        
        print("\n")
        return True
    
    @classmethod
    def run_suites(cls):
        nsuccess = 0
        for suite in cls.suites:
            nsuccess += suite.run()
        
        nfail = len(cls.suites) - nsuccess
        ntest_total = sum(len(suite.tests) for suite in cls.suites)
        print(f"ran {ntest_total} tests, {nsuccess} suites succeeded, {nfail} suites failed")
        if nfail == 0:
            print ("\033[92mSUCCESS\033[0m\n")
        else:
            print ("\033[93mFAIL\033[0m\n")
        
        cls.suites = list()
        return nfail == 0

def test_performance(nval, ntests):
    nopers = []
    data = [str(val) for val in range(1, nval + 1)]
    for _ in range(ntests):
        random.shuffle(data)
        test = PipeTest(data)
        test.run()
        nopers.append(test.actual_noper)
    print (
        f"{nval} random values:\n"
        f"min={min(nopers)}, avg={statistics.mean(nopers):.1f}, max={max(nopers)} ({ntests} datapoints)\n"
    )
    return max(nopers)

def prepare_suits():
	suite = Suite("checker - non numeric parameters")
	suite.add(Test("checker", "1 a", "Error"))
	suite.add(Test("checker", "1 a 3", "Error"))
	suite.add(Test("checker", "1 2a567 3", "Error"))
	
	suite = Suite("checker - duplicate numeric parameters")
	suite.add(Test("checker", "1 1", "Error"))
	suite.add(Test("checker", "1 2 1", "Error"))
	suite.add(Test("checker", "1 2 2", "Error"))
	suite.add(Test("checker", "-1 -1", "Error"))
	suite.add(Test("checker", "-1 2 -1", "Error"))
	suite.add(Test("checker", "-2 -1 -1", "Error"))
	
	suite = Suite("checker - parameters greater than MAXINT")
	suite.add(Test("checker", "2147483648", "Error"))
	suite.add(Test("checker", "1 2147483648", "Error"))
	suite.add(Test("checker", "2147483648 1", "Error"))
	suite.add(Test("checker", "1 2147483648 1", "Error"))
	suite.add(Test("checker", "-2147483649", "Error"))
	suite.add(Test("checker", "1 -2147483649", "Error"))
	suite.add(Test("checker", "-2147483649 1", "Error"))
	suite.add(Test("checker", "1 -2147483649 1", "Error"))
	suite.add(Test("checker", "1 999999999999999999999999 1", "Error"))
	suite.add(Test("checker", "1 -999999999999999999999999 1", "Error"))
	
	suite = Suite("checker - no parameters")
	suite.add(Test("checker", "", ""))
	
	suite = Suite("checker - illegal actions")
	suite.add(Test("checker", "1 2 3", "Error", "sp"))                
	suite.add(Test("checker", "1 3 2", "Error", "sp"))                
	suite.add(Test("checker", "1 3 2", "Error", "sa sp"))                
	suite.add(Test("checker", "1 3 2", "Error", "sp sa"))                               
	suite.add(Test("checker", "1 3 2", "Error", ['sa ', 'sa']))                               
	suite.add(Test("checker", "1 3 2", "Error", [' sa', 'sa']))                               
	suite.add(Test("checker", "1 3 2", "Error", [' sa ', 'sa']))                               
	suite.add(Test("checker", "1 3 2", "Error", ['sa', 'sa ']))                               
	suite.add(Test("checker", "1 3 2", "Error", ['sa', ' sa']))                               
	suite.add(Test("checker", "1 3 2", "Error", ['sa', 'sa ']))                               
	suite.add(Test("checker", "1 3 2", "Error", ['sa', ' sa ']))
	
	suite = Suite("checker - false tests")
	suite.add(Test("checker", "0 9 1 8 2 7 3 6 4 5", "KO", "sa pb rrr"))
	suite.add(Test("checker", "4 2 3 1", "KO", "rr pb ra pa"))
	suite.add(Test("checker", "4 2 3 1", "KO", "rr pb ra pa"))
	suite.add(Test("checker", "3 1 5 8 2 7 4 10 9 6", "KO", "ra pb pb ra pb ra pb pb ra pa ra pa rra pa ra pa rra rra pa rra pa rra rra"))
	
	suite = Suite("checker - right tests")
	suite.add(Test("checker", "0 1 2", "OK"))
	suite.add(Test("checker", "0 9 1 8 2", "OK", "pb ra pb ra sa ra pa pa"))
	suite.add(Test("checker", "3 1 5 8 2 7 4 10 9 6", "OK", "pb ra pb pb ra pb ra pb pb ra pa ra pa rra pa ra pa rra rra pa rra pa rra rra"))
	
	suite = Suite("push_swap - identity test")
	suite.add(Test("push_swap", "42", ""))
	suite.add(Test("push_swap", "0 1 2 3", ""))
	suite.add(Test("push_swap", "0 1 2 3 4 5 6 7 8 9", ""))
	
	suite = Suite("push_swap - simple version")
	suite.add(PipeTest("2 1 0", max_noper=3, min_noper=2))
	
	suite = Suite("push_swap - another simple version")
	suite.add(PipeTest("1 5 2 4 3", 12))
	data = [str(val) for val in range(1, 6)]
	for _ in range(20):
	    random.shuffle(data)
	    suite.add(PipeTest(data, 12))

if __name__ == "__main__":
	if len(sys.argv) == 2:
		sys.chdir(sys.argv[1])
	if len(sys.argv) > 2 or not os.path.exists("./checker") or not os.path.exists("./push_swap"):
		sys.exit(f"Usage: {__file__} <path-to-project-directory>")

	prepare_suits()
	Suite.run_suites()

	test_performance(5, 120)
	test_performance(100, 50)
	test_performance(500, 10)
