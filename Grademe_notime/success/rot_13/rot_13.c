/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:40:07 by abendrih          #+#    #+#             */
/*   Updated: 2025/07/01 18:16:11 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : rot_13
// Expected files   : rot_13.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays it, replacing each of its
// letters by the letter 13 spaces ahead in alphabetical order.

// 'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

// The output will be followed by a newline.

// If the number of arguments is not 1, the program displays a newline.

// Example:

// $>./rot_13 "abc"
// nop
// $>./rot_13 "My horse is Amazing." | cat -e
// Zl ubefr vf Nznmvat.$
// $>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
// NxwuM mYXVWm , 23l $
// $>./rot_13 | cat -e
// $
// $>
// $>./rot_13 "" | cat -e
// $
// $>

#include <unistd.h>

int	is_alpha(char c)
{
	if ((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'M'))
		return (1);
	else if ((c >= 'n' && c <= 'z') || (c >= 'N' && c <= 'Z'))
		return (2);
	else
		return (0);
}

int	main(int ac, char **av)
{
	int		i;
	char	c;

	if (ac != 2)
		return (write(1, "\n", 1), 0);
	i = 0;
	while (av[1][i])
	{
		if (is_alpha(av[1][i]) == 1)
		{
			c = av[1][i] + 13;
			write(1, &c, 1);
			i++;
		}
		else if (is_alpha(av[1][i]) == 2)
		{
			c = av[1][i] - 13;
			write(1, &c, 1);
			i++;
		}
		else
		{
			write(1, &av[1][i], 1);
			i++;
		}
	}
	return (write(1, "\n", 1), 0);
}
