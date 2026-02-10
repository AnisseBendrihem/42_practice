/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 00:14:52 by abendrih          #+#    #+#             */
/*   Updated: 2025/06/23 01:06:17 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// // # Assignment name  : do_op
// // # Expected files   : do_op.c
// // # Allowed functions: atoi, printf, write
//
// # --------------------------------------------------------------------------------

// // # Write a program that takes three strings:
// // #
// 	- The first and the third one are representations of base-10 signed integers
// // #   that fit in an int.
// // # - The second one is an arithmetic operator chosen from: + - * / %

//
// # The program must display the result of the requested arithmetic operation,
// // # followed by a newline. If the number of parameters is not 3, the program
// // # just displays a newline.

//
// # You can assume the string have no mistakes or extraneous characters. Negative
// // # numbers, in input or output, will have one and only one leading '-'. The
// // # result of the operation fits in an int.

// // # Examples:

// // # $> ./do_op "123" "*" 456 | cat -e
// // # 56088$
// // # $> ./do_op "9828" "/" 234 | cat -e
// // # 42$
// // # $> ./do_op "1" "+" "-43" | cat -e
// // # -42$
// // # $> ./do_op | cat -e
// // # $

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac != 4)
		write(1, "\n", 1);
	else
	{
		int a;
		int b;
		int result = 0;
		char signe;

		a = atoi(av[1]);
		b = atoi(av[3]);
		signe = av[2][0];
		switch (signe)
		{
            case '+':
                result = a + b;
                break ;
            case '*':
                result = a * b;
                break ;
            case '/':
                result = a / b;
                break ;
		}
		printf("%d\n", result);
	}
	return (0);
}