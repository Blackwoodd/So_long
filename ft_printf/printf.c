/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbechon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:30:23 by nbechon           #+#    #+#             */
/*   Updated: 2022/12/12 10:30:25 by nbechon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_list(char c, va_list args)
{
	if (c == 'c')
		return (ft_printer_c(va_arg(args, int)));
	else if (c == 's')
		return (ft_printer_s(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_printer_p(va_arg(args, void *)));
	else if (c == 'd')
		return (ft_printer_d(va_arg(args, int)));
	else if (c == 'i')
		return (ft_printer_i(va_arg(args, int)));
	else if (c == 'u')
		return (ft_printer_u(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_printer_x(va_arg(args, int)));
	else if (c == 'X')
		return (ft_printer_upperx(va_arg(args, int)));
	else if (c == '%')
		return (write(1, "%", 1));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	len = 0;
	i = -1;
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			len += ft_list(format[i + 1], args);
			i++;
		}
		else
		{
			write(1, &(format[i]), 1);
			len++;
		}
	}
	va_end(args);
	return (len);
}
