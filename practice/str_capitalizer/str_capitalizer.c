/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:33:37 by abendrih          #+#    #+#             */
/*   Updated: 2025/06/26 20:33:24 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_alpha(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (2);
	else if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

int	main(int ac, char **av)
{
	int		i;
	int		j;
	char	c;

	if (ac < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	else
	{
		j = 1;
		while (j < ac)
		{
			i = 0;
			while (av[j][i])
			{
				if (is_alpha(av[j][i]) && is_alpha(av[j][i - 1]) == 0)
				{
					if (is_alpha(av[j][i]) == 1)
						c = av[j][i] - 32;
					else if (is_alpha(av[j][i]) == 2)
						c = av[j][i];
				}
				else if (is_alpha(av[j][i]) == 2)
					c = av[j][i] + 32;
				else
					c = av[j][i];
				i++;
				write(1, &c, 1);
			}
			j++;
			write(1, "\n", 1);
		}
	}
	return (0);
}
