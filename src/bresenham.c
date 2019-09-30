/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 13:04:01 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/08/01 16:15:01 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/colors.h"

void		put_pixel(t_mlx *mlx, int x, int y, int color)
{
	int		i;

	if ((x >= MENU_WIDTH && x <= WIDTH - MENU_WIDTH) && (y >= 0 && y <=
				HEIGHT))
	{
		i = ((x * (mlx->bpp / 8)) + (y * mlx->s_l));
		mlx->data_addr[i] = color;
		mlx->data_addr[++i] = color >> 8;
		mlx->data_addr[++i] = color >> 16;
	}
}

int			set_values(t_coord *delta, t_coord *a, t_coord *b)
{
	int		boo;

	boo = 0;
	(*delta).y = (*b).y - (*a).y;
	(*delta).x = (*b).x - (*a).x;
	if (abs((*delta).y) > abs((*delta).x))
	{
		ft_swap(&delta->y, &delta->x);
		boo = 1;
	}
	return (boo);
}

void		set_div(t_coord *delta, t_coord *val, double *div)
{
	(*val).x = 0;
	(*val).y = ((*delta).x < 0) ? -1 : 1;
	*div = ((*delta).y == 0) ? (*delta).x :
		(double)(*delta).x / (double)(*delta).y;
}

t_coord		to_c(int x, int y)
{
	t_coord		coord;

	coord.x = x;
	coord.y = y;
	return (coord);
}

void		bresenham(t_mlx *mlx, t_tab a, t_tab b)
{
	t_coord		delta;
	t_coord		val;
	int			boo;
	double		div;

	boo = set_values(&delta, &a.coord, &b.coord);
	set_div(&delta, &val, &div);
	while (val.x != delta.x)
	{
		if (boo)
		{
			put_pixel(mlx, a.coord.x + (int)((double)val.x / div),
			a.coord.y + val.x, gradient(to_c(a.coord.x +
			(int)((double)val.x / div), a.coord.y + val.x), a, b, delta));
			val.x += val.y;
		}
		else
		{
			put_pixel(mlx, a.coord.x + val.x, a.coord.y +
			(int)((double)val.x / div), gradient(to_c(a.coord.x + val.x,
			(int)((double)val.x / div)), a, b, delta));
			val.x += val.y;
		}
	}
}
