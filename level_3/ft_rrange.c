/*

Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.

*/

#include <stdlib.h>
#include <stdio.h>

int     *ft_rrange(int start, int end)
{
	int i = 0;
	int range = start - end;

	if (range < 0)
		range = range * -1;
	int *arr = malloc(sizeof(int) * (range + 1));;
	if(!arr)
		return NULL;
	while(i <= range)
	{
		if(start > end)
			arr[i] = end + i;
		else
			arr[i] = end - i;
		i++;
	}
	return arr;
}

int main()
{
	int start = 0;
	int end = 0;
	int *res = ft_rrange(start, end);
	
	int range = start - end;
	if (range < 0)
		range *= -1;
	int i = 0;
	while(i <= range)
	{
		printf("range pos %d: %d\n", i, res[i]);
		i++;
	}
}