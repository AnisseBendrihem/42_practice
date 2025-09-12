/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 01:18:19 by abendrih          #+#    #+#             */
/*   Updated: 2025/07/04 01:41:40 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : pgcd
// Expected files   : pgcd.c
// Allowed functions: printf, atoi, malloc, free
// --------------------------------------------------------------------------------

// Write a program that takes two strings representing two strictly positive
// integers that fit in an int.

// Display their highest common denominator followed by a newline (It's always a
// strictly positive integer).

// If the number of parameters is not 2, display a newline.

// Examples:

// $> ./pgcd 42 10 | cat -e
// 2$
// $> ./pgcd 42 12 | cat -e
// 6$
// $> ./pgcd 14 77 | cat -e
// 7$
// $> ./pgcd 17 3 | cat -e
// 1$
// $> ./pgcd | cat -e
// $

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	gcd(int *x, int *y)
{
	int	recip;

	while (*y != 0)
	{
		recip = *y;
		*y = *x % *y;
		*x = recip;
	}
	return (*x);
}

int	main(int ac, char **av)
{
	int	x;
	int	y;
	int	r;

	if (ac != 3)
		return (write(1, "\n", 1), 0);
	x = atoi(av[1]);
	y = atoi(av[2]);
	if (x > y)
		r = gcd(&x, &y);
	else
		r = gcd(&y, &x);
	printf("%d\n", r);
}
