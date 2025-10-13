/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baron_kakka <baron_kakka@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:51:11 by baron_kakka       #+#    #+#             */
/*   Updated: 2025/10/13 17:53:32 by baron_kakka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int    ft_strcmp(char *str, char *censore)
{
    int    i = 0;

    while (censore[i])
    {
        if (!str[i])
            return (0);
        if (censore[i] == str[i])
            i++;
        else
            return (0);
    }
    return (1);
}

void    filter(char *str, char *censore)
{
    int    len = strlen(censore);
    int    i = 0;
    int    j;

    while (str[i])
    {
        if (ft_strcmp(&str[i], censore))
        {
            j = 0;
            while (j < len)
            {
                write(1, "*", 1);
                i++;
                j++;
            }
        }
        else
        {
            write(1, &str[i], 1);
            i++;
        }
    }
}

int    main(int ac, char **av)
{
    char        in[10000];
    int         readed;
    int         i = 0;    
    char        c;

    if (ac != 2 || !av[1][0])
        return (1);
    readed = read(0, &c, 1);
    while (readed)
    {
        in[i] = c;
        readed = read(0, &c, 1);
        i++;
    }
    if (readed == -1)
        return (perror("Error"), 0);
    in[i] = '\0';
    filter(in, av[1]);
    return (0);
}
