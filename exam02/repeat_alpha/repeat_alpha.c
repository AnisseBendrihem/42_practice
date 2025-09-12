/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:09:28 by abendrih          #+#    #+#             */
/*   Updated: 2025/06/23 17:37:10 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : repeat_alpha
// Expected files   : repeat_alpha.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program called repeat_alpha that takes a string and display it
// repeating each alphabetical character as many times as its alphabetical index,
// followed by a newline.

// 'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

// Case remains unchanged.

// If the number of arguments is not 1, just display a newline.

// Examples:

// $>./repeat_alpha "abc"
// abbccc
// $>./repeat_alpha "Alex." | cat -e
// Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
// $>./repeat_alpha 'abacadaba 42!' | cat -e
// abbacccaddddabba 42!$
// $>./repeat_alpha | cat -e
// $
// $>
// $>./repeat_alpha "" | cat -e
// $
// $>

#include <unistd.h>

int	is_alpha(char c)
{
	if (c >= 'a' && c <= 'z')
		return (0);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (-1);
}

void	ft_putnchar(char c)
{
	int	i;

	i = 0;
	if (is_alpha(c) == 1)
	{
		while (i <= (int)c - 'A')
		{
			write(1, &c, 1);
			i++;
		}
	}
	else if (is_alpha(c) == 0)
	{
		while (i <= (int)c - 'a')
		{
			write(1, &c, 1);
			i++;
		}
	}
	else
	{
		write(1, &c, 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		write(1, "\n", 1);
	else
	{
		int i;

		i = 0;
		while (av[1][i])
		{
			ft_putnchar(av[1][i]);
			i++;
		}
		write(1, "\n", 1);
	}
	return (0);
}