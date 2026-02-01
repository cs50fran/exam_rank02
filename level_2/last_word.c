/*

Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>

*/

#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int is_space(char c)
{
    if(c == 32 || (c >= 9 && c <= 13))
        return 1;
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int i = 0;
        int j = 0;

        while(av[1][i])
        {
            if (av[1][i] && is_space(av[1][i]) && !is_space(av[1][i + 1]) && av[1][i + 1])
                j = i + 1;
            i++;
        }
        while(av[1][j] && !is_space(av[1][j]))
        {
            ft_putchar(av[1][j]);
            j++;
        }
    }
    ft_putchar('\n');
    return 0;
}

/* int main(int ac, char **av)
{
    if (ac == 2)
    {
        int i = 0;

        // ir até ao fim
        while(av[1][i++]);
        i--; // estamos na última posição

        // se houver espaços no fim, recuar até uma letra
        while(is_space(av[1][i]))
            i--;

        // estamos numa letra, recuar até ao inicio da ultima palavra
        while(i >= 0 && !is_space(av[1][i]))
            i--;

        i++; // estamos na 1a letra da última palavra

        // escrever enquanto não for um espaço
        while(!is_space(av[1][i]) && av[1][i])
        {
            ft_putchar(av[1][i]);
            i++;
        }
    }
    ft_putchar('\n');
    return 0;
} */

