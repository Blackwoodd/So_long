/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbechon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:10:56 by nbechon           #+#    #+#             */
/*   Updated: 2022/11/15 15:06:00 by nbechon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

//int	main()
//{
//	char t;
//	t = 'A';
//	printf("%d", ft_isdigit(t));
//
//	t = '1';
//	printf("%d", ft_isdigit(t));
//
//}
