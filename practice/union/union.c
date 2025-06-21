/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 16:01:48 by abendrih          #+#    #+#             */
/*   Updated: 2025/06/21 19:07:57 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strconcat(char *s1, char *s2, char *s3)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	return (s3);
}
void	ft_print(char *str)
{
	int		i;
	char	recip[256];

	i = 0;
	while (str[i])
	{
		if (str[i] == recip[(int)str[i]])
			i++;
		else
		{
			recip[(int)str[i]] = str[i];
			write(1, &str[i], 1);
			i++;
		}
	}
}

int	main(int ac, char *av[])
{
	char	tmp[256];

	if (ac != 3)
		write(1, "\n", 1);
	else
	{
		ft_strconcat(av[1], av[2], tmp);
		ft_print(tmp);
		write(1, "\n", 1);
	}
	return (0);
}
