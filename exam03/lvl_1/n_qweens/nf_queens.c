/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nf_queens.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:48:10 by abendrih          #+#    #+#             */
/*   Updated: 2025/10/08 22:30:07 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int is_safe(int *positions, int current_col, int current_row)
{
	for (int prev_col = 0; prev_col < current_col; prev_col++)
	{
		int prev_row = positions[prev_col];
		if (prev_row == current_row ||
			prev_row - prev_col == current_row - current_col ||
			prev_row + prev_col == current_row + current_col)
			return 0;
	}
	return 1;
}

void solve(int *positions, int col, int n)
{
	if (col == n)
	{
	   for (int i = 0; i < n; i++)
		{
			if (i > 0)
				printf(" ");
			printf("%d", positions[i]);
		}
		printf("\n");
		return;
	}
	for(int row = 0; row < n; row++)
	{
		if(is_safe(positions, col, row))
		{
			positions[col] = row;
			solve(positions, col + 1, n);
		}
	}
}

int main(int ac, char **av)
{
	if(ac == 2 && av[1][0] != '-')
	{
		int n = atoi(av[1]);
		int *positions = malloc(sizeof(int) * n);
		if (!positions)
			return 1;
		solve(positions, 0, n);
		free(positions);
	}
	return 0;
}
