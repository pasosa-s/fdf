/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 20:15:02 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/08/22 17:20:32 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/controls.h"
#include "../inc/colors.h"

int		mouse_press(int button, int x, int y, void *param)
{
	t_mlx		*mlx;

	mlx = (t_mlx *)param;
	if (button == MOUSE_SCROLL_UP)
		mlx->cam->zoom++;
	else if (button == MOUSE_SCROLL_DOWN)
		mlx->cam->zoom--;
	if (mlx->cam->zoom < 1)
		mlx->cam->zoom = 1;
	draw(mlx, mlx->map, 3);
	return (0);
}

void	theme_dark(t_mlx *mlx, t_menu *menu)
{
	menu->background = AUTUM_BLUE;
	menu->menu = DARK_BLUE;
	menu->color1 = ACQUA;
	menu->color2 = TAMARINDO;
	menu->color3 = PASION;
	menu->color4 = BOCA90;
	menu->color5 = BOB;
	menu->text1 = MARBLE;
	menu->text2 = GRIS;
	menu->boo = 1;
}

void	theme_light(t_mlx *mlx, t_menu *menu)
{
	menu->background = PASTEL1;
	menu->menu = PASTEL2;
	menu->color1 = GGREEN;
	menu->color2 = TUR5;
	menu->color3 = PASION2;
	menu->color4 = PASION3;
	menu->color5 = PURPLE5;
	menu->text1 = BLUE2;
	menu->text2 = BLUE2;
	menu->boo = 2;
}

void	text_menu_right(t_mlx *big_mlx)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	t_coord	color;

	mlx = big_mlx->mlx_ptr;
	win = big_mlx->win_ptr;
	color.x = big_mlx->menu->text1;
	color.y = big_mlx->menu->text2;
	x = WIDTH - MENU_WIDTH;
	y = 200;
	mlx_string_put(mlx, win, x += 10, y, color.x, "[ 7 ] [ 8 ] [ 9 ]");
	mlx_string_put(mlx, win, x, y += 30, color.x, "[ 4 ] [ 5 ] [ 6 ]");
	mlx_string_put(mlx, win, x, y += 30, color.x, "[ 1 ] [ 2 ] [ 3 ]");
	mlx_string_put(mlx, win, x, y += 100, color.y, "2 = rotation x++");
	mlx_string_put(mlx, win, x, y += 20, color.y, "8 = rotation x--;");
	mlx_string_put(mlx, win, x, y += 50, color.y, "4 = rotation y++");
	mlx_string_put(mlx, win, x, y += 20, color.y, "6 = rotation y--");
	mlx_string_put(mlx, win, x, y += 50, color.y, "3/9 = rotation z++");
	mlx_string_put(mlx, win, x, y += 20, color.y, "1/7 = rotation z--;");
	mlx_string_put(mlx, win, x, y += 200, color.x, "[ - ] [ MOUSE --]");
	mlx_string_put(mlx, win, x += 50, y += 30, color.y, "zoom out");
	mlx_string_put(mlx, win, x -= 50, y += 50, color.y, "[ + ] [ MOUSE ++]");
	mlx_string_put(mlx, win, x += 50, y += 30, color.y, "zoom in");
}

void	text_menu_left(t_mlx *big_mlx)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	t_coord	color;

	mlx = big_mlx->mlx_ptr;
	win = big_mlx->win_ptr;
	color.x = big_mlx->menu->text1;
	color.y = big_mlx->menu->text2;
	x = 10;
	y = 200;
	mlx_string_put(mlx, win, x, y, color.x, "[ Q ] [ W ] [ E ]");
	mlx_string_put(mlx, win, x, y += 20, color.x, "[ A ] [ S ] [ D ]");
	mlx_string_put(mlx, win, x, y += 100, color.y, "[ Q ] = z alt--");
	mlx_string_put(mlx, win, x, y += 20, color.y, "[ E ] = z alt++");
	mlx_string_put(mlx, win, x, y += 50, color.y, "[ W ] = up");
	mlx_string_put(mlx, win, x, y += 20, color.y, "[ A ] = left");
	mlx_string_put(mlx, win, x, y += 20, color.y, "[ S ] = down");
	mlx_string_put(mlx, win, x, y += 20, color.y, "[ D ] = right");
	mlx_string_put(mlx, win, x += 10, y += 200, color.x, "[  SPACEBAR  ]");
	mlx_string_put(mlx, win, x -= 15, y += 30, color.y, " switch projection");
	mlx_string_put(mlx, win, x += 50, y += 200, color.x, "[ Z ]");
	mlx_string_put(mlx, win, x -= 50, y += 30, color.y, " theme dark/light");
	text_menu_right(big_mlx);
}
