/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:47:38 by abendrih          #+#    #+#             */
/*   Updated: 2025/06/27 16:25:30 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// // Assignment name  : max
// // Expected files   : max.c
// // Allowed functions:
//
// --------------------------------------------------------------------------------

// // Write the following function:

// // int		max(int* tab, unsigned int len);

// // The first parameter is an array of int,
// the second is the number of elements in
// 	// the array.

// 	// The function returns the largest number found in the array.

// 	// If the array is empty, the function returns 0.

int	max(int *tab, unsigned int len)
{
	unsigned int	i;
	int				n;

	n = tab[0];
	if (!tab)
		return (0);
	i = 1;
	while (i < len)
	{
		if (n < tab[i])
			n = tab[i];
		i++;
	}
	return (n);
}
