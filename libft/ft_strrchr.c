/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:34:13 by abendrih          #+#    #+#             */
/*   Updated: 2025/05/01 14:54:45 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*cs;
	char	cc;
	int		i;

	cc = (char) c;
	cs = (char *) s;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (cc == cs[i])
		{
			return (cs + i);
		}
		i--;
	}
	return (0);
}
