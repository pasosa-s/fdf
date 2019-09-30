/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 16:20:04 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/08/01 17:01:59 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/colors.h"

t_map		*get_map(char *av, t_menu *menu)
{
	t_map		*map;
	t_lst		*lst;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		end(ERR_MALLOC);
	map->size.x = 0;
	map->size.y = 0;
	map->lst = NULL;
	if (!open_file(av, &(map)->size, map, menu))
		return (NULL);
	return (map);
}

int			get_zoom(t_coord size)
{
	return (minimum(WIDTH / size.x / 2, HEIGHT / size.y / 2));
}

t_cam		*get_cam(t_coord size)
{
	t_cam	*camera;

	if (!(camera = (t_cam *)malloc(sizeof(t_cam))))
		end(ERR_MALLOC);
	camera->zoom = get_zoom(size);
	camera->iso = 1;
	camera->start.x = WIDTH / 10;
	camera->start.y = 0;
	camera->center.x = WIDTH / 2 - (camera->zoom * size.x) / 2;
	camera->center.y = HEIGHT / 2 - (camera->zoom * size.y) / 2;
	camera->z_mag = 0.1;
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	return (camera);
}

t_menu		*get_menu(void)
{
	t_menu		*menu;

	if (!(menu = (t_menu *)malloc(sizeof(t_menu))))
		end(ERR_MALLOC);
	menu->background = AUTUM_BLUE;
	menu->menu = DARK_BLUE;
	menu->color1 = ACQUA;
	menu->color2 = TAMARINDO;
	menu->color3 = PASION;
	menu->color4 = BOCA90;
	menu->color5 = BOB;
	menu->text1 = MARBLE;
	menu->text2 = GRIS;
	menu->boo = 0;
	return (menu);
}

t_mlx		*get_mlx(char *av, t_map *m, t_cam *camera, t_menu *menu)
{
	t_mlx		*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		end(ERR_MALLOC);
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, av);
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	mlx->map = m;
	mlx->cam = camera;
	mlx->menu = menu;
	mlx->bpp = 32;
	mlx->s_l = WIDTH * 4;
	mlx->endian = 0;
	mlx->data_addr = mlx_get_data_addr(mlx->img_ptr,
			&(mlx->bpp), &(mlx->s_l), &(mlx->endian));
	ft_bzero(mlx->data_addr, WIDTH * HEIGHT * 4);
	mlx->tab = NULL;
	return (mlx);
}
