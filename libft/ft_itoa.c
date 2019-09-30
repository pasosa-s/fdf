/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:39:28 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/05/21 09:40:47 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_len(int n, unsigned int *nb)
{
	int		len;
	int		sign;

	len = 0;
	sign = 0;
	if (n < 0)
	{
		*nb = -n;
		sign = 1;
	}
	else
		*nb = n;
	while (n /= 10)
		len++;
	if (sign)
		len++;
	return (len);
}

char			*ft_itoa(int n)
{
	int				len;
	char			*str;
	unsigned int	nb;

	len = get_len(n, &nb);
	str = ft_strnew((size_t)len + 1);
	if (!str)
		return (NULL);
	str[len] = nb % 10 + 48;
	nb /= 10;
	len--;
	while (nb)
	{
		str[len] = nb % 10 + 48;
		nb /= 10;
		len--;
	}
	if (n < 0)
		str[len] = '-';
	return (str);
}
