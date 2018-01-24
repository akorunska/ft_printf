/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:49:13 by akorunsk          #+#    #+#             */
/*   Updated: 2017/12/01 10:25:25 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <locale.h>

int		main(void)
{
	int rv2;
	int rv1;
//	char r[] = {35, -12, 0};

	setlocale(LC_ALL, "");
	rv1 = printf("%.5S", L"ача");
	printf("\n");
	rv2 = ft_printf("%.5S", L"ача");
	printf("\n");
	printf("original return value is %i, yours is %i", rv1, rv2);
	printf("\n");
	printf("\n");

	return (0);
}
