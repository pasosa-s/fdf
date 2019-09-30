/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_to_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:24:44 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/08/01 17:32:20 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/colors.h"

void		ft_lst_add(t_lst **alst, t_lst *new)
{
	new->next = *alst;
	*alst = new;
}

t_lst		*new_coord(char *str, t_menu *menu)
{
	t_lst		*new;

	if (!(new = (t_lst *)malloc(sizeof(t_lst))))
		end(ERR_MALLOC);
	new->z = ft_atoi(str);
	if (new->z && new->z > 100)
		new->z = 100;
	if (!new->z)
		new->color = menu->color1;
	else if (new->z && new->z <= 5)
		new->color = menu->color2;
	else if (new->z > 5 && new->z <= 8)
		new->color = menu->color3;
	else if (new->z > 30)
		new->color = menu->color5;
	else
		new->color = menu->color4;
	new->next = NULL;
	free(str);
	return (new);
}

void		split_to_list(t_map *map, char **line_s, t_coord *size,
		t_menu *menu)
{
	int		i;

	i = 0;
	while (line_s[i])
	{
		ft_lst_add(&map->lst, new_coord(line_s[i], menu));
		i++;
	}
	if ((*size).x == 0)
		(*size).x = i;
	else if ((*size).x != i)
	{
		free(menu);
		free_lst(map->lst);
		free(map);
		end(ERR_LENGTH);
	}
}
