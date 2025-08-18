/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:18:56 by abendrih          #+#    #+#             */
/*   Updated: 2025/07/11 20:28:23 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : ft_split
// Expected files   : ft_split.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write a function that takes a string, splits it into words, and returns them as
// a NULL-terminated array of strings.

// A "word" is defined as a part of a string delimited either by spaces/tabs/new
// lines, or by the start/end of the string.

// Your function must be declared as follows:


#include <stdio.h>

int is_space (char c)
{
    return (c <= 32);
}
int count_words(char *str)
{
    int i;
    int count;
    
    i= 0;
    count = 0;
    while (is_space(str[i]))
        i++;
    while (str[i])
    {
        while (!is_space(str[i]) && str[i])
        {
            if (is_space(str[i + 1]) || !str[i + 1])
            {
                count++;
                i++;
                break;
            }
            i++;
        }
        i++;
    }
    return (count);
}

int	is_space(char c)
{
	return (c <= 32);
}

int	count_words(char *str)
{
	int	i = 0;
	int	count = 0;
	int	in_word = 0;

	while (str[i])
	{
		if (!is_space(str[i]) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (is_space(str[i]) && in_word)
			in_word = 0;
		i++;
	}
	return (count);
}


// "   fdsfs sss ff s"

// char *alocation(char *str, int)
// {
    
// }

// char    **ft_split(char *str)
// {
    
// }
int main (int ac, char **av)
{
    if (ac != 2)
        return (0);
    printf("%d", count_words(av[1]));
    return (0);
}
