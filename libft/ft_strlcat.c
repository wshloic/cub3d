/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 11:27:23 by lbertran          #+#    #+#             */
/*   Updated: 2020/11/24 16:25:19 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	a;
	size_t	b;
	size_t	i;

	a = ft_strlen(dest);
	b = ft_strlen(src);
	i = a;
	if (size == 0)
		return (b);
	while (src[i - a] && i < size - 1)
	{
		dest[i] = src[i - a];
		i++;
	}
	if (size < a)
		return (b + size);
	dest[i] = '\0';
	return (a + b);
}
