/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 22:30:37 by abendrih          #+#    #+#             */
/*   Updated: 2025/04/30 23:22:36 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	originlendst;

	originlendst = ft_strlen(dst);
	i = 0;
	if (dstsize <= originlendst)
		return (dstsize + ft_strlen(src));
	while (src[i] && originlendst + i < dstsize - 1)
	{
		dst[originlendst + i] = src[i];
		i++;
	}
	dst[originlendst + i] = '\0';
	return (originlendst + ft_strlen(src));
}
