/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:13:54 by abendrih          #+#    #+#             */
/*   Updated: 2025/07/09 21:25:17 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : rev_wstr
// Expected files   : rev_wstr.c
// Allowed functions: write, malloc, free
// --------------------------------------------------------------------------------

// Write a program that takes a string as a parameter, and prints its words in
// reverse order.

// A "word" is a part of the string bounded by spaces and/or tabs, or the
// begin/end of the string.

// If the number of parameters is different from 1, the program will display
// '\n'.

// In the parameters that are going to be tested,
// there won't be any "additional"
// spaces (meaning that there won't be additionnal spaces at the beginning or at
// the end of the string,
// and words will always be separated by exactly one space).

// Examples:

// $> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat
// ironic? it Isn't gatherings. love I But people! hate You$
// $>./rev_wstr "abcdefghijklm"
// abcdefghijklm
// $> ./rev_wstr "Wingardium Leviosa" | cat -e
// Leviosa Wingardium$
// $> ./rev_wstr | cat -e
// $
// $>

#include <unistd.h>

int	count_words(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == 32 || str[i + 1] == '\0')
		{
			count++;
		}
		i++;
	}
	return (count);
}

void	rev(char *str, int *i)
{
	int	j;

	j = 0;
	while (str[*i] != 32 && *i >= 0)
		(*i)--;
	j = *i + 1;
	(*i)--;
	while (str[j] != 32 && str[j])
	{
		write(1, &str[j], 1);
		j++;
	}
	if (*i > 0)
		write(1, " ", 1);
}

int	main(int ac, char **av)
{
	int	i;
	int	words;

	i = 0;
	if (ac == 2)
	{
		words = count_words(av[1]);
		while (av[1][i])
			i++;
		while (words)
		{
			rev(av[1], &i);
			words--;
		}
	}
	return (write(1, "\n", 1), 0);
}
