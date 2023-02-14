/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbechon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:46:19 by nbechon           #+#    #+#             */
/*   Updated: 2023/02/08 14:51:06 by nbechon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_verif_inside(t_vars *vars, t_data *data)
{
	data->len1 = 0;
	data->e = 0;
	data->c = 0;
	data->p = 0;
	while (vars->bu[data->len1])
	{
		if (vars->bu[data->len1] == 'E')
			data->e++;
		if (vars->bu[data->len1] == 'C')
			data->c++;
		if (vars->bu[data->len1] == 'P')
			data->p++;
		data->len1++;
	}
	if (data->e > 1 || data->e == 0 || data->p > 1 || data->p == 0
		|| data->c == 0)
	{
		ft_printf ("ERROR\n");
		ft_printf ("-FOR BAD INSIDE-\n");
		ft_destroy(vars);
		return ;
	}
}

void	ft_verif_forme(t_vars *vars, t_data *data)
{
	data->u = 0;
	data->t = 0;
	data->len2 = 0;
	while (vars->bu[data->len2++] != '\n')
		data->u++;
	data->len2 = 0;
	while (vars->bu[data->len2] != '\0')
	{
		if (vars->bu[data->len2] == '\n')
		{
			if (data->t != data->u)
			{
				ft_printf ("ERROR\n");
				ft_printf ("-BAD FORME-\n");
				ft_destroy2(vars);
			}	
			data->t = -1;
		}
		data->t++;
		data->len2++;
	}
}

void	ft_verif_ber(char *argv)
{
	int	p;

	p = 0;
	while (argv[p])
	{
		if (argv[p] == '.')
		{
			if (argv[p + 1] == 'b' && argv[p + 2]
				== 'e' && argv[p + 3] == 'r' && argv[p + 4] == '\0')
				return ;
			else
				exit (0);
		}
		p++;
	}
}

void	ft_verif_wall(t_vars *vars)
{
	int	len;

	len = 0;
	while (vars->bu[len] != '\n')
	{
		if (vars->bu[len] != '1')
			ft_error3(vars);
		len++;
	}
	while (vars->bu[len] != '\0')
	{
		if (vars->bu[len] == '\n')
		{	
			if ((vars->bu[len - 1] != '1' || vars->bu[len + 1] != '1'))
				ft_error3(vars);
		}
		len++;
	}
}

void	backtracking(int p2herox, int p2heroy, t_vars *vars)
{
	if ((ft_to_file(vars->maptest[p2herox][p2heroy])) == 0)
		return ;
	if (vars->maptest[p2herox][p2heroy] == 'C')
		vars->w++;
	if (vars->maptest[p2herox][p2heroy] == 'E')
		vars->r++;
	vars->maptest[p2herox][p2heroy] = 'X';
	backtracking(p2herox - 1, p2heroy, vars);
	backtracking(p2herox + 1, p2heroy, vars);
	backtracking(p2herox, p2heroy - 1, vars);
	backtracking(p2herox, p2heroy + 1, vars);
}
