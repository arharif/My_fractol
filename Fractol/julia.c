/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arharif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:05:04 by arharif           #+#    #+#             */
/*   Updated: 2022/07/06 15:05:11 by arharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia2(int x, int y, t_mlx *mlx)
{
	int		iteration;

	iteration = 1;
	mlx->z.r = mlx->r_min + (x + mlx->t_x)
		/ WIN_W * (mlx->zoom);
	mlx->z.i = mlx->i_min + (y + mlx->t_y)
		/ WIN_H * (mlx->zoom);
	mlx->c.r = mlx->r_min + mlx->m_x
		/ (WIN_W / (mlx->r_max - mlx->r_min));
	mlx->c.i = mlx->i_min + mlx->m_y
		/ (WIN_H / (mlx->i_max - mlx->i_min));
	mlx->tmp = mlx->z;
	while (mlx->z.r * mlx->z.r + mlx->z.i * mlx->z.i < 4
		&& iteration < mlx->max_iter)
	{
		mlx->tmp.r = mlx->z.r * mlx->z.r
			- mlx->z.i * mlx->z.i + mlx->c.r;
		mlx->tmp.i = 2 * mlx->z.r * mlx->z.i + mlx->c.i;
		mlx->z = mlx->tmp;
		iteration++;
	}
	return (iteration);
}

void	julia(t_mlx *mlx)
{
	int				x;
	int				y;
	int				iteration;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			iteration = julia2(x, y, mlx);
			if (iteration == mlx->max_iter)
				mlx->color = 0;
			else
				mlx->color = iteration * mlx->newcolor;
			my_mlx_pixel_put(mlx->img_str, x, y, mlx->color);
			x++;
		}
		y++;
	}
}
