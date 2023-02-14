/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbechon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:07:04 by nbechon           #+#    #+#             */
/*   Updated: 2023/01/18 14:29:50 by nbechon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "../minilibx/mlx_int.h"
# include "../minilibx/mlx.h"

// # if BUFFER_SIZE != 1000
// #  undef BUFFER_SIZE
// # endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif
# define PIXEL_WIN	64

typedef struct s_data
{
	int	e;
	int	c;
	int	p;
	int	len1;
	int	len2;
	int	u;
	int	t;
}				t_data;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	void		*knight;
	void		*piece;
	void		*exitclose;
	void		*wall;
	void		*herbe;
	void		*exitopen;
	int			file;
	int			len;
	int			lenmap;
	int			pherox;
	int			pheroy;
	int			pexitx;
	int			pexity;
	long int	nombre_de_deplacement;
	int			i;
	int			j;
	int			x;
	int			y;
	int			w;
	int			x2;
	int			y2;
	int			ymap;
	int			xmap;
	int			r;
	char		**maptest;
	char		**map;
	char		*bu;
}				t_vars;

void	ft_init_game(t_vars *vars);
void	ft_error3(t_vars *vars);
void	ft_condition(t_vars *vars);
void	ft_destroy_image(t_vars *vars);
void	backtracking(int p2herox, int p2heroy, t_vars *vars);
void	ft_destroy2(t_vars *vars);
void	ft_destroy(t_vars *vars);
void	ft_error2(t_vars *vars);
void	ft_verif_ber(char *argv);
void	ft_verif_forme(t_vars *vars, t_data *data);
void	ft_verif_wall(t_vars *vars);
void	ft_haut(t_vars *vars);
void	ft_bas(t_vars *vars);
void	ft_gauche(t_vars *vars);
void	ft_droite(t_vars *vars);
void	ft_creation_map(t_vars *vars);
void	ft_verif_inside(t_vars *vars, t_data *data);
void	ft_lecture_map(char *argv, t_vars *vars);
void	ft_lecture_map2(t_vars *vars);
void	ft_creation(t_vars *vars);
void	ft_position_hero(t_vars *vars);
void	ft_position_exit(t_vars *vars);
void	ft_position_piece(t_vars *vars);
void	ft_creation2(t_vars *vars);
int		ft_exit(t_vars *vars);
int		deal_key(int key, t_vars *vars);
int		ft_to_file(char c);
void	ft_init(t_vars *vars);

#endif
