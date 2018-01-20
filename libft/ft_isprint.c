/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorunsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 20:47:36 by akorunsk          #+#    #+#             */
/*   Updated: 2017/10/26 21:13:20 by akorunsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
