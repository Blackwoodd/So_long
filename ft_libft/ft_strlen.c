/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbechon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:35:13 by nbechon           #+#    #+#             */
/*   Updated: 2022/11/15 15:16:26 by nbechon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

//int	main()
//{
//	char	t[] = "COUCOU";
//	
//	ft_strlen(t);
//	printf("%ld", ft_strlen(t));
//
//	strlen(t);
//	printf("%ld", strlen(t));
//		
//	return (0);
//	
//}
