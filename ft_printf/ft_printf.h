/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbechon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:28:05 by nbechon           #+#    #+#             */
/*   Updated: 2022/12/12 10:28:13 by nbechon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# define HEXA_LOW "0123456789abcdef"
# define HEXA_UP "0123456789ABCDEF"

int		ft_printf(const char *format, ...);
int		ft_printer_c(int c);
int		ft_printer_d(int nb);
int		ft_printer_i(int nb);
int		ft_printer_p(void *list);
int		ft_printer_s(char *str);
int		ft_printer_u(unsigned int nb);
int		ft_printer_x(int nb);
int		ft_printer_upperx(int nb);
void	ft_putnbr_int(int nb, int *len);
void	ft_putnbr_ui(unsigned int nb, int *len);
int		ft_len_nb_hexa(long nb);
void	ft_putchar(char c);
int		ft_putnbr_hexa_up(unsigned int nb, int *len);
int		ft_putnbr_hexa_low(unsigned int nb, int *len);

#endif
