/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wsrting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <akorunsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 11:48:00 by akorunsk          #+#    #+#             */
/*   Updated: 2018/01/22 11:48:00 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //
#include <wchar.h>

size_t  ft_wstrlen(char *str)
{
    int     i;
	int		len;

    i = 0;
	len = 0;
    while (str[i] && str[i + 1])
    {
		i += get_wchar_len(str[i]);
		len++;
    }
	printf("len is %i\n", len);
    return (len + 1);
}

void    ft_putnwstr(char *str, t_param *p)
{
    int		i;
	int		j;
    int		to_output;
    int     cur;
    int     wchar_len;

	i = 0;
    cur = 0;
    to_output = (p->precision > 0) ? p->precision : -p->precision;
    while (cur < to_output && str[i] && str[i + 1])
    {
        wchar_len = get_wchar_len(str[i]);
		j = 0;
		while (j < wchar_len)
		{
			ft_putchar(str[i]);
			j++;
			i++;
		}
		cur++;
    }
}

void	print_str(char *str)
{
	int i;

	i = 0;
	printf("\n");
	while (i < 10)
	{
		printf("%i  ", str[i]);
		i++;
	}
	printf("\n");
}

int		handle_wstring(va_list args, t_param *p)
{
	char		*str;
    int			len;

    str = (char *)va_arg(args, void*);
    if (!str)
        str = "(null)";
	print_str(str);
    len = (p->precision_specified && (size_t)p->precision < ft_wstrlen(str)) ? \
			p->precision : ft_wstrlen(str);
    if (p->width_specified && !p->flag_minus && !p->flag_zero)
        ft_putnchar(' ', p->width - len);
    if (p->width_specified && !p->flag_minus && p->flag_zero)
        ft_putnchar('0', p->width - len);
    if (p->precision_specified)
        ft_putnwstr(str, p);
    else
        ft_putstr(str);
    if (p->width_specified && p->flag_minus)
        ft_putnchar(' ', p->width - len);
    return ((p->width > len) ? p->width : len);
}
