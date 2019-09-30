/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:15:20 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/08/01 16:37:50 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/controls.h"

void	move_and_alt(int key, t_mlx *mlx)
{
	if (key == KEY_Q)
		mlx->cam->z_mag -= 0.05;
	else if (key == KEY_E)
		mlx->cam->z_mag += 0.05;
	else if (key == KEY_W)
		mlx->cam->start.y -= 10;
	else if (key == KEY_A)
		mlx->cam->start.x -= 10;
	else if (key == KEY_S)
		mlx->cam->start.y += 10;
	else
		mlx->cam->start.x += 10;
	if (mlx->cam->z_mag < 0.1)
		mlx->cam->z_mag = 0.1;
	else if (mlx->cam->z_mag > 10)
		mlx->cam->z_mag = 10;
}

void	zoom(int key, t_mlx *mlx)
{
	if (key == PAD_ADD)
		mlx->cam->zoom++;
	else if (key == PAD_RES)
		mlx->cam->zoom--;
	if (mlx->cam->zoom < 1)
		mlx->cam->zoom = 1;
}

void	rotate(int key, t_mlx *mlx)
{
	if (key == PAD_NUM_2)
		mlx->cam->alpha += 0.05;
	else if (key == PAD_NUM_8)
		mlx->cam->alpha -= 0.05;
	else if (key == PAD_NUM_4)
		mlx->cam->beta += 0.05;
	else if (key == PAD_NUM_6)
		mlx->cam->beta -= 0.05;
	else if (key == PAD_NUM_3 || key == PAD_NUM_9)
		mlx->cam->gamma += 0.05;
	else if (key == PAD_NUM_1 || key == PAD_NUM_7)
		mlx->cam->gamma -= 0.05;
}

void	theme(t_mlx *mlx, t_menu *menu)
{
	if (menu->boo == 0)
		menu->boo = 1;
	if (menu->boo == 1)
		theme_light(mlx, menu);
	else if (menu->boo == 2)
		theme_dark(mlx, menu);
}

int		key_press(int key, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (key == KEY_ESC)
	{
		free_mlx(mlx, mlx->map->size);
		exit(0);
	}
	else if (key == KEY_Z)
		theme(mlx, mlx->menu);
	else if (key == KEY_SPACE)
		reset_values(mlx);
	else if (key == KEY_Q || key == KEY_W || key == KEY_E ||
			key == KEY_A || key == KEY_S || key == KEY_D)
		move_and_alt(key, mlx);
	else if (key == PAD_ADD || key == PAD_RES)
		zoom(key, mlx);
	else if (key == PAD_NUM_1 || key == PAD_NUM_2 || key == PAD_NUM_3 ||
			key == PAD_NUM_4 || key == PAD_NUM_6 ||
			key == PAD_NUM_7 || key == PAD_NUM_8 || key == PAD_NUM_9)
		rotate(key, mlx);
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	draw(mlx, mlx->map, 1);
	return (0);
}
