/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:44:53 by abendrih          #+#    #+#             */
/*   Updated: 2025/07/01 22:22:37 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : print_hex
// Expected files   : print_hex.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a positive (or zero) number expressed in base 10,
// and displays it in base 16 (lowercase letters) followed by a newline.

// If the number of parameters is not 1, the program displays a newline.

// Examples:

// $> ./print_hex "10" | cat -e
// a$
// $> ./print_hex "255" | cat -e
// ff$
// $> ./print_hex "5156454" | cat -e
// 4eae66$
// $> ./print_hex | cat -e
// $

#include <stdio.h>
#include <unistd.h>

int	mini_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}

void	ft_puthex(int nbr)
{
	if (nbr > 16)
		ft_puthex(nbr / 16);
	write(1, &"0123456789abcdef"[nbr % 16], 1);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (write(1, "\n", 1), 0);
	ft_puthex(mini_atoi(av[1]));
	return (write(1, "\n", 1), 0);
}

// ----------------8<-------------[ START TEST
//         💻 TEST
// ./a.out "4324324"
//         🔎 YOUR OUTPUT:
// 4b04b04$
//         🗝 EXPECTED OUTPUT:
// 41fbe4$
// ----------------8<------------- END TEST ]
