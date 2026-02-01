/*

Assignment name	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the strspn function 
(man strspn).

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept);

*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>

size_t  ft_strcspn(const char *s, const char *accept)
{
    int     i = 0;
    int     j;
    while (s[i]) 
    {
		j = 0;
        while (accept[j])
            if(s[i] != accept[j]) 
                return i;
    }
    return i;
}


