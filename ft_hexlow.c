/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:16:41 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/02/13 16:16:43 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlow(va_list f)
{
	unsigned long long	i;
	char				res[10];
	int					k;
	int					len;

	k = 0;
	i = va_arg(f, unsigned int);
	if (i == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (i != 0)
	{
		if (i % 16 >= 10 && i % 16 <= 15)
			res[k] = i % 16 - 10 + 'a';
		else
			res[k] = i % 16 + '0';
		i /= 16;
		k++;
	}
	len = k;
	while (--k > -1)
		write(1, &res[k], 1);
	return (len);
}
