/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:01:06 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/01/24 18:45:14 by gevorg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbrun_fd(unsigned int n, int fd);
size_t	ft_strlen(const char *str);
int		ft_int(va_list f);
int		ft_hexupper(va_list f);
int		ft_hexlow(va_list f);
int		ft_ptr(va_list f);
int		ft_unint(va_list f);

#endif