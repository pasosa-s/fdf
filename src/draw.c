/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   with_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 19:01:37 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/08/01 14:45:20 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void		change_color(t_tab *tab, t_menu *menu)
{
	if (!tab->zac.x)
		tab->zac.y = menu->color1;
	else if (tab->zac.x && tab->zac.x <= 5)
		tab->zac.y = menu->color2;
	else if (tab->zac.x > 5 && tab->zac.x <= 8)
		tab->zac.y = menu->color3;
	else if (tab->zac.x > 30)
		tab->zac.y = menu->color5;
	else
		tab->zac.y = menu->color4;
}

void		control_moves(t_mlx *mlx, t_tab *tab, int x, int y)
{
	int		z;

	tab->coord.x = mlx->cam->zoom * x;
	tab->coord.y = mlx->cam->zoom * y;
	if (mlx->menu->boo)
		change_color(tab, mlx->menu);
	z = tab->zac.x * (mlx->cam->zoom * mlx->cam->z_mag);
	if (mlx->cam->iso)
		isometric(&tab->coord, z);
	rotate_x(&tab->coord.y, &z, mlx->cam->alpha);
	rotate_y(&tab->coord.x, &z, mlx->cam->beta);
	rotate_z(&tab->coord.x, &tab->coord.y, mlx->cam->gamma);
	tab->coord.x += mlx->cam->center.x;
	tab->coord.y += mlx->cam->center.y;
	tab->coord.x += mlx->cam->start.x;
	tab->coord.y += mlx->cam->start.y;
}

t_tab		get_coord(int x, int y, t_mlx *mlx, int index)
{
	if (index)
		control_moves(mlx, &mlx->tab[y][x], x, y);
	return (mlx->tab[y][x]);
}

void		draw(t_mlx *mlx, t_map *map, int index)
{
	int		x;
	int		y;

	y = 0;
	background(mlx);
	while (y < map->size.y)
	{
		x = 0;
		while (x < map->size.x)
		{
			if (x < map->size.x - 1)
				bresenham(mlx, get_coord(x, y, mlx, index),
						get_coord(x + 1, y, mlx, index));
			if (y < map->size.y - 1)
				bresenham(mlx, get_coord(x, y, mlx, index),
						get_coord(x, y + 1, mlx, index));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	text_menu_left(mlx);
}
