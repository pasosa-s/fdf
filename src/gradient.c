/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:22:09 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/08/09 13:46:47 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

double		percent(int start, int end, int cur)
{
	double placement;
	double distance;

	placement = cur - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int			color_mix(int start, int end, double per)
{
	return ((int)((1 - per) * start + per * end));
}

int			gradient(t_coord cur, t_tab start, t_tab end, t_coord delta)
{
	int		red;
	int		green;
	int		blue;
	double	per;

	if (start.zac.y == end.zac.y)
		return (start.zac.y);
	if (delta.x > delta.y)
		per = percent(start.coord.x, end.coord.x, cur.x);
	else
		per = percent(start.coord.y, end.coord.y, cur.y);
	red = color_mix((start.zac.y >> 16) & 0xFF, (end.zac.y >> 16) & 0xFF, per);
	green = color_mix((start.zac.y >> 8) & 0xFF, (end.zac.y >> 8) & 0xFF, per);
	blue = color_mix((start.zac.y) & 0xFF, (end.zac.y) & 0xFF, per);
	return ((red << 16) | (green << 8) | (blue));
}
