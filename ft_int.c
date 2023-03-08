/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:13:29 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/02/13 16:13:31 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_int(va_list f)
{
	int	i;
	int	res;

	res = 0;
	i = va_arg(f, int);
	ft_putnbr_fd(i, 1);
	if (i == 0)
		return (1);
	else if (i < 0)
		res++;
	while (i != 0)
	{
		i /= 10;
		res++;
	}
	return (res);
}
