/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arharif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:07:27 by arharif           #+#    #+#             */
/*   Updated: 2022/07/06 15:07:31 by arharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	init2(t_mlx *z)
{
	z->t_x = 0;
	z->t_y = 0;
	z->r_max = 2;
	z->r_min = -2;
	z->i_max = 2;
	z->i_min = -2;
	z->m_x = 0;
	z->m_y = 0;
	z->color = 0xeeeeee;
	z->newcolor = 0xeeeeee;
	z->interp = 1.;
	z->max_iter = 50;
}

void	init(t_mlx *z, char *str)
{
	init2(z);
	if (ft_strcmp("mandelbrot", str) == 0)
		z->id = 1;
	else if (ft_strcmp("julia", str) == 0)
		z->id = 2;
	else if (ft_strcmp("burning_ship", str) == 0)
		z->id = 3;
	else
	{
		write(1, "./fractol [mandelbrot | julia | burning_ship]\n", 46);
		free(z);
		exit(0);
	}
	z->mlx_ptr = mlx_init();
	z->win_ptr = mlx_new_window(z->mlx_ptr, WIN_W, WIN_H, "fractol");
	z->img_ptr = mlx_new_image(z->mlx_ptr, WIN_W, WIN_H);
	z->img_str = (int *)mlx_get_data_addr
		(z->img_ptr, &z->bpp, &z->l, &z->endian);
}
