/*

Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$

*/

#include <unistd.h>
#include <stdio.h>

int ft_atoi(char *s)
{
    int i = 0;
    int res = 0;

    while(s[i] >= '0' && s[i] <= '9')
        res = res * 10 + (s[i++] - '0');
    return res;
}

void write_hex(int nb)
{
    char base[16] = "0123456789abcdef";

    if(nb >= 16)
        write_hex(nb / 16);
    write(1, &base[nb % 16], 1);
}

int main(int ac, char ** av)
{
    if(ac == 2)
        write_hex(ft_atoi(av[1]));
    write(1, "\n", 1);
    return 0;
}