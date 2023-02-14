/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbechon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:30:44 by nbechon           #+#    #+#             */
/*   Updated: 2023/01/16 13:31:02 by nbechon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_haut(t_vars *vars)
{
	if (vars->map[vars->pherox / 64][(vars->pheroy / 64) - 1] != '1')
	{
		if (vars->map[vars->pherox / 64]
			[(vars->pheroy / 64) - 1] == 'E' && vars->i == vars->j)
		{
			vars->nombre_de_deplacement += 1;
			ft_printf("Mouvement : %d\n", vars->nombre_de_deplacement);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->herbe,
				vars->pherox, vars->pheroy);
			vars->pheroy -= 64;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->knight,
				vars->pherox, vars->pheroy);
		}
		else if (vars->map[vars->pherox / 64]
			[(vars->pheroy / 64) - 1] != 'E')
		{	
			vars->nombre_de_deplacement += 1;
			ft_printf("Mouvement : %d \n", vars->nombre_de_deplacement);
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->herbe, vars->pherox, vars->pheroy);
			vars->pheroy -= 64;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->knight,
				vars->pherox, vars->pheroy);
		}
	}
}

void	ft_bas(t_vars *vars)
{
	if (vars->map[vars->pherox / 64][(vars->pheroy / 64) + 1] != '1')
	{
		if (vars->map[vars->pherox / 64]
			[(vars->pheroy / 64) + 1] == 'E' && vars->i == vars->j)
		{
			vars->nombre_de_deplacement += 1;
			ft_printf("Mouvement : %d\n", vars->nombre_de_deplacement);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->herbe,
				vars->pherox, vars->pheroy);
			vars->pheroy += 64;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->knight,
				vars->pherox, vars->pheroy);
		}
		else if (vars->map[vars->pherox / 64]
			[(vars->pheroy / 64) + 1] != 'E')
		{
			vars->nombre_de_deplacement += 1;
			ft_printf("Mouvement : %d\n", vars->nombre_de_deplacement);
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->herbe, vars->pherox, vars->pheroy);
			vars->pheroy += 64;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->knight,
				vars->pherox, vars->pheroy);
		}
	}
}

void	ft_droite(t_vars *vars)
{
	if (vars->map[(vars->pherox / 64) + 1][vars->pheroy / 64] != '1')
	{
		if (vars->map[(vars->pherox / 64) + 1]
			[vars->pheroy / 64] == 'E' && vars->i == vars->j)
		{
			vars->nombre_de_deplacement += 1;
			ft_printf("Mouvement : %d\n", vars->nombre_de_deplacement);
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->herbe, vars->pherox, vars->pheroy);
			vars->pherox += 64;
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->knight, vars->pherox, vars->pheroy);
		}
		else if (vars->map[(vars->pherox / 64) + 1]
			[vars->pheroy / 64] != 'E')
		{
			vars->nombre_de_deplacement += 1;
			ft_printf("Mouvement : %d\n", vars->nombre_de_deplacement);
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->herbe, vars->pherox, vars->pheroy);
			vars->pherox += 64;
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->knight, vars->pherox, vars->pheroy);
		}
	}
}

void	ft_gauche(t_vars *vars)
{
	if (vars->map[(vars->pherox / 64) - 1][vars->pheroy / 64] != '1')
	{
		if (vars->map[(vars->pherox / 64) - 1]
			[vars->pheroy / 64] == 'E' && vars->i == vars->j)
		{
			vars->nombre_de_deplacement += 1;
			ft_printf("Mouvement : %d\n", vars->nombre_de_deplacement);
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->herbe, vars->pherox, vars->pheroy);
			vars->pherox -= 64;
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->knight, vars->pherox, vars->pheroy);
		}
		else if (vars->map[(vars->pherox / 64) - 1]
			[vars->pheroy / 64] != 'E')
		{
				vars->nombre_de_deplacement += 1;
			ft_printf("Mouvement : %d\n", vars->nombre_de_deplacement);
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->herbe, vars->pherox, vars->pheroy);
			vars->pherox -= 64;
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->knight, vars->pherox, vars->pheroy);
		}
	}
}
