/*

Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>

*/

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int is_alpha(char c)
{
	if((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return 1;
	return 0;
}

char to_lower(char c)
{
	if(c >= 'A' && c <= 'Z')
		c += 32;
	return c;
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0;
		int count = 0;
		while(av[1][i])
		{
			if(is_alpha(av[1][i]))
			{
				count = to_lower(av[1][i]) - 97;
				while (count >= 0)
				{
					ft_putchar(av[1][i]);
					count--;
				}
			}
			else
				ft_putchar(av[1][i]);
			i++;
		}
	}
	ft_putchar('\n');
	return 0;
}
