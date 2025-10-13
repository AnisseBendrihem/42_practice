/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baron_kakka <baron_kakka@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:46:16 by abendrih          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/10/08 01:11:18 by abendrih         ###   ########.fr       */
=======
/*   Updated: 2025/10/13 17:30:07 by baron_kakka      ###   ########.fr       */
>>>>>>> f4f07f5 (progress(exam03): mastered all exercises except nqueen and rip)
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

<<<<<<< HEAD
int	ft_strcmp(char *src, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!src[i])
			return (0);
		if (src[i] == str[i])
			i++;
		else
			return (0);
	}
	return (1);
}

void	filter(char *src, char *censored)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = strlen(censored);
	while (src[i])
	{
		if (ft_strcmp(&src[i], censored))
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
			write(1, &src[i], 1);
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	char	str[100000];
	char	c;
	int		readed;
	int		i;

	i = 0;
	if (ac != 2 || !av[1][0])
		return (1);
	readed = read(0, &c, 1);
	while (readed > 0)
	{
		str[i] = c;
		readed = read(0, &c, 1);
		i++;
	}
	if (readed == -1)
		return (perror("Error"), 1);
	str[i] = '\0';
	filter(str, av[1]);
	return (0);
}
=======
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
>>>>>>> f4f07f5 (progress(exam03): mastered all exercises except nqueen and rip)
