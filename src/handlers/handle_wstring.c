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

void	ft_putwstr(int *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putwchar(str[i]);
		i++;
	}
}

void	ft_putnwstr(int *str, int to_output)
{
	int		i;
	int		outputted;
	int		w_len;

	i = 0;
	outputted = 0;
	while (i < to_output && str[i])
	{
		w_len = get_wchar_len(str[i]);
		if (outputted + w_len > to_output)
			return ;
		ft_putwchar(str[i]);
		outputted += w_len;
		i++;
	}
}

int		ft_wstrlen(int *str)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i])
	{
		len += get_wchar_len(str[i]);
		i++;
	}
	return (len);
}

int		handle_wstring(va_list args, t_param *p)
{
	int		*str;
	int		len;

	str = (int *)va_arg(args, void*);
	if (!str)
		str = (int *)L"(null)";
	len = (p->precision_specified && p->precision < ft_wstrlen(str)) ? \
			p->precision : ft_wstrlen(str);
	if (p->width_specified && !p->flag_minus && !p->flag_zero)
		ft_putnchar(' ', p->width - len);
	if (p->width_specified && !p->flag_minus && p->flag_zero)
		ft_putnchar('0', p->width - len);
	if (p->precision_specified)
		ft_putnwstr(str, (p->precision > 0) ? p->precision : -p->precision);
	else
		ft_putwstr(str);
	if (p->width_specified && p->flag_minus)
		ft_putnchar(' ', p->width - len);
	return ((p->width > len) ? p->width : len);
}
