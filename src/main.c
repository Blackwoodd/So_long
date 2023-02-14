/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbechon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:20:05 by nbechon           #+#    #+#             */
/*   Updated: 2023/02/08 14:48:13 by nbechon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_to_file(char c)
{
	if (c == 'E' || c == 'P' || c == 'C' || c == '0')
		return (1);
	return (0);
}

void	ft_creation_map(t_vars *vars)
{
	t_data	data;
	int		p2herox;
	int		p2heroy;

	ft_creation(vars);
	p2herox = vars->pherox / 64;
	p2heroy = vars->pheroy / 64;
	ft_verif_forme(vars, &data);
	ft_verif_wall(vars);
	ft_verif_inside(vars, &data);
	backtracking(p2herox, p2herox, vars);
	if (vars->r != 1)
	{
		ft_printf("ERROR\n-NO EXIT ACCESS-\n");
		ft_destroy(vars);
	}
	if (vars->w != vars->i)
	{
		ft_printf("ERROR\n-NO COLLECTIBLE ACCESS-\n");
		ft_destroy(vars);
	}
}

int	deal_key(int key, t_vars *vars)
{
	if (key == 0xFF1B)
		ft_destroy(vars);
	if (key == 119)
		ft_haut(vars);
	if (key == 115)
		ft_bas(vars);
	if (key == 97)
		ft_gauche(vars);
	if (key == 100)
		ft_droite(vars);
	if (vars->map[vars->pherox / 64][vars->pheroy / 64] == 'C')
	{
		vars->map[vars->pherox / 64][vars->pheroy / 64] = '0';
		vars->j++;
	}
	if (vars->j == vars->i)
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->exitopen, vars->pexitx, vars->pexity);
	if (vars->map[vars->pherox / 64][vars->pheroy / 64] == 'E')
		ft_destroy(vars);
	return (0);
}

void	ft_init(t_vars *vars)
{
	int	xpm1_x;

	xpm1_x = 0;
	vars->knight = mlx_xpm_file_to_image(vars->mlx, "tiles/knight2.xpm",
			&xpm1_x, &xpm1_x);
	vars->piece = mlx_xpm_file_to_image(vars->mlx, "tiles/piece.xpm",
			&xpm1_x, &xpm1_x);
	vars->exitclose = mlx_xpm_file_to_image(vars->mlx, "tiles/ExitClose.xpm",
			&xpm1_x, &xpm1_x);
	vars->wall = mlx_xpm_file_to_image(vars->mlx, "tiles/wall3.xpm",
			&xpm1_x, &xpm1_x);
	vars->herbe = mlx_xpm_file_to_image(vars->mlx, "tiles/herbe.xpm",
			&xpm1_x, &xpm1_x);
	vars->exitopen = mlx_xpm_file_to_image(vars->mlx, "tiles/exit.xpm",
			&xpm1_x, &xpm1_x);
	if (!vars->knight || !vars->piece || !vars->exitclose || !vars->herbe
		|| !vars->wall || !vars->exitopen)
		ft_destroy_image(vars);
	return ;
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc == 2)
	{
		ft_init_game(&vars);
		ft_verif_ber(argv[1]);
		ft_lecture_map(argv[1], &vars);
		vars.mlx = mlx_init();
		if (!vars.mlx)
			return (ft_destroy2(&vars), 1);
		vars.win = mlx_new_window(vars.mlx, vars.xmap * PIXEL_WIN,
				vars.ymap * PIXEL_WIN, "MON JEU");
		if (!vars.win)
			return (ft_destroy2(&vars), mlx_destroy_display(vars.mlx), 1);
		ft_init(&vars);
		ft_creation_map(&vars);
		mlx_key_hook(vars.win, deal_key, &vars);
		mlx_hook(vars.win, KeyPress, KeyPressMask, 0, 0);
		mlx_hook(vars.win, DestroyNotify, StructureNotifyMask,
			ft_exit, &vars);
		mlx_loop(vars.mlx);
	}
}
