/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbechon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:26:38 by nbechon           #+#    #+#             */
/*   Updated: 2022/11/18 12:36:45 by nbechon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <bsd/string.h>
#include <stdlib.h>

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!little || !big)
		return (0);
	if (!little || little[0] == '\0')
		return ((char *)big);
	while (big[i] && n > 0)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (i + j < n && big[i + j] == little[j])
			{
				j++;
				if (!little[j])
					return ((char *)(big + i));
			}
		}
		i++;
	}
	return (0);
}
