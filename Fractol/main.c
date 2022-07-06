/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arharif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:05:30 by arharif           #+#    #+#             */
/*   Updated: 2022/07/06 15:05:43 by arharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_mlx	*z;

	if (ac != 2 || !av[1][0])
	{
		write(1, "./fractol [mandelbrot | julia]\n", 31);
		exit (0);
	}
	z = (t_mlx *) malloc(sizeof(t_mlx));
	if (!z)
		return (1);
	init(z, av[1]);
	if (z->id == 1)
		mandelbrot (z);
	else if (z->id == 2)
		julia (z);
	mlx_put_image_to_window(z->mlx_ptr, z->win_ptr, z->img_ptr, 0, 0);
	mlx_hook (z->win_ptr, 17, 0, ft_close, z);
	mlx_hook (z->win_ptr, 2, 0, key_press, z);
	mlx_hook (z->win_ptr, 4, 0, mouse_press, z);
	mlx_hook (z->win_ptr, 6, 0, mouse_move, z);
	mlx_loop (z->mlx_ptr);
}
