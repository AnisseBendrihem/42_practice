/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:33:34 by abendrih          #+#    #+#             */
/*   Updated: 2025/06/27 15:44:43 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// // Assignment name  : first_word
// // Expected files   : first_word.c
// // Allowed functions: write
//
// --------------------------------------------------------------------------------

// // Write a program that takes a string and displays its first word,
// followed by a
// 	// newline.

// 	// A word is a section of string delimited by spaces/tabs or by the start/end of
// 	// the string.

// 	// If the number of parameters is not 1, or if there are no words,
// 	simply display
// 		// a newline.

// 		// Examples:

// 		// $> ./first_word "FOR PONY" | cat -e
// 		// FOR$
// 		// $> ./first_word "this        ...       is sparta, then again,
// 		maybe not " | cat -e
// 	// this$
// 	// $> ./first_word "   " | cat -e
// 	// $
// 	// $> ./first_word "a" "b" | cat -e
// 	// $
// 	// $> ./first_word "  lorem,ipsum  " | cat -e
// 	// lorem,ipsum$
// 	// $>

#include <unistd.h>

int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		write(1, "\n", 1);
	else
	{
		int i;

		i = 0;
		while (is_space(av[1][i]))
		{
			i++;
		}
		while (av[1][i])
		{
			if (is_space(av[1][i]))
				break ;
			write(1, &av[1][i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
}