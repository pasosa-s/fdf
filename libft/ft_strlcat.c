/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:08:54 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/04/10 15:16:21 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		dlen;
	size_t		slen;
	size_t		i;
	int			j;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	i = 0;
	j = 0;
	if (size <= dlen)
		return (slen + size);
	while (dst[i] && i < (size - 1))
		i++;
	while (src[j] && i < (size - 1))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = 0;
	return (dlen + slen);
}
