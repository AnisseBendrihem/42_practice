#include <unistd.h>

void	ft_print(char *s1, char *s2)
{
	int		i;
	int		j;
	char	recip[256];

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j] && recip[(int)s1[i]] != s1[i])
			{
				write(1, &s1[i], 1);
				recip[(int)s1[i]] = s1[i];
				break ;
			}
			else
				j++;
		}
		i++;
	}
}

int	main(int ac, char *av[])
{
	if (ac != 3)
		write(1, "\n", 1);
	else
	{
		ft_print(av[1], av[2]);
		write(1, "\n", 1);
	}
	return (0);
}