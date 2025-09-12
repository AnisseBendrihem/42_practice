/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:27:10 by abendrih          #+#    #+#             */
/*   Updated: 2025/06/23 01:17:48 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : rev_print
// Expected files   : rev_print.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a string, and displays the string in reverse
// followed by a newline.

// If the number of parameters is not 1, the program displays a newline.

// Examples:

// $> ./rev_print "zaz" | cat -e
// zaz$
// $> ./rev_print "dub0 a POIL" | cat -e
// LIOP a 0bud$
// $> ./rev_print | cat -e
// $

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return i;
}

#include <unistd.h>
int main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	int i = ft_strlen(av[1]) - 1;
	while (i >= 0)
	{
		write (1, &av[1][i], 1);
		i--;
	}
	write (1, "\n", 1);
	return (0);
}
