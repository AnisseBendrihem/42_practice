/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baron_kakka <baron_kakka@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:52:41 by baron_kakka       #+#    #+#             */
/*   Updated: 2025/10/14 16:22:51 by baron_kakka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int found = 0;

void power( int target, int *set, int *subset, int len_set, int idx,  int len_subset, int sum)
{
    if (sum == target && len_subset > 0)
    {
        found = 1;
        for (int i = 0; i < len_subset; i++)
        {
            if (i > 0)
                printf(" ");
            printf("%d", subset[i]);
        }
        printf("\n");
    }
    while  (idx < len_set)
    {
        subset[len_subset] = set[idx];
        power(target,set, subset, len_set,  idx + 1, len_subset + 1, sum + set[idx]);
        idx++;
    }
}

int main(int ac, char **av)
{
    if (ac < 2)
        return 0;
    
    int target = atoi(av[1]);
    int len_set = ac - 2;
    
    int *set = malloc(len_set * sizeof(int));
    int *subset = malloc(len_set * sizeof(int));
    if (!set || !subset)
        return 1;
    
    for (int i = 0; i < len_set; i++)
        set[i] = atoi(av[i + 2]);
    
    power(target, set, subset, len_set,  0,  0, 0);
    
    if (!found)
        printf("\n");
    
    free(set);
    free(subset);
    return 0;
}
