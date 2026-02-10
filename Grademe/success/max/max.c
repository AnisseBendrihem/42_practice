/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:47:10 by abendrih          #+#    #+#             */
/*   Updated: 2025/07/11 19:01:56 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : max
// Expected files   : max.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write the following function:

// int		max(int* tab, unsigned int len);

// The first parameter is an array of int, the second is the number of elements in
// the array.

// The function returns the largest number found in the array.

// If the array is empty, the function returns 0.

#include <stdio.h>

int		max(int* tab, unsigned int len)
{
    unsigned int i;
    int r;

    i = 0;
    r = tab[i];
    while (i < len)
    {
        if (r < tab[i])
            r = tab[i];
        i++;
    }
    return (r);
}

// int main ()
// {
//     int tab[4]= {1, 5, 6, 4}; 
//     printf("%d", max(tab, 4));
// }