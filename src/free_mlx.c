/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 15:28:21 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/09/09 15:25:49 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	free_lst(t_lst *alst)
{
	t_lst		*ptr;

	while (alst)
	{
		ptr = alst->next;
		free(alst);
		alst = ptr;
	}
}

void	free_mlx(t_mlx *mlx, t_coord size)
{
	int		i;

	i = 0;
	free(mlx->cam);
	free(mlx->menu);
	free_lst(mlx->map->lst);
	free(mlx->map);
	while (i < size.y)
	{
		free(mlx->tab[i]);
		i++;
	}
	free(mlx->tab);
	free(mlx);
}
