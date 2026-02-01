/*

Assignment name  : rstr_capitalizer
Expected files   : rstr_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or more strings and, for each argument, puts 
the last character that is a letter of each word in uppercase and the rest
in lowercase, then displays the result followed by a \n.

A word is a section of string delimited by spaces/tabs or the start/end of the
string. If a word has a single letter, it must be capitalized.

A letter is a character in the set [a-zA-Z]

If there are no parameters, display \n. 

Examples:

$> ./rstr_capitalizer | cat -e
$
$> ./rstr_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A firsT littlE tesT$
$> ./rstr_capitalizer "SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
seconD tesT A littlE biT   moaR compleX$
   but... thiS iS noT thaT compleX$
     okay, thiS iS thE lasT 1239809147801 buT noT    thE leasT    T$
$>

*/

#include <unistd.h>
#include <stdio.h>

char to_upper(char c)
{
    if(c >= 'a' && c <= 'z')
        c -= 32;
    return c;
}

char to_lower(char c)
{
    if(c >= 'A' && c <= 'Z')
        c += 32;
    return c;
}

int is_space(char c)
{
    if(c == 32 || (c >= 9 && c <= 13))
        return 1;
    return 0;
}

void    rstr_capitalizer(char *s)
{
    int i = 0;
    char temp;
    while(s[i])
    {
        if(is_space(s[i]) == 0 && (is_space(s[i + 1]) == 0 && s[i + 1]))
            temp = to_lower(s[i]);
        else if(!is_space(s[i]) && (is_space(s[i + 1]) || s[i + 1] == '\0'))
            temp = to_upper(s[i]);
        else    
            temp = s[i];
        write(1, &temp, 1);
        i++;
    }
}

int main(int ac, char **av)
{
    if(ac > 1)
    {
        int i = 1;
        while(av[i])
        {
            rstr_capitalizer(av[i++]);
            if(av[i])
                write(1, "\n", 1);
        }
    }
    write(1, "\n", 1);
    return 0;
}