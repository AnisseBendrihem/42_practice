/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 22:03:13 by abendrih          #+#    #+#             */
/*   Updated: 2025/05/05 00:26:29 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t		fullen;
	size_t		lens1;
	size_t		i;
	char		*s3;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	fullen = lens1 + ft_strlen(s2);
	s3 = malloc(sizeof(char) * (fullen + 1));
	if (!s3)
		return (NULL);
	while (i < fullen)
	{
		if (i < lens1)
			s3[i] = s1[i];
		else
			s3[i] = s2[i - lens1];
		i++;
	}
	s3[fullen] = '\0';
	return (s3);
}
