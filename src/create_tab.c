/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:55:33 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/08/01 14:47:34 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void		isometric(t_coord *coord, int z)
{
	int		x;
	int		y;

	x = (*coord).x;
	y = (*coord).y;
	(*coord).x = (x - y) * cos(0.523599);
	(*coord).y = (x + y) * sin(0.523599) - z;
}

t_tab		get_mag_and_color(t_mlx *mlx, int x, int y, t_coord size)
{
	int			i;
	t_lst		*ptr;
	t_tab		string;

	i = 1;
	ptr = mlx->map->lst;
	while (i < (((size.y - y) * size.x) - x) && ptr)
	{
		ptr = ptr->next;
		i++;
	}
	string.coord.x = mlx->cam->zoom * x;
	string.coord.y = mlx->cam->zoom * y;
	string.zac.x = ptr->z;
	string.zac.y = ptr->color;
	if (mlx->cam->iso)
		isometric(&string.coord,
				string.zac.x * ((mlx->cam->zoom) * mlx->cam->z_mag));
	string.coord.x += mlx->cam->center.x + mlx->cam->start.x;
	string.coord.y += mlx->cam->center.y;
	return (string);
}

t_tab		*create_string(t_mlx *mlx, int y, t_coord size)
{
	t_tab		*string;
	int			x;

	x = 0;
	string = (t_tab *)malloc(sizeof(t_tab) * size.x);
	while (x < size.x)
	{
		string[x] = get_mag_and_color(mlx, x, y, size);
		x++;
	}
	return (string);
}

t_tab		**create_tab(t_mlx *mlx)
{
	t_tab		**tab;
	int			y;

	y = 0;
	tab = (t_tab **)malloc(sizeof(t_tab) * mlx->map->size.y);
	while (y < mlx->map->size.y)
	{
		tab[y] = create_string(mlx, y, mlx->map->size);
		y++;
	}
	return (tab);
}
