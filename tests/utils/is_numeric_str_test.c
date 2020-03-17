/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_numeric_str_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 15:25:06 by unite             #+#    #+#             */
/*   Updated: 2020/03/16 08:43:34 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

char		*is_numeric_str_test(void)
{
	int	rc;

	rc = is_numeric_str("0");
	ASSERT("IS_NUMERIC_STR: 0 declared non-numeric\n", rc == 1);
	rc = is_numeric_str("0123456789");
	ASSERT("IS_NUMERIC_STR: 0123456789 declared non-numeric\n", rc == 1);
	rc = is_numeric_str("-0123456789");
	ASSERT("IS_NUMERIC_STR: -0123456789 declared non-numeric\n", rc == 1);

	rc = is_numeric_str("");
	ASSERT("IS_NUMERIC_STR: empty string declared numeric\n", rc == 0);
	rc = is_numeric_str("-");
	ASSERT("IS_NUMERIC_STR: - declared numeric\n", rc == 0);
	rc = is_numeric_str("0a");
	ASSERT("IS_NUMERIC_STR: 0a declared numeric\n", rc == 0);
	rc = is_numeric_str("0123456789a");
	ASSERT("IS_NUMERIC_STR: 0123456789a declared numeric\n", rc == 0);
	rc = is_numeric_str("0123456789a");
	ASSERT("IS_NUMERIC_STR: 0123456789a declared numeric\n", rc == 0);
	rc = is_numeric_str("01234a56789");
	ASSERT("IS_NUMERIC_STR: 01234a56789 declared numeric\n", rc == 0);
	rc = is_numeric_str("01234.56789");
	ASSERT("IS_NUMERIC_STR: 01234.56789 declared numeric\n", rc == 0);
	rc = is_numeric_str("0123456789.");
	ASSERT("IS_NUMERIC_STR: 0123456789. declared numeric\n", rc == 0);
	rc = is_numeric_str("01234-56789");
	ASSERT("IS_NUMERIC_STR: 01234-56789 declared numeric\n", rc == 0);
	rc = is_numeric_str("0123456789-");
	ASSERT("IS_NUMERIC_STR: 0123456789- declared numeric\n", rc == 0);

	return (0);
}
