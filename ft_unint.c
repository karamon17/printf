/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:14:44 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/02/13 16:14:46 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unint(va_list f)
{
	unsigned int	i;
	int				res;

	res = 0;
	i = va_arg(f, unsigned int);
	ft_putnbrun_fd(i, 1);
	if (i == 0)
		return (1);
	while (i != 0)
	{
		i /= 10;
		res++;
	}
	return (res);
}
