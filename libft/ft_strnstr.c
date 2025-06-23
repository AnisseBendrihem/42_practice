/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:07:22 by abendrih          #+#    #+#             */
/*   Updated: 2025/05/01 21:45:50 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] && i + ft_strlen(little) <= len)
	{
		if (ft_strncmp(&big[i], little, ft_strlen(little)) == 0)
			return ((char *)(big + i));
		i++;
	}
	return (0);
}
