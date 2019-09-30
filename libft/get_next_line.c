/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:44:47 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/05/02 18:49:28 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_putinchar(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static int		new_line(char **rst, char **line, int ret)
{
	char	*tmp;
	int		i;

	i = ft_putinchar(*rst, '\n');
	if (i >= 0)
	{
		*line = ft_strsub(*rst, 0, i);
		tmp = ft_strdup(*rst + i + 1);
		free(*rst);
		*rst = tmp;
		return (1);
	}
	else if (ret == 0 && *rst)
	{
		*line = ft_strdup(*rst);
		ft_strdel(rst);
		return (1);
	}
	return (0);
}

static int		end_read(char **rst, char **line, int ret)
{
	if (ret < 0)
		return (-1);
	else if (*rst == NULL || ft_strlen(*rst) == 0)
	{
		ft_strdel(rst);
		return (0);
	}
	else
		return (new_line(rst, line, ret));
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static char		*rst[CHAR_SIZE];
	char			*tmp;
	int				ret;

	if (fd < 0 || !line)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = 0;
		if (!(rst[fd]))
			rst[fd] = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(rst[fd], buf);
			free(rst[fd]);
			rst[fd] = tmp;
		}
		if (new_line(&(rst[fd]), line, ret))
			return (1);
	}
	return (end_read(&(rst[fd]), line, ret));
}
