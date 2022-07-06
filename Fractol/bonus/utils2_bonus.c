/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arharif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:08:38 by arharif           #+#    #+#             */
/*   Updated: 2022/07/06 15:08:42 by arharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_close(t_mlx *z)
{
	free (z);
	exit (0);
	return (0);
}

void	ft_clear_img(int *img_str)
{
	int	i;

	i = 0;
	while (i < WIN_H * WIN_W)
		img_str[i++] = 0x000000;
}

void	key_press2(int keycode, t_mlx *z)
{
	if (keycode == 123)
		z->t_x = z->t_x + 20;
	else if (keycode == 124)
		z->t_x = z->t_x - 20;
	else if (keycode == 125)
		z->t_y = z->t_y - 20;
	else if (keycode == 126)
		z->t_y = z->t_y + 20;
	else if (keycode == 18)
		z->newcolor = MY_COLOR2;
	else if (keycode == 19)
		z->newcolor = MY_COLOR3;
	else if (keycode == 20)
		z->newcolor = MY_COLOR4;
}

int	key_press(int keycode, t_mlx *z)
{
	if (keycode == 53)
	{
		free (z);
		exit (0);
	}
	else if (keycode == 69)
		z->max_iter += 5;
	else if (keycode == 78)
		z->max_iter -= 5;
	else
		key_press2(keycode, z);
	ft_clear_img(z->img_str);
	if (z->id == 1)
		mandelbrot (z);
	else if (z->id == 2)
		julia (z);
	else if (z->id == 3)
		burning_ship (z);
	mlx_put_image_to_window(z->mlx_ptr, z->win_ptr, z->img_ptr, 0, 0);
	return (0);
}
