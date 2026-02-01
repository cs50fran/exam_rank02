/*

Assignment name  : rot_13
Expected files   : rot_13.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

The output will be followed by a newline.

If the number of arguments is not 1, the program displays a newline.

Example:

$>./rot_13 "abc"
nop
$>./rot_13 "My horse is Amazing." | cat -e
Zl ubefr vf Nznmvat.$
$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
NxwuM mYXVWm , 23l $
$>./rot_13 | cat -e
$
$>
$>./rot_13 "" | cat -e
$
$>

*/

#include <unistd.h>

int is_alpha(char c)
{
	if((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return 1;
	return 0;
}

char rot_13(char c)
{
	if((c > 'm' && c <= 'z') || (c > 'M' && c <= 'Z') )
		c -= 13;
	else
		c += 13;
	return c;
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0;
		char c;

		while(av[1][i])
		{
			c = av[1][i];
			if(is_alpha(av[1][i]))
				c = rot_13(av[1][i]);
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}