/*

Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char    *ft_strdup(char *src)
{
    char    *new;
    size_t  len = 0;

    while (src[len])
        len++;
    new = malloc(sizeof(char *)*len + 1);
    if (!new)
        return 0;
    len = 0;
    while(src[len])
    {
        new[len] = src[len];
        len++;
    }
    new[len] = '\0';
    return new;
}

int main()
{
    char s[] = "teste";

    printf("Original: %s\n", strdup(s));
    printf("le copie: %s\n", ft_strdup(s));
}