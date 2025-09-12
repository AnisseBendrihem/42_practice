/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 00:53:02 by abendrih          #+#    #+#             */
/*   Updated: 2025/07/10 01:26:28 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : ft_rrange
// Expected files   : ft_rrange.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write the following function:

// int     *ft_rrange(int start, int end);

// It must allocate (with malloc()) an array of integers,
// fill it with consecutive
// values that begin at end and end at start (Including start and end !), then
// return a pointer to the first value of the array.

// Examples:

// - With (1, 3) you will return an array containing 3, 2 and 1
// - With (-1, 2) you will return an array containing 2, 1, 0 and -1.
// - With (0, 0) you will return an array containing 0.
// - With (0, -3) you will return an array containing -3, -2, -1 and 0.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	*ft_rrange(int start, int end)
{
	int i;
	int len;
	int *range;

	i = 0;
	if (start > end)
		len = start - end + 1;
	else
		len = end - start + 1;
	range = malloc(sizeof(int) * len);
	if (!range)
		return (NULL);
	while (i < len)
	{
		range[i] = end;
		if (start < end)
			end--;
		else
			end++;
		i++;
	}
	return (range);
}