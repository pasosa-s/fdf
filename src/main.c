/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:41:01 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/08/01 17:30:28 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		main(int ac, char **av)
{
	t_map		*map;
	t_mlx		*mlx;
	t_cam		*cam;
	t_menu		*menu;

	if (ac != 2)
		end(ERR_USAGE);
	menu = get_menu();
	if (!(map = get_map(av[1], menu)))
		exit(0);
	cam = get_cam(map->size);
	mlx = get_mlx(av[1], map, cam, menu);
	mlx->tab = create_tab(mlx);
	draw(mlx, mlx->map, 0);
	mlx_hook(mlx->win_ptr, 2, 0, key_press, mlx);
	mlx_hook(mlx->win_ptr, 4, 0, mouse_press, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
