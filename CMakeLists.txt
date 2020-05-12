cmake_minimum_required(VERSION 3.15)
project(push_swap C)

set(CMAKE_C_STANDARD 11)

include_directories(includes)

link_directories(.)

add_executable(push_swap
        includes/libft.h
        includes/push_swap.h
        includes/stack.h
        src/operations/functions/perform_pa.c
        src/operations/functions/perform_pb.c
        src/operations/functions/perform_ra.c
        src/operations/functions/perform_rb.c
        src/operations/functions/perform_rr.c
        src/operations/functions/perform_rra.c
        src/operations/functions/perform_rrb.c
        src/operations/functions/perform_rrr.c
        src/operations/functions/perform_sa.c
        src/operations/functions/perform_sb.c
        src/operations/functions/perform_ss.c
        src/operations/perform_operation.c
        src/stack/append_stack.c
        src/stack/free_stack.c
        src/stack/has_duplicates_stack.c
        src/stack/is_sorted_stack.c
        src/stack/new_stack.c
        src/stack/print_stack.c
        src/stack/pull_stack.c
        src/stack/push_stack.c
        src/stack/reverse_rotate_stack.c
        src/stack/rotate_stack.c
        src/stack/swap_stack.c
        src/stack/min_stack.c
        src/stack/max_stack.c
        src/stack/avg_stack.c
        src/utils/is_numeric_str.c
        src/utils/ft_atoi2.c
        src/push_swap.c src/stack/rank_stack.c src/utils/process_arguments.c src/sorts/simple_sort.c src/process_arguments.c)

target_link_libraries(push_swap
        libftprintf.a)
