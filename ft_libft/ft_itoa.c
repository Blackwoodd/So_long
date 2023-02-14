/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbechon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:34:23 by nbechon           #+#    #+#             */
/*   Updated: 2022/11/16 12:02:34 by nbechon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_itoa_size(int n)
{
	int	size;

	size = 0;
	if (n < 0 && n > -2147483648)
	{
		size++;
		n = -n;
	}
	else if (n == 0)
		return (1);
	else if (n == -2147483648)
		return (11);
	while (n >= 1)
	{
		n /= 10;
		size++;
	}
	return (size);
}

int	ft_neg(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

int	ft_tmp(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				i;
	int				size;
	int				neg;
	unsigned int	tmp;

	i = 1;
	size = ft_itoa_size(n);
	neg = ft_neg(n);
	str = malloc(sizeof(char) * ft_itoa_size(n) + 1);
	if (!str)
		return (NULL);
	tmp = ft_tmp(n);
	if (tmp == 0)
		str[tmp] = '0';
	while (tmp >= 1)
	{
		str[size - i] = (tmp % 10) + '0';
		tmp /= 10;
		i++;
	}
	if (neg)
		*str = '-';
	str[size] = '\0';
	return (str);
}
