#include <unistd.h>
int main(int ac, char **av)
{
    if (ac != 2)
        {
            write(1, "\n", 1);
            return 0;
        }
        int i = 0;
        int j = 0;
        while ((av[1][i] >= 9 && av[1][i] <= 13) || av[1][i] == 32) 
        {
            i++;
            j++;
        }
        while  (av[1][i] && av[1][i] < 9 || av[1][i] > 13 && av[1][i] != 32)
            i++;
        while (j < i)
        {
            write(1, &av[1][j], 1);
            j++;
        }
        write (1, "\n", 1);
        return 0;
}