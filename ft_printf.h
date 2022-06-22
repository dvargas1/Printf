/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 22:49:01 by dvargas           #+#    #+#             */
/*   Updated: 2022/06/22 18:38:53 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "unistd.h"
# include "stdarg.h"
# include "stdlib.h"

int		ft_printf(const char *str, ...);
int		ft_treatchar(char str, va_list list);
int		ft_putstr(char *str);
int		ft_putchar(int c);
int		ft_putnbr(int nb);
int		ft_putnbru(unsigned int nb);
int		ft_puthex(unsigned int i, char *base);
int		ft_putp(void *i);
int		nbsize(long nb);
int		nbsize16(unsigned int nb);
int		nbsizeptr(unsigned long nb);
char	*ft_hex16base(unsigned int i, char *base);
char	*ft_hexptr(unsigned long nb, char *base);
char	*ft_utoa(unsigned int i);
char	*ft_itoa(int n);

#endif
