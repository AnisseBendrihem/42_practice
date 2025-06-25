/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:12:09 by abendrih          #+#    #+#             */
/*   Updated: 2025/06/25 19:31:41 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// // Assignment name  : rotone
// // Expected files   : rotone.c
// // Allowed functions: write
//
// --------------------------------------------------------------------------------

// // Write a program that takes a string and displays it, replacing each of its
// // letters by the next one in alphabetical order.

// // 'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.

// // The output will be followed by a \n.

// // If the number of arguments is not 1, the program displays \n.

// // Example:

// // $>./rotone "abc"
// // bcd
//
// $>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat
// 	-e
// // Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
// // $>./rotone "AkjhZ zLKIJz , 23y " | cat -e
// // BlkiA aMLJKa , 23z $
// // $>./rotone | cat -e
// // $
// // $>
// // $>./rotone "" | cat -e
// // $
// // $>
// // ➜ sub

#include <unistd.h>

int	is_alpha(char c)
{
	if ((c >= 'a' && c < 'z') || (c >= 'A' && c < 'Z'))
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
		char c;

		i = 0;
		while (av[1][i])
		{
			if (av[1][i] == 'Z' || av[1][i] == 'z')
			{
				c = av[1][i] - 25;
				write(1, &c, 1);
			}
			else if (is_alpha(av[1][i]))
			{
				c = av[1][i] + 1;
				write(1, &c, 1);
			}
			else
				write(1, &av[1][i], 1);

			i++;
		}
		write(1, "\n", 1);
	}
	return (0);
}