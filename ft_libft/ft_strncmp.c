/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbechon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:37:10 by nbechon           #+#    #+#             */
/*   Updated: 2022/11/21 14:59:01 by nbechon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;
	size_t			i;

	dest = (unsigned char *)s1;
	src = (unsigned char *)s2;
	i = 0;
	while (n--)
	{
		if (dest[i] != src[i] || src[i] == 0 || dest[i] == 0)
			return (dest[i] - src[i]);
		i++;
	}
	return (0);
}
