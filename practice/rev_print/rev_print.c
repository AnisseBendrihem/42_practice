/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:27:10 by abendrih          #+#    #+#             */
/*   Updated: 2025/06/20 15:54:42 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return i;
}

#include <unistd.h>
int main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	int i = ft_strlen(av[1]) - 1;
	while (i >= 0)
	{
		write (1, &av[1][i], 1);
		i--;
	}
	write (1, "\n", 1);
	return (0);
}
