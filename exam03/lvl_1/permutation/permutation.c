/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:48:13 by abendrih          #+#    #+#             */
/*   Updated: 2025/09/12 13:49:30 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name : permutations

// Expected files : *.c *.h
// Allowed functions : puts, malloc, calloc, realloc, free, write
// ---------------------------------------------------------------

// Write a program that will print all the permutations of a string given as argument.

// The solutions must be given in alphabetical order.

// We will not try your program with strings containing duplicates (eg: 'abccd')

// For example this should work:
// $> ./permutations a | cat -e
// a$
// $> ./permutations ab | cat -e
// ab$
// ba$
// $> ./permutations abc | cat -e
// abc$
// acb$
// bac$
// bca$
// cab$
// cba$