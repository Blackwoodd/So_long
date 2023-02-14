/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbechon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:55:28 by nbechon           #+#    #+#             */
/*   Updated: 2022/11/21 14:56:59 by nbechon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlen(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;
	size_t	j;

	if (!s)
		return (NULL);
	j = ft_strlen(s);
	if (start > j)
		str = malloc(sizeof(char));
	else if (len >= j)
		str = malloc(sizeof(char) * (j - start + 1));
	else
		str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[start] && len-- > 0 && start < j)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
