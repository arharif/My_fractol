/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arharif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:04:31 by arharif           #+#    #+#             */
/*   Updated: 2022/07/06 15:04:37 by arharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# define WIN_W 500.
# define WIN_H 500.
# define MAX_ITER 100

typedef struct s_complex{
	double	r;
	double	i;
}t_complex;

typedef struct s_mlx
{
	t_complex			z;
	t_complex			c;
	t_complex			tmp;
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	int					*img_str;
	int					bpp;
	int					l;
	int					endian;
	int					t_x;
	int					t_y;
	int					color;
	int					newcolor;
	int					id;
	int					m_x;
	int					m_y;
	int					max_iter;
	double				r_min;
	double				r_max;
	double				i_min;
	double				i_max;
	double				interp;
	double				zoom;
}t_mlx;

void	init(t_mlx *z, char *str);
void	mandelbrot(t_mlx *mlx);
int		ft_close(t_mlx *z);
int		key_press(int keycode, t_mlx *z);
int		mouse_press(int button, int x, int y, t_mlx *z);
int		ft_strcmp(const char *s1, const char *s2);
void	my_mlx_pixel_put(int *img_str, int x, int y, int color);
void	julia(t_mlx *mlx);
void	burning_ship(t_mlx *mlx);
int		mouse_move(int x, int y, t_mlx *z);
double	interpolate(double start, double end, double interp);
void	apply_zoom(t_mlx *mlx, int x, int y);
void	ft_clear_img(int *img_str);
#endif
