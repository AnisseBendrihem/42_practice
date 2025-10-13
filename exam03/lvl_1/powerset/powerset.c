/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baron_kakka <baron_kakka@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:48:16 by abendrih          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/10/09 01:40:15 by abendrih         ###   ########.fr       */
=======
/*   Updated: 2025/10/13 17:25:51 by baron_kakka      ###   ########.fr       */
>>>>>>> f4f07f5 (progress(exam03): mastered all exercises except nqueen and rip)
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
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

=======

int summ(int *subset, int len)
{
    int i = 0;
    int sum = 0;
    while (i < len)
    {
        sum += subset[i];
        i++;
    }
    return (sum);
}

void powerset(int target, int *set, int *subset, int len_set, int idx, int len_subset)
{
    int i = 0;
    int sum = summ(subset, len_subset);
    
    if( sum == target)
    {
        while (i < len_subset)
        {
            printf("%d", subset[i]);
            if (i != len_subset -1)
                printf(" ");
            i++;
        }
        printf("\n");
    }
    while (idx < len_set)
    {
        if (set[idx] + sum <= target)
        {
            subset[len_subset] = set[idx];
            powerset(target, set, subset, len_set, idx + 1, len_subset + 1);
            subset[len_subset] = 0;
        }
        idx++;
    }
}

int main (int ac , char **av)
{
    int target;
    int *set;
    int *subset;
    int len_set;

    if (ac <= 2)
        return (1);
    len_set = ac - 2;
    target = atoi(av[1]);
    set = malloc(sizeof(int) * len_set);
    subset = malloc(sizeof(int) * len_set);
    for (int i = 0; i < len_set; i++)
    {
        set[i] = atoi(av[i + 2]);
        subset[i] = 0;
    }
    powerset(target, set, subset, len_set, 0, 0);
}
>>>>>>> f4f07f5 (progress(exam03): mastered all exercises except nqueen and rip)
