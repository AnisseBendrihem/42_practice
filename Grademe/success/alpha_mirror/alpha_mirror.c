/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:33:40 by abendrih          #+#    #+#             */
/*   Updated: 2025/06/25 19:52:37 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : alpha_mirror
// Expected files   : alpha_mirror.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program called alpha_mirror that takes a string and displays this string
// after replacing each alphabetical character by the opposite alphabetical
// character, followed by a newline.

// 'a' becomes 'z', 'Z' becomes 'A'
// 'd' becomes 'w', 'M' becomes 'N'

// and so on.

// Case is not changed.

// If the number of arguments is not 1, display only a newline.

// Examples:

// $>./alpha_mirror "abc"
// zyx
// $>./alpha_mirror "My horse is Amazing." | cat -e
// Nb slihv rh Znzarmt.$
// $>./alpha_mirror | cat -e
// $
// $>

#include <unistd.h>

int	is_alpha(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if ((c >= 'A' && c <= 'Z'))
		return (2);
	else
		return (0);
}

int	main(int ac, char **av)
{
	int		i;
	char	c;

	if (ac != 2)
		write(1, "\n", 1);
	else
	{
		i = 0;
		while (av[1][i])
		{
			if (is_alpha(av[1][i]) == 1)
			{
				c = 'a' - av[1][i] + 'z';
				write(1, &c, 1);
			}
			else if (is_alpha(av[1][i]) == 2)
			{
				c = 'A' - av[1][i] + 'Z';
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
