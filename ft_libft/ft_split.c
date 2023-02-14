/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbechon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:37:11 by nbechon           #+#    #+#             */
/*   Updated: 2022/11/21 14:35:17 by nbechon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len);

static void	**ft_free_all(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		strs[i++] = NULL;
	}
	free(strs);
	return (NULL);
}

static char	**ft_words_in_tab(const char *s, char c, char **strs)
{
	int	i;
	int	j;
	int	end_last;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		end_last = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > end_last)
		{
			strs[j++] = ft_substr(s, end_last, i - end_last);
			if (!(strs[j - 1]))
				return (*ft_free_all(strs));
		}
	}
	return (strs);
}

char	**ft_split(const char *s, char c)
{
	char	**strs;
	int		i;
	int		end_last;
	int		j;

	if (!s)
		return (NULL);
	j = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		end_last = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > end_last)
			j++;
	}
	strs = malloc(sizeof (char *) * (j + 1));
	if (!strs)
		return (NULL);
	strs[j] = NULL;
	strs = ft_words_in_tab(s, c, strs);
	return (strs);
}
