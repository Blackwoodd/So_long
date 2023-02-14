/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfupx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbechon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:39:36 by nbechon           #+#    #+#             */
/*   Updated: 2022/11/29 15:48:54 by nbechon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_hexa_writer(unsigned int nb, int i, int *len)
{
	char	c;

	if (nb >= 16)
	{
		ft_hexa_writer(nb / 16, i - 1, len);
		c = HEXA_UP[nb % 16];
		*len += write(1, &c, 1);
	}
	else
	{
		c = HEXA_UP[nb];
		*len += write(1, &c, 1);
	}
}

int	ft_putnbr_hexa_up(unsigned int nb, int *len)
{
	ft_hexa_writer(nb, ft_len_nb_hexa(nb) - 1, len);
	return (*len);
}

int	ft_printer_upperx(int nb)
{
	int	len;

	len = 0;
	ft_putnbr_hexa_up(nb, &len);
	return (len);
}
