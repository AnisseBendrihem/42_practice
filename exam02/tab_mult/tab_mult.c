/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:42:26 by abendrih          #+#    #+#             */
/*   Updated: 2025/07/09 20:12:41 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : tab_mult
// Expected files   : tab_mult.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that displays a number's multiplication table.

// The parameter will always be a strictly positive number that fits in an int,
// and said number times 9 will also fit in an int.

// If there are no parameters, the program displays \n.

// Examples:

// $>./tab_mult 9
// 1 x 9 = 9
// 2 x 9 = 18
// 3 x 9 = 27
// 4 x 9 = 36
// 5 x 9 = 45
// 6 x 9 = 54
// 7 x 9 = 63
// 8 x 9 = 72
// 9 x 9 = 81
// $>./tab_mult 19
// 1 x 19 = 19
// 2 x 19 = 38
// 3 x 19 = 57
// 4 x 19 = 76
// 5 x 19 = 95
// 6 x 19 = 114
// 7 x 19 = 133
// 8 x 19 = 152
// 9 x 19 = 171
// $>
// $>./tab_mult | cat -e
// $
// $>

#include <unistd.h>

int	ft_miniatoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] <= '9' && str[i] >= '0')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}

void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

void	mult(int n)
{
	int	i;

	i = 1;
	while (i < 10)
	{
		ft_putnbr(i);
		write(1, " x ", 3);
		ft_putnbr(n);
		write(1, " = ", 3);
		ft_putnbr(n * i);
		write(1, "\n", 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	n;

	if (ac == 1)
		return (write(1, "\n", 1), 0);
	n = ft_miniatoi(av[1]);
	mult(n);
	return (0);
}
