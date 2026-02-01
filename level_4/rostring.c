/*

Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>

*/

#include <unistd.h>
#include <stdio.h>

void w_lastword(char *s)
{
	int i = 0;
	int start, end;
	while(s[i++]);
	while (i >= 0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\0'))
		i--;
	end = i;
	while (i >= 0 && (s[i] != ' ' && s[i] != '\t'))
		i--;
	start = i + 1;
	while(start < end)
		write(1, &s[start++], 1);
}

int is_space(char c)
{
	return(c == ' ' || c == '\t');
}

void rostring(char *s)
{
	int i = 0;
	int start;
	int end;
	while(is_space(s[i]))
		i++;
	start = i;
	while(s[i] && !is_space(s[i]))
		i++;
	end = i - 1;
	// ------------------------
	while(s[i])
	{
		while(s[i] && is_space(s[i]))
			i++;
		while(s[i] && !is_space(s[i]))
			write(1, &s[i++], 1);
		if(s[i] && s[i + 1] && is_space(s[i]) && !is_space(i + 1))
			write(1, &s[i++], 1);
	}
	write(1, " ", 1);
	while(start <= end)
		write(1, &s[start++], 1);
}



int main(int ac, char **av)
{
	if(ac > 1)
		rostring(av[1]);
	write(1, "\n", 1);
	return 0;
}
