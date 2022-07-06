/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arharif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:09:46 by arharif           #+#    #+#             */
/*   Updated: 2022/07/06 15:09:50 by arharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	applyzoom(t_mlx *z)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = (double)z->m_x / (WIN_W / (z->r_max - z->r_min)) + z->r_min;
	mouse_im = (double)z->m_y / (WIN_H / (z->i_max - z->i_min)) + z->i_min;
	z->r_min = interpolate(mouse_re, z->r_min, z->interp);
	z->i_min = interpolate(mouse_im, z->i_min, z->interp);
	z->r_max = interpolate(mouse_re, z->r_max, z->interp);
	z->i_max = interpolate(mouse_im, z->i_max, z->interp);
}

int	mouse_press(int button, int x, int y, t_mlx *z)
{
	x = 0;
	y = 0;
	ft_clear_img(z->img_str);
	if (button == 5)
		z->interp = 0.9;
	else if (button == 4)
		z->interp = 1.1;
	applyzoom(z);
	if (z->id == 1)
		mandelbrot (z);
	else if (z->id == 2)
		julia (z);
	else if (z->id == 3)
		burning_ship (z);
	mlx_put_image_to_window(z->mlx_ptr, z->win_ptr, z->img_ptr, 0, 0);
	return (0);
}

int	mouse_move(int x, int y, t_mlx *z)
{
	z->m_x = x;
	z->m_y = y;
	if (z->id == 2)
	{
		ft_clear_img(z->img_str);
		julia (z);
		mlx_put_image_to_window(z->mlx_ptr, z->win_ptr, z->img_ptr, 0, 0);
	}
	return (0);
}

double	interpolate(double start, double end, double interp)
{
	return (start + ((end - start) * interp));
}

void	my_mlx_pixel_put(int *img_str, int x, int y, int color)
{
	img_str[((int)WIN_W * y) + x] = color;
}
