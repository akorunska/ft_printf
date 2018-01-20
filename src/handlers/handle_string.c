/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 16:50:42 by akorunsk          #+#    #+#             */
/*   Updated: 2017/12/25 16:51:00 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnstr(char *str, t_param *p)
{
	int		i;
	int		to_output;

	i = 0;
	to_output = (p->precision > 0) ? p->precision : -p->precision;
	while (i < to_output && str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int		handle_string(va_list args, t_param *p)
{
	char		*str;
	int			len;

	str = (char *)va_arg(args, void*);
	if (!str)
		str = "(null)";
	len = (p->precision_specified && (size_t)p->precision < ft_strlen(str)) ? \
			p->precision : ft_strlen(str);
	if (p->width_specified && !p->flag_minus && !p->flag_zero)
		ft_putnchar(' ', p->width - len);
	if (p->width_specified && !p->flag_minus && p->flag_zero)
		ft_putnchar('0', p->width - len);
	if (p->precision_specified)
		ft_putnstr(str, p);
	else
		ft_putstr(str);
	if (p->width_specified && p->flag_minus)
		ft_putnchar(' ', p->width - len);
	return ((p->width > len) ? p->width : len);
}
