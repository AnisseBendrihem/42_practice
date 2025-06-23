/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:44:58 by abendrih          #+#    #+#             */
/*   Updated: 2025/05/01 17:10:48 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cs;
	unsigned char	cc;

	cc = (unsigned char)c;
	cs = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (cs[i] == cc)
			return (cs + i);
		i++;
	}
	return (0);
}
