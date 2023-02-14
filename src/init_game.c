/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbechon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:40:13 by nbechon           #+#    #+#             */
/*   Updated: 2023/01/27 15:41:44 by nbechon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_init_game(t_vars *vars)
{
	vars->bu = NULL;
	vars->file = 0;
	vars->ymap = 1;
	vars->xmap = 0;
	vars->nombre_de_deplacement = 0;
	vars->w = 0;
	vars->r = 0;
	vars->i = 0;
	vars->x = 0;
	vars->y = 0;
	vars->x2 = 0;
	vars->y2 = 0;
	vars->j = 0;
	vars->len = 0;
	vars->pexitx = 0;
	vars->pexity = 0;
	vars->pheroy = 0;
	vars->pherox = 0;
	vars->lenmap = 0;
}
