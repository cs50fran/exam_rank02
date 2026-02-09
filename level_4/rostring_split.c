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
#include <stdlib.h>

// fazer splic e imprimir a comecar na segunda

void ft_putstr(char *s)
{
	while(*s)
		write(1, s++, 1);
}

int is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int count_words(char *s)
{
	if(!s)
		return 0;
	int i = 0;
	int count = 0;
	while(s[i] && is_space(s[i]))
		i++;
	while(s[i])
	{
		if(!is_space(s[i]))
		{
			count++;
			while(s[i] && !is_space(s[i]))
				i++;
		}
		while(s[i] && is_space(s[i]))
			i++;
	}
	return count;
}

char *ft_substr(char *s, int start, int len)
{
	if(!s || s[0] == 0)
		return NULL;
	int i = 0;
	char *res = malloc(sizeof(char) * (len + 1));

	while(i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return res;
}

char **ft_split(char *s)
{
	int words = count_words(s);
	char **arr = malloc(sizeof(char *) * words);
	int start = 0;
	int len = 0;
	int k = 0;

	while(k < words)
	{
		while(s[start] && is_space(s[start]))
			start++;
		while(!is_space(s[start + len]))
			len++;
		arr[k] = ft_substr(s, start, len);
		start += len;
		len = 0;
		k++;
	}
	return arr;
}

void rostring(char *s)
{
	if(!s || !s[0])
		return;
	int words = count_words(s);
	char **split = ft_split(s);

	if(words == 1)
	{
		ft_putstr(split[0]);
		return;
	}
	int i = 1;
	while(i < words)
	{
		ft_putstr(split[i]);
		ft_putstr(" ");
		i++;
	}
	ft_putstr(split[0]);
}

int main(int ac, char **av)
{
	if (ac == 2)
		rostring(av[1]);
write(1, "\n", 1);
return 0;
}
