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

int		main(void)
{
	int rv2;
	int rv1;

	rv1 = printf("|printf:   | |{%30S}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("\n");
	rv2 = ft_printf("|ft_printf:| |{%30S}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("\n");
	printf("original return value is %i, yours is %i", rv1, rv2);
	printf("\n");
	printf("\n");

	return (0);
}
