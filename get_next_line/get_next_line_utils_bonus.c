/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:42:28 by abendrih          #+#    #+#             */
/*   Updated: 2025/06/13 20:01:06 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strndup(char *src, size_t n)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	dest = malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (NULL);
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	fullen;
	size_t	lens1;
	size_t	i;
	char	*s3;

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
	free(s1);
	s3[fullen] = '\0';
	return (s3);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (c == s[i])
			return (&s[i]);
		i++;
	}
	if (c == '\0')
		return (&s[i]);
	return (0);
}

int	lenof_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}
