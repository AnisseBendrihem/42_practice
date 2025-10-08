/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:48:16 by abendrih          #+#    #+#             */
/*   Updated: 2025/10/09 01:40:15 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	ssum(int *subset)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (subset[i])
	{
		sum += subset[i];
		i++;
	}
	return (sum);
}

void	powerset(int *set, int *subset, int target, int index, int nbr_val,
		int len_subset)
{
	int	i;
	int	sum;

	i = 0;
	sum = ssum(subset);
	if (sum == target)
	{
		i = 0;
		while (i < len_subset)
		{
			printf("%d ", subset[i]);
			i++;
		}
		printf("\n");
		return ;
	}
	
	while (index < nbr_val)
	{
		if (sum + set[index] <= target)
		{
			subset[len_subset] = set[index];
			powerset(set, subset, target, index + 1, nbr_val, len_subset + 1);
			subset[len_subset] = 0;
		}
		index++;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	target;
	int	nbr_val;
	int	*set;
	int	*subset;

	i = 0;
	if (ac <= 2)
		return (1);
	target = atoi(av[1]);
	nbr_val = ac - 2;
	set = malloc(sizeof(int) * (nbr_val));
	subset = malloc(sizeof(int) * (nbr_val));
	while (i < nbr_val)
	{
		set[i] = atoi(av[i + 2]);
		subset[i] = 0;
		i++;
	}
	powerset(set, subset, target, 0, nbr_val, 0);
	free(set);
	free(subset);
	return (0);
}

