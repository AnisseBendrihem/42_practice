/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:32:17 by abendrih          #+#    #+#             */
/*   Updated: 2025/10/07 17:39:11 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

char *ft_strdup(char *src)
{
	int i = 0;
	char *dest;
	
	while (src[i])
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	} 
	dest[i] = '\0';
	return(dest);
}

char *get_next_line(int fd)
{
	static int j = 0;
	static int readed = 0;
	static char buffer[BUFFER_SIZE];
	char line [10000];
	int i = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (j >= readed)
		{
			readed = read(fd, buffer, BUFFER_SIZE);
			j = 0;
			if(readed == 0)
				break;
		}
		line[i++] = buffer[j++];
		if (line[i - 1] == '\n')
			break;
	}
	if (i == 0)
		return (NULL);
	line[i] = '\0';
	return(ft_strdup(line));
}
