/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:49:53 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/08/01 16:16:40 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/colors.h"

void	end(char *message)
{
	ft_putendl(message);
	exit(0);
}

int		abs(int i)
{
	return (i < -1 ? -i : i);
}

int		minimum(int a, int b)
{
	return ((a < b) ? a : b);
}

void	background(t_mlx *mlx)
{
	int		*image;
	int		i;

	i = 0;
	image = (int *)mlx->data_addr;
	i = 0;
	while (i < WIDTH * HEIGHT)
	{
		if (i % WIDTH <= MENU_WIDTH || i % WIDTH > WIDTH - MENU_WIDTH)
			image[i] = mlx->menu->menu;
		else
			image[i] = mlx->menu->background;
		i++;
	}
}

void	reset_values(t_mlx *mlx)
{
	mlx->cam->zoom = get_zoom(mlx->map->size);
	mlx->cam->z_mag = 0.1;
	mlx->cam->alpha = 0;
	mlx->cam->beta = 0;
	mlx->cam->gamma = 0;
	mlx->cam->start.x = mlx->cam->iso ? 0 : WIDTH / 10;
	mlx->cam->start.y = 0;
	mlx->cam->iso = (mlx->cam->iso == 1) ? 0 : 1;
}
