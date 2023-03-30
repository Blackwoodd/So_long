/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lecture_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbechon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:26:16 by nbechon           #+#    #+#             */
/*   Updated: 2023/02/08 14:50:12 by nbechon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_lecture_map2(t_vars *vars)
{
	while (vars->bu[vars->lenmap] != '\n')
	{
		if (vars->xmap == 41)
			ft_error2(vars);
		vars->xmap++;
		vars->lenmap++;
	}
	while (vars->bu[vars->lenmap])
	{
		if (vars->bu[vars->lenmap] == '\n')
			vars->ymap++;
		if (vars->ymap == 21)
			ft_error2(vars);
		vars->lenmap++;
	}
	return ;
}

void	ft_lecture_map(char *argv, t_vars *vars)
{
	int		buff;

	buff = 0;
	vars->file = open(argv, O_RDONLY);
	if (vars->file == -1)
		exit(0);
	vars->bu = malloc(sizeof(char) * BUFFER_SIZE);
	if (!vars->bu)
		ft_destroy2(vars);
	buff = read(vars->file, vars->bu, BUFFER_SIZE);
	if (buff < 0)
		ft_destroy2(vars);
	vars->bu[buff] = '\0';
	ft_lecture_map2(vars);
	return ;
}

void	ft_condition(t_vars *vars)
{
	if (vars->map[vars->x][vars->y] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->wall, vars->x * 64, vars->y * 64);
	if (vars->map[vars->x][vars->y] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->herbe, vars->x * 64, vars->y * 64);
	if (vars->map[vars->x][vars->y] == 'P')
		ft_position_hero(vars);
	if (vars->map[vars->x][vars->y] == 'E')
		ft_position_exit(vars);
	if (vars->map[vars->x][vars->y] == 'C')
		ft_position_piece(vars);
	return ;
}

void	ft_creation2(t_vars *vars)
{
	if (vars->x == vars->xmap)
	{
		vars->x = 0;
		vars->x2 = 0;
		vars->y++;
		vars->y2++;
	}
	return ;
}

void	ft_creation(t_vars *vars)
{
	int	buff;

	buff = 0;
	vars->map = malloc(sizeof(char *) * vars->lenmap);
	vars->maptest = malloc(sizeof(char *) * vars->lenmap);
	while (vars->bu[buff])
	{
		if (vars->bu[buff] != '\n')
		{
			vars->map[vars->len] = malloc(sizeof(char *) * BUFFER_SIZE);
			vars->maptest[vars->len] = malloc(sizeof(char *) * BUFFER_SIZE);
			vars->maptest[vars->x2][vars->y2] = vars->bu[buff];
			vars->map[vars->x][vars->y] = vars->bu[buff];
			ft_condition(vars);
			vars->x++;
			vars->len++;
			vars->x2++;
		}
		ft_creation2(vars);
		buff++;
	}
	return ;
}
