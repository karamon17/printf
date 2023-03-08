/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:15:44 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/02/13 16:15:47 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr(va_list f)
{
	unsigned long long	i;
	char				res[16];
	int					k;
	int					len;

	k = 0;
	i = va_arg(f, unsigned long long);
	if (i == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	while (i != 0)
	{
		if (i % 16 >= 10 && i % 16 <= 15)
			res[k++] = i % 16 - 10 + 'a';
		else
			res[k++] = i % 16 + '0';
		i /= 16;
	}
	len = k + 2;
	write(1, "0x", 2);
	while (--k >= 0)
		write(1, &res[k], 1);
	return (len);
}
