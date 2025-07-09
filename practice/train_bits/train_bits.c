/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   train_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 01:29:58 by abendrih          #+#    #+#             */
/*   Updated: 2025/07/05 15:10:37 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_bits(unsigned char octet)
{
	int				i;
	unsigned char	c;

	i = 8;
	while (i--)
	{
		c = ((octet >> i) & 1) + '0';
		write(1, &c, 1);
	}
}

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	res;
	int				i;

	res = 0;
	i = 8;
	while (i--)
	{
		res = res << 1;
		res = res | (octet & 1);
		octet = octet >> 1;
	}
	return (res);
}

int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	return ((n & (n - 1)) == 0);
}
