/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arharif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:06:30 by arharif           #+#    #+#             */
/*   Updated: 2022/07/06 15:06:34 by arharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

int	key_press(int keycode, t_mlx *z)
{
	if (keycode == 53)
	{
		free (z);
		exit (0);
	}
	return (0);
}
