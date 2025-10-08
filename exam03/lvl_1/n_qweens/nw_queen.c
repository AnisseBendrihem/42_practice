/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nw_queen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 22:27:43 by abendrih          #+#    #+#             */
/*   Updated: 2025/10/08 22:31:21 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	check_board(int *board, int value, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (board[i] == value || 
            board[i] - value == i - index || 
            board[i] - value == index - i)
			return (0);
		i++;
	}
	return (1);
}

void	nqueens(int *board, int N, int index)
{
	int	i;
	int	value;

	i = 0;
	value = 0;
	if (index == N)
	{
		while (i < N)
			printf("%d", board[i++]);
		printf("\n");
		return ;
	}
	while (value < N)
	{
		if (check_board(board, value, index))
		{
			board[index] = value;
			nqueens(board, N, index + 1);
			board[index] = -1;
		}
		value++;
	}
}

int	main(int argc, char **argv)
{
	int	N;
	int	*board;
	int	i;

	if (argc != 2)
	{
		write(1, "Usage: ./nqueens N\n", 19);
		return (1);
	}
	N = atoi(argv[1]);
	if (N < 1 || N > 20)
	{
		write(1, "N must be between 1 and 20\n", 27);
		return (1);
	}
	board = malloc(sizeof(int) * N);
	if (!board)
		return (1);
	i = 0;
	while (i < N)
	{
		board[i] = -1;
		i++;
	}
	nqueens(board, N, 0);
	free(board);
	return (0);
}
