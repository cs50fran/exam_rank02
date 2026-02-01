/*

Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.

*/

int		max(int* tab, unsigned int len)
{
    unsigned int i = 0;
    int max = 0;

    while(i <= len)
    {
        if (tab[i] > max)
            max = tab[i];
        i++;
    }
    return max;
}

#include <stdio.h>
int main()
{
    int tab[10] = {100, 700, 89, 16, 7453, 5, 64, 91, 28, 54};
    printf("MAX: %d", max(tab, 10));
}