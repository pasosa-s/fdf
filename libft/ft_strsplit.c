/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:09:18 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/07/23 18:18:05 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			c_words(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (s[i + 1] == c || s[i + 1] == 0)
				count++;
			i++;
		}
		else
			i++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**a;

	i = 0;
	j = 0;
	k = 0;
	if (!s || !(a = (char **)malloc(sizeof(char *) * c_words(s, c) + 1)))
		return (NULL);
	while (k < c_words(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		j = i;
		while (s[i] != c && s[i])
			i++;
		a[k] = ft_strsub(s, j, i - j);
		k++;
	}
	a[k] = 0;
	return (a);
}
