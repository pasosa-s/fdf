/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:58:05 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/04/12 18:08:47 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;

	i = 0;
	if (needle[i] == 0)
		return ((char *)haystack);
	while (i < (int)len && haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (needle[j + 1] == 0 && i + j < (int)len)
				return ((char *)haystack + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
