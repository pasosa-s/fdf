/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 19:54:41 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/04/15 21:32:53 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_space(char c)
{
	return ((c == ' ' || c == '\n' || c == '\t') ? 1 : 0);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	k = 0;
	while (is_space(s[i]))
		i++;
	while (is_space(s[j]))
		j--;
	if (j < i)
		j = i;
	if (!(str = ft_strsub(s, i, j - i + 1)))
		return (NULL);
	return (str);
}
