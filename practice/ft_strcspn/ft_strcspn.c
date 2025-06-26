/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:48:52 by abendrih          #+#    #+#             */
/*   Updated: 2025/06/26 16:27:07 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// // Expected files	: ft_strcspn.c
// // Allowed functions: None
// // ---------------------------------------------------------------

// // Reproduce exactly the behavior of the function strcspn
// // (man strcspn).

// // The function should be prototyped as follows:

// // size_t	ft_strcspn(const char *s, const char *reject);

int	ft_strcspn(const char *s, const char *reject)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
