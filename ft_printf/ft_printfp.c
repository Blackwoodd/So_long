/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbechon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:28:39 by nbechon           #+#    #+#             */
/*   Updated: 2022/12/12 10:28:42 by nbechon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_hexa_writer(unsigned long nb, int i, int *len)
{
	char	c;

	if (nb >= 16)
	{
		ft_hexa_writer(nb / 16, i - 1, len);
		c = HEXA_LOW[nb % 16];
		*len += write(1, &c, 1);
	}
	else
	{
		c = HEXA_LOW[nb];
		*len += write(1, &c, 1);
	}
}

int	ft_putnbr_hexa(unsigned long nb)
{
	int	len;

	len = 0;
	ft_hexa_writer(nb, ft_len_nb_hexa(nb) - 1, &len);
	return (len);
}

int	ft_printer_p(void *list)
{
	if (list)
		return (write(1, "0x", 2) + ft_putnbr_hexa((unsigned long) list));
	return (write(1, "(nil)", 5));
}
