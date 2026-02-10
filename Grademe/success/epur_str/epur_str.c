/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:55:37 by abendrih          #+#    #+#             */
/*   Updated: 2025/06/25 20:31:51 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// // Assignment name  : epur_str
// // Expected files   : epur_str.c
// // Allowed functions: write
//
// --------------------------------------------------------------------------------

// // // Write a program that takes a string,
// // 	and displays this string with exactly one
// // // space between words,
// // 	with no spaces or tabs either at the beginning or the end,
// // // followed by a \n.

// //
// A "word" is defined as a part of a string delimited either by spaces/tabs,
// or
// 	// // by the start/end of the string.

// 	// // If the number of arguments is not 1,
// 	or if there are no words to display,
// 	the
// 	// // program displays \n.

// 	// // Example:
// 	// // $> ./epur_str "See? It's easy to print the same thing" | cat -e
// 	// // See? It's easy to print the same thing$
// 	//
// 	// $> ./epur_str " this        time it      will     be    more complex  . " | cat
// 	// 	-e
// 	// // this time it will be more complex .$
// 	// // $> ./epur_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
// 	// // $
// 	// // $> ./epur_str "" | cat -e
// 	// // $
// 	// // $>

#include <unistd.h>

int	ispace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}
int	main(int ac, char **av)
{
	int i;

	if (ac != 2)
		write(1, "\n", 1);
	else
	{
		i = 0;
		while (av[1][i])
		{
			if (ispace(av[1][i]))
				i++;
			else if (av[1][i + 1] == ' ')
			{
				write(1, &av[1][i], 1);
				if (av[1][i + 2] != '\0')
					write(1, " ", 1);
				i++;
			}
			else
			{
				write(1, &av[1][i], 1);
				i++;
			}
		}
		write(1, "\n", 1);

		return (0);
	}
}