/* Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions: 
--------------------------------------------------------------------------------

Write the following function:

void sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent.
 */

#include <stdlib.h>
#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i;
	unsigned int j = 0;
	int temp;

	while(j < size)
	{
		i = 0;
		while(i < size - j)
		{
			if(tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
			}
			i++;
		}
		j++;
	}
}

int main(int ac, char **av)
{
	int *tab = (int[]){7, 7, 0, 3, 2, 0, 61};
	if(ac == 2)
		sort_int_tab(tab, atoi(av[1]));
	int i = 0;
	while(i < atoi(av[1]))
	{
		printf("tab %d: %d\n", i, tab[i]);
		i++;
	}
}