/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi2_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 02:18:23 by unite             #+#    #+#             */
/*   Updated: 2020/03/16 08:42:59 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

char	*ft_atoi2_test(void)
{
	int	rc;
	int	num;

	rc = ft_atoi2("0", &num);
	ASSERT("FT_ATOI2: 0 yields wrong return code\n", rc == 0);
	ASSERT("FT_ATOI2: 0 failed\n", num == 0);
	rc = ft_atoi2("1", &num);
	ASSERT("FT_ATOI2: 1 yields wrong return code\n", rc == 0);
	ASSERT("FT_ATOI2: 1 failed\n", num == 1);
	rc = ft_atoi2("-1", &num);
	ASSERT("FT_ATOI2: -1 yields wrong return code\n", rc == 0);
	ASSERT("FT_ATOI2: -1 failed\n", num == -1);
	rc = ft_atoi2("2147483647", &num);
	ASSERT("FT_ATOI2: 2147483647 yields wrong return code\n", rc == 0);
	ASSERT("FT_ATOI2: 2147483647 failed\n", num == 2147483647);
	rc = ft_atoi2("-2147483648", &num);
	ASSERT("FT_ATOI2: -2147483648 yields wrong return code\n", rc == 0);
	ASSERT("FT_ATOI2: -2147483648 failed\n", num == -2147483648);

	num = 5555;
	rc = ft_atoi2("2147483648", &num);
	ASSERT("FT_ATOI2: 2147483648 yields wrong return code\n", rc == 1);
	ASSERT("FT_ATOI2: 2147483648 failed\n", num == 5555);
	num = 1111;
	rc = ft_atoi2("-2147483649", &num);
	ASSERT("FT_ATOI2: -2147483649 yields wrong return code\n", rc == 1);
	ASSERT("FT_ATOI2: -2147483649 failed\n", num == 1111);

	rc = ft_atoi2("1aaaaaaa", &num);
	ASSERT("FT_ATOI2: 1aaaaaaa yields wrong return code\n", rc == 0);
	ASSERT("FT_ATOI2: 1aaaaaaa failed\n", num == 1);
	rc = ft_atoi2("-1aaaaaaa", &num);
	ASSERT("FT_ATOI2: -1aaaaaaa yields wrong return code\n", rc == 0);
	ASSERT("FT_ATOI2: -1aaaaaaa failed\n", num == -1);
	rc = ft_atoi2("0aaaaaaa", &num);
	ASSERT("FT_ATOI2: 0aaaaaaa yields wrong return code\n", rc == 0);
	ASSERT("FT_ATOI2: 0aaaaaaa failed\n", num == 0);
	
	rc = ft_atoi2("aaaaa5aaaaa", &num);
	ASSERT("FT_ATOI2: aaaaa5aaaaa yields wrong return code\n", rc == 0);
	ASSERT("FT_ATOI2: aaaaa5aaaaa failed\n", num == 0);

	return (0);
}
