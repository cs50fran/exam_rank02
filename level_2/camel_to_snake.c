/*

Assignment name  : camel_to_snake
Expected files   : camel_to_snake.c
Allowed functions: malloc, free, realloc, write
--------------------------------------------------------------------------------

Write a program that takes a single string in lowerCamelCase format
and converts it into a string in snake_case format.

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

Examples:
$>./camel_to_snake "hereIsACamelCaseWord"
here_is_a_camel_case_word
$>./camel_to_snake "helloWorld" | cat -e
hello_world$
$>./camel_to_snake | cat -e
$

*/

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void new_line(void)
{
    ft_putchar('\n');
}

int is_upper(char c)
{
	if(c >= 'A' && c <= 'Z')
		return 1;
	return 0;
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int i = 0;

        while(av[1][i])
        {
            if(is_upper(av[1][i]))
            {
                ft_putchar('_');
                av[1][i] += 32;
            }
            ft_putchar(av[1][i++]);
        }
    }
    new_line();
    return 0;
}