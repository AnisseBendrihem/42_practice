/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 00:26:52 by abendrih          #+#    #+#             */
/*   Updated: 2025/05/01 14:30:51 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*cs;
	char	cc;

	cc = (char) c;
	cs = (char *) s;
	while (*cs)
	{
		if (cc == *cs)
		{
			return (cs);
		}
		cs++;
	}
	if (cc == '\0')
		return (cs);
	return (0);
}
