/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baron_kakka <baron_kakka@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:00:43 by baron_kakka       #+#    #+#             */
/*   Updated: 2025/10/13 17:53:35 by baron_kakka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char *ft_strdup(char *src)
{
    char *dest;
    int i = 0;

    while (src[i])
        i++;
    dest = malloc (sizeof(char) * (i + 1));
    if (!dest)
        return(NULL);
    i = 0;
    while (src[i++])
        dest[i -1 ] = src[i -1];
    dest[i - 1] = '\0';
    return(dest);
}

char *gnl(int fd)
{
    char line[10000];
    static char buffer[BUFFER_SIZE];
    static int readed = 0;
    static int j = 0;
    int i = 0;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while (1)
    {
        if(j >= readed)
        {
            readed = read(fd, buffer, BUFFER_SIZE);
            j = 0;
            if (readed == 0)
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

int main()
{
    int fd;
    char *line;

    fd = open("subject.txt", O_RDONLY);
    line = gnl(fd);
    while(line)
    {
        printf("%s", line);
        free(line);
        line = gnl(fd);
    }
    close (fd);
    return(0);
}
