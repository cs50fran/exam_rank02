/*

Assignment name  : paramsum
Expected files   : paramsum.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays the number of arguments passed to it, followed by
a newline.

If there are no arguments, just display a 0 followed by a newline.

Example:

$>./paramsum 1 2 3 5 7 24
6
$>./paramsum 6 12 24 | cat -e
3$
$>./paramsum | cat -e
0$
$>

*/

#include <unistd.h>


void ft_putnbr(int nb)
{
    char c;
    if (nb >= 10)
        ft_putnbr(nb / 10);
    c = nb % 10 + '0';
    write(1, &c, 1);
}


int main(int ac, char **av)
{
    if(ac > 1)
    {
        int i = 1;
        while(av[i])
            i++;
        ft_putnbr(--i);
    }
    write(1, "\n", 1);
    return 0;
}