/*

Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);

*/

#include <stdio.h>
#include <stdlib.h>

int power(int n, int power)
{
    int res = 1;
    while(power-- > 0)
        res = res * n;
    return res;
}

char	*ft_itoa(int nbr)
{
    int neg = 0;
    int size = 1;
    int temp;
    int i = 0;
    int j = 0;
    char *res;

    if(nbr < 0)
    {
        neg = 1;
        nbr *= -1;
    }
    temp = nbr;
    while(temp >= 10)
    {
        size++;
        temp /= 10;
    }
    printf("size: %d\n", size);
    res = malloc(sizeof(char) * (size + neg + 1));
    if(neg == 1)
        res[j++] = '-';
    while(i < size + neg)
    {
        res[j++] = (nbr / power(10, size - 1 - i)) % 10 + '0';
        i++;
    }
    res[i] = '\0';
    return res;
}

int main(int ac, char **av)
{
    if(ac == 2)
    {
        // printf("power: %d\n", power(atoi(av[1]), atoi(av[2])));
        printf("itoa: %s\n", ft_itoa(atoi(av[1])));
    }

}