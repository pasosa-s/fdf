/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 18:10:15 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/07/31 14:31:58 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	rotate_x(int *y, int *z, double alpha)
{
	int		old_y;

	old_y = *y;
	*y = old_y * cos(alpha) + *z * sin(alpha);
	*z = -old_y * sin(alpha) + *z * cos(alpha);
}

void	rotate_y(int *x, int *z, double alpha)
{
	int		old_x;

	old_x = *x;
	*x = old_x * cos(alpha) - *z * sin(alpha);
	*z = old_x * sin(alpha) + *z * cos(alpha);
}

void	rotate_z(int *x, int *y, double alpha)
{
	int		old_x;
	int		old_y;

	old_x = *x;
	old_y = *y;
	*x = old_x * cos(alpha) + old_y * sin(alpha);
	*y = -old_x * sin(alpha) + old_y * cos(alpha);
}
