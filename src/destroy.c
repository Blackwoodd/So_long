/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbechon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:29:07 by nbechon           #+#    #+#             */
/*   Updated: 2023/02/08 12:29:11 by nbechon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_destroy_image(t_vars *vars)
{
	free(vars->bu);
	if (vars->knight)
		mlx_destroy_image(vars->mlx, vars->knight);
	if (vars->wall)
		mlx_destroy_image(vars->mlx, vars->wall);
	if (vars->herbe)
		mlx_destroy_image(vars->mlx, vars->herbe);
	if (vars->piece)
		mlx_destroy_image(vars->mlx, vars->piece);
	if (vars->exitopen)
		mlx_destroy_image(vars->mlx, vars->exitopen);
	if (vars->exitclose)
		mlx_destroy_image(vars->mlx, vars->exitclose);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

void	ft_destroy(t_vars *vars)
{
	int	i;

	i = 0;
	close (vars->file);
	while (i != (vars->xmap * vars->ymap))
	{
		free(vars->map[i]);
		free(vars->maptest[i]);
		i++;
	}
	free(vars->map);
	free(vars->maptest);
	ft_destroy_image(vars);
}
