/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbechon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:12:01 by nbechon           #+#    #+#             */
/*   Updated: 2022/11/29 15:45:18 by nbechon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_nb_hexa(long nb)
{	
	int	i;

	i = 1;
	while (nb >= 16)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

static void	ft_hexa_writer(unsigned int nb, int i, int *len)
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

int	ft_putnbr_hexa_low(unsigned int nb, int *len)
{
	ft_hexa_writer(nb, ft_len_nb_hexa(nb) - 1, len);
	return (*len);
}

int	ft_printer_x(int nb)
{
	int	len;

	len = 0;
	ft_putnbr_hexa_low(nb, &len);
	return (len);
}
