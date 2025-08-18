// Assignment name  : rotone
// Expected files   : rotone.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays it, replacing each of its
// letters by the next one in alphabetical order.

// 'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.

// The output will be followed by a \n.

// If the number of arguments is not 1, the program displays \n.

// Example:

// $>./rotone "abc"
// bcd
// $>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
// Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
// $>./rotone "AkjhZ zLKIJz , 23y " | cat -e
// BlkiA aMLJKa , 23z $
// $>./rotone | cat -e
// $
// $>
// $>./rotone "" | cat -e
// $
// $>


#include <unistd.h>

int is_alpha(char c)
{
	if (c >= 'a' && c <'z' )
		return(1);
	if (c >= 'A' && c < 'Z' )
		return (2);
	return (0);
	
}

int main(int ac, char **av)
{
	int i;
	char c;

	i = 0;
	if (ac != 2)
		return (write(1, "\n", 1));

	while(av[1][i])
	{
		if (is_alpha(av[1][i]) == 1)
		{
			c = av[1][i] + 1;
				write (1, &c, 1);
		}
		else if (is_alpha(av[1][i]) == 2)
		{
			c = av[1][i] + 1;
			write (1, &c, 1);
		}
		else if (av[1][i] == 'z' || av[1][i] == 'Z')
		{
			c = av[1][i] - 25;
			write (1, &c, 1);
		}
		else
			write (1, &av[1][i], 1);
		i++;
	}
	return (write(1, "\n", 1));

}