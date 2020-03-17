/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 11:14:15 by unite             #+#    #+#             */
/*   Updated: 2020/03/16 19:49:13 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static char	*enqueue_dequeue_queue_test(void)
{
	t_queue *q;
	char	*c;
	int		rc;

	rc = new_queue(&q);
	ASSERT("QUEUE: Couldn't allocate new queue\n", rc == 0);

	rc = enqueue_queue(q, "Allan Black");
	ASSERT("QUEUE: Couldn't enqueue first element\n", rc == 0);
	rc = enqueue_queue(q, "Vermont Andante");
	ASSERT("QUEUE: Couldn't enqueue second element\n", rc == 0);
	rc = enqueue_queue(q, "Meg Tong");
	ASSERT("QUEUE: Couldn't enqueue third element\n", rc == 0);
	rc = enqueue_queue(q, "Isobel Herschel");
	ASSERT("QUEUE: Couldn't enqueue fourth element\n", rc == 0);
	rc = enqueue_queue(q, "Ivan Petrov");
	ASSERT("QUEUE: Couldn't enqueue fifth element\n", rc == 0);

	rc = dequeue_queue(q, &c);
	ASSERT("QUEUE: Couldn't dequeue first element\n", rc == 0);
	ASSERT("QUEUE: First element isn't Allan Black\n", ft_strequ(c, "Allan Black"));
	rc = dequeue_queue(q, &c);
	ASSERT("QUEUE: Couldn't dequeue second element\n", rc == 0);
	ASSERT("QUEUE: Second element isn't Vermont Andante\n", ft_strequ(c, "Vermont Andante"));
	rc = dequeue_queue(q, &c);
	ASSERT("QUEUE: Couldn't dequeue third element\n", rc == 0);
	ASSERT("QUEUE: Third element isn't Meg Tong\n", ft_strequ(c, "Meg Tong"));
	rc = dequeue_queue(q, &c);
	ASSERT("QUEUE: Couldn't dequeue fourth element\n", rc == 0);
	ASSERT("QUEUE: Fourth element isn't Isobel Herschel\n", ft_strequ(c, "Isobel Herschel"));
	rc = dequeue_queue(q, &c);
	ASSERT("QUEUE: Couldn't dequeue fifth element\n", rc == 0);
	ASSERT("QUEUE: Fifth element isn't Ivan Petrov\n", ft_strequ(c, "Ivan Petrov"));

	free_queue(q);
	return (0);
}

static char	*copy_queue_test(void)
{
	t_queue	*q1;
	t_queue	*q2;
	char	*c;
	int		rc;

	new_queue(&q1);
	enqueue_queue(q1, "Allan Black");
	enqueue_queue(q1, "Vermont Andante");
	enqueue_queue(q1, "Meg Tong");
	enqueue_queue(q1, "Isobel Herschel");
	enqueue_queue(q1, "Ivan Petrov");

	rc = copy_queue(q1, &q2);
	free_queue(q1);
	ASSERT("QUEUE: Couldn't copy queue\n", rc == 0);

	dequeue_queue(q2, &c);
	ASSERT("QUEUE: First copied element isn't Allan Black\n", ft_strequ(c, "Allan Black"));
	dequeue_queue(q2, &c);
	ASSERT("QUEUE: Second copied element isn't Vermont Andante\n", ft_strequ(c, "Vermont Andante"));
	dequeue_queue(q2, &c);
	ASSERT("QUEUE: Third copied element isn't Meg Tong\n", ft_strequ(c, "Meg Tong"));
	dequeue_queue(q2, &c);
	ASSERT("QUEUE: Fourth copied element isn't Isobel Herschel\n", ft_strequ(c, "Isobel Herschel"));
	dequeue_queue(q2, &c);
	ASSERT("QUEUE: Fifth copied element isn't Ivan Petrov\n", ft_strequ(c, "Ivan Petrov"));

	free_queue(q2);
	return (0);
}

static char		*len_queue_test(void)
{
	t_queue	*q;
	int		rc;

	new_queue(&q);
	rc = len_queue(q);
	ASSERT("QUEUE: Wrong queue length with empty queue\n", rc == 0);
	free_queue(q);

	new_queue(&q);
	enqueue_queue(q, "a");
	rc = len_queue(q);
	ASSERT("QUEUE: Wrong queue length with a in queue\n", rc == 1);
	free_queue(q);

	new_queue(&q);
	enqueue_queue(q, "a");
	enqueue_queue(q, "b");
	rc = len_queue(q);
	ASSERT("QUEUE: Wrong queue length with a->b in queue\n", rc == 2);
	free_queue(q);

	new_queue(&q);
	enqueue_queue(q, "a");
	enqueue_queue(q, "b");
	enqueue_queue(q, "c");
	rc = len_queue(q);
	ASSERT("QUEUE: Wrong queue length with 1->2->3 in queue\n", rc == 3);
	free_queue(q);

	return (0);
}

char		*queue_test(void)
{
	RUN_TEST(enqueue_dequeue_queue_test);
	RUN_TEST(copy_queue_test);
	RUN_TEST(len_queue_test);
	return (0);
}
