/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pouwer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 23:36:43 by abendrih          #+#    #+#             */
/*   Updated: 2025/10/09 01:48:32 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ssum(int *subresult) //fonction qui additionne tout ce quil a dans le tableau
{
	int i = 0;
	int sum = 0;
	
	while (subresult[i])
	{
		sum = sum + subresult[i];
		i++;
	}
	return (sum);
}

void powerset(int *set, int *subresult, int target, int nbr_val , int idx, int len_subresult)
{
	int i;
	int sum;

	i = 0;
	sum = ssum(subresult); //la somme de toutes les nombres
	
	if (sum == target)            // si on arrive a la bonne somme on imprime tout simplement tout les chiffre  
	{
		while (i < len_subresult)
		{
			printf("%d", subresult[i]);
			i++;
		}
		printf("\n");
		return;
	}
	
	while (idx < nbr_val)
	{
		if(sum + set[idx] <= target)
		{
			subresult[len_subresult] = set[idx];
			powerset(set, subresult, target, idx + 1, nbr_val, len_subresult + 1);
			subresult[len_subresult] = 0;
		}
		idx ++;
	}
}

int	main(int ac, char **av)
{
	int	i;  //index
	int	target; // le premier nombre a atteindre 
	int	nbr_val; // le nombre de valeur en dehors du nombre phare
	int	*set;	// le tableau de valeur 
	int	*subresult; // le tableau des resultat a imprimer 

	i = 0;
	if (ac <= 2)
		return (1);
	target = atoi(av[1]);
	nbr_val = ac - 2; 
    set = malloc(sizeof(int) * nbr_val);
	subresult = malloc(sizeof(int) * nbr_val);
	while (i < nbr_val)         // boucle de remplissage de nos deux tableau 
	{
		set[i] = atoi(av[i + 2]); // on remplis de tout les nombre mis a part le nb phare 
		subresult[i] = 0;    // on remplis de 0 pour linstant 
		i++;
	}
	powerset(set, subresult, target, nbr_val, 0, 0); //fonction recursive qui print les valeur somme de target 
	free(set);
	free(subresult);
	return (0);
}
