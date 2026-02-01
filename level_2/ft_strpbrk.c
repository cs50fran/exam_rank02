/*

Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2);

*/


#include <string.h>
#include <stdio.h>


char	*ft_strpbrk(const char *s1, const char *s2)
{
    int j;

    while(*s1)
    {
        j = 0;
        while(s2[j])
        {
            if(*s1 == s2[j])
                return ((char *)s1);
            j++;
        }
        s1++;
    }
    return NULL;
}

int main(int ac, char **av)
{
    if(ac == 3)
    {
        printf("Original: %s\n", strpbrk(av[1], av[2]));
        printf("le copie: %s\n", ft_strpbrk(av[1], av[2]));
    }
}