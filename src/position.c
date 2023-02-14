/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbechon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:19:29 by nbechon           #+#    #+#             */
/*   Updated: 2023/01/18 14:19:32 by nbechon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_position_hero(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->knight, vars->x * 64, vars->y * 64);
	vars->pherox = (vars->x * 64);
	vars->pheroy = (vars->y * 64);
}

void	ft_position_exit(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->exitclose, vars->x * 64, vars->y * 64);
	vars->pexitx = vars->x * 64;
	vars->pexity = vars->y * 64;
}

void	ft_position_piece(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->piece, vars->x * 64, vars->y * 64);
	vars->i++;
}
