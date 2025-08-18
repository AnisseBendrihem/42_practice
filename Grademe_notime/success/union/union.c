/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 16:01:48 by abendrih          #+#    #+#             */
/*   Updated: 2025/06/20 18:43:25 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *str) 
{
	int i=0;
	while(str[i])
		i++;
	return (i);
}

char *ft_strconcat(char *s1, char *s2, char *s3)
{
    int i = 0;
    int j = 0;

    while (s1[i])
    {
        s3[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        s3[i] = s2[j];
        i++;
        j++;
    }
    s3[i] = '\0';
    return (s3);
}
void ft_print(char *str)
{
	int i = 0;
	char recip[256];

	while(str[i])
	{
		if (str[i] == recip[(int)str[i]])
			i++;
		else
		{
			recip[(int)str[i]] = str[i];
			write(1, &str[i], 1);
			i++;
		}
	}
}

int main(int ac, char *av[])
{
	if (ac != 3)
		write (1, "\n", 1);
	else
	{
		char tmp[256];
		ft_strconcat(av[1], av[2], tmp);
		ft_print(tmp);
		write(1, "\n", 1);
	}
	return (0);
}
