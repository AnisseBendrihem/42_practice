/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 20:43:59 by abendrih          #+#    #+#             */
/*   Updated: 2025/06/25 21:33:26 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : ft_itoa
// Expected files   : ft_itoa.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write a function that takes an int and converts it to a null-terminated string.
// The function returns the result in a char array that you must allocate.

// Your function must be declared as follows:

// char	*ft_itoa(int nbr);

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	numlen(long nbr)
{
	int	i;

	i = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		i++;
	}
	while (nbr >= 10)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	char	*result;
	int		i;
	long	n;

	n = nbr;
	i = numlen(n);
	result = malloc(i);
	if (!result)
		return (NULL);
	result[i] = '\0';
	i--;
	if (n < 0)
	{
		result[0] = '-';
		n *= -1;
	}
	while (n >= 10)
	{
		result[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	if (n < 10)
		result[i] = n + '0';
	return (result);
}
