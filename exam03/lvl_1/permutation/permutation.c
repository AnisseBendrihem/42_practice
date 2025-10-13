/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baron_kakka <baron_kakka@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:48:13 by abendrih          #+#    #+#             */
/*   Updated: 2025/10/13 17:53:25 by baron_kakka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

void ft_swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void ft_sort(char *str)
{
    for(int i = 0; str[i]; i++)
        for(int j = 0; str[j]; j++)
            if (str[j] > str[i])
                ft_swap(&str[i], &str[j]);
}

int permute(char *str, int len)
{
    int i = len -2;
    int j = len -1;
    int r = len -1;
    int l;

    while (i >= 0 && str[i] >= str[i + 1])
        i--;
    if (i < 0)
        return (0);
    while (str[j] <= str[i])
        j--;
    ft_swap(&str[i], &str[j]);
    l = i +1;
    while (l < r)
        ft_swap(&str[l++], &str[r--]);
    return (1);
}

int main (int ac, char **av)
{
    if (ac != 2)
        return (1);
    ft_sort(av[1]);
    puts(av[1]);
    while (permute(av[1], ft_strlen(av[1])))
        puts(av[1]);
    return (0);
}
