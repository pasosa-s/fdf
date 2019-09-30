/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:00:21 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/08/01 17:32:18 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		message(char *message, t_menu *menu, t_map *map)
{
	if (!(ft_strcmp(message, "empty")))
		ft_putstr("No data found.\n");
	else if (!(ft_strcmp(message, "dir")))
		ft_putstr("Input is a directory.\n");
	else
	{
		ft_putstr("No file ");
		ft_putendl(message);
	}
	free(menu);
	free_lst(map->lst);
	free(map);
	return (0);
}

int		open_file(char *av, t_coord *size, t_map *map, t_menu *menu)
{
	char	**line_s;
	char	*line;
	int		fd;
	int		ret;

	ret = 0;
	if ((fd = open(av, O_DIRECTORY)) != -1)
		return (message("dir", menu, map));
	if (!((fd = open(av, O_RDONLY)) >= 0))
		return (message(av, menu, map));
	while ((ret = get_next_line(fd, &line)))
	{
		if (!(line_s = ft_strsplit(line, ' ')))
			end(ERR_MALLOC);
		split_to_list(map, line_s, size, menu);
		(*size).y++;
		free(line);
		free(line_s);
	}
	close(fd);
	if (ret == -1 || (*size).x == 0 || (*size).y == 0)
		return (message("empty", menu, map));
	return (1);
}
