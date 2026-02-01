/*

Assignment name  : alpha_mirror
Expected files   : alpha_mirror.c
Allowed functions: write
--------------------------------------------------------------------------------
 
Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.
 
'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'
 
and so on.
 
Case is not changed.
 
If the number of arguments is not 1, display only a newline.
 
Examples:
 
$>./alpha_mirror "abc"
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
$
$>

*/

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *s)
{
	while(*s)
		ft_putchar(*s++);
}

int is_lower(char c)
{
	if(c >= 'a' && c <= 'z')
		return 1;
	return 0;
}

int is_upper(char c)
{
	if(c >= 'A' && c <= 'Z')
		return 1;
	return 0;
}

int main(int ac, char **av)
{
	if(ac == 2)
	{
		int i = 0;

		while(av[1][i])
		{
			if(is_lower(av[1][i]))
				av[1][i] = 'a' + ('z' - av[1][i]);
			if(is_upper(av[1][i]))
				av[1][i] = 'A' + ('Z' - av[1][i]);
			write(1, &av[1][i++], 1);
		}
	}
	write(1, "\n", 1);
	return 0;
}