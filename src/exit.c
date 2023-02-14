/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbechon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:35:31 by nbechon           #+#    #+#             */
/*   Updated: 2023/01/27 15:28:36 by nbechon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_exit(t_vars *vars)
{
	ft_destroy(vars);
	return (0);
}

void	ft_error2(t_vars *vars)
{
	ft_printf ("ERROR\n");
	ft_printf ("-MAP VERY BIG-\n");
	ft_destroy(vars);
}

void	ft_error3(t_vars *vars)
{
	ft_printf ("ERROR\n");
	ft_printf ("-FOR BAD WALL-\n");
	ft_destroy2(vars);
}

void	ft_destroy2(t_vars *vars)
{
	int	i;

	i = 0;
	close (vars->file);
	while (i != (vars->xmap * vars->ymap) - 1)
	{
		free(vars->map[i]);
		free(vars->maptest[i]);
		i++;
	}
	free(vars->map);
	free(vars->maptest);
	ft_destroy_image(vars);
}
