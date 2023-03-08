/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:20:28 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/02/09 13:20:31 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_char(va_list f)
{
	char	c;

	c = va_arg(f, int);
	write(1, &c, 1);
	return (1);
}

static int	ft_str(va_list f)
{
	char	*str;

	str = va_arg(f, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

static int	ft_case(va_list f, char c)
{
	int	res;

	res = 0;
	if (c == 'd' || c == 'i')
		res += ft_int(f);
	else if (c == 'u')
		res += ft_unint(f);
	else if (c == 'c')
		res += ft_char(f);
	else if (c == 's')
		res += ft_str(f);
	else if (c == 'p')
		res += ft_ptr(f);
	else if (c == 'x')
		res += ft_hexlow(f);
	else if (c == 'X')
		res += ft_hexupper(f);
	return (res);
}

static int	ft_continu(const char *str, va_list factor, int i, int res)
{
	while (str[++i])
	{
		if (str[i] == '%')
		{
			res += ft_case(factor, str[i + 1]);
			if (str[i + 1] == '%')
			{
				write(1, "%", 1);
				res++;
				i++;
				if (str[i + 1] != '%' && str[i + 1])
				{	
					write(1, &str[i + 1], 1);
					res++;
				}
			}
		}
		else if ((i == 0 && str[i] != '%') || (i > 0 && str[i - 1] != '%'))
		{
			write(1, &str[i], 1);
			res++;
		}
	}
	return (res);
}

int	ft_printf(const char *str, ...)
{
	va_list	factor;
	int		i;
	int		res;

	i = -1;
	res = 0;
	va_start(factor, str);
	res = ft_continu(str, factor, i, res);
	va_end(factor);
	return (res);
}