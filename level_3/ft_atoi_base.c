/*

Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);

*/

#include <stdio.h>

char to_lower(char c)
{
    if(c >= 'A' && c <= 'Z')
        c += 32;
    return c;
}

int char_to_digit(char c, int str_base)
{
    c = to_lower(c);
    char *base = "0123456789abcdef";
    int i = 0;
    while(i < str_base)
    {
        if(c == base[i])
            return i;
        i++;
    }
    return -1;
}

int	ft_atoi_base(const char *str, int str_base)
{
    int neg = 1;
    int i = 0;
    int digit = 0;
    int result = 0;

    if(str[i] == '-')
    {
        neg = -1;
        i++;
    }

    while(str[i])
    {
        digit = char_to_digit(str[i], str_base);
        if(digit == -1)
            return result;
        result = result * str_base + digit;
        i++;
    }
    return result * neg;
}

#include <stdio.h>

int ft_atoi_base(const char *str, int str_base);

int main(void)
{
    printf("Binary:\n");
    printf("1011 (base 2) = %d\n", ft_atoi_base("1011", 2));     // 11
    printf("-1011 (base 2) = %d\n", ft_atoi_base("-1011", 2));   // -11

    printf("\nDecimal:\n");
    printf("42 (base 10) = %d\n", ft_atoi_base("42", 10));       // 42
    printf("-42 (base 10) = %d\n", ft_atoi_base("-42", 10));     // -42

    printf("\nHexadecimal:\n");
    printf("2f (base 16) = %d\n", ft_atoi_base("2f", 16));       // 47
    printf("2F (base 16) = %d\n", ft_atoi_base("2F", 16));       // 47
    printf("-FF (base 16) = %d\n", ft_atoi_base("-FF", 16));     // -255

    printf("\nOther bases:\n");
    printf("123 (base 4) = %d\n", ft_atoi_base("123", 4));       // 27
    printf("777 (base 8) = %d\n", ft_atoi_base("777", 8));       // 511

    printf("\nInvalid / partial:\n");
    printf("12fg (base 16) = %d\n", ft_atoi_base("12fg", 16));   // stops at g
    printf("19 (base 8) = %d\n", ft_atoi_base("19", 8));         // stops at 9

    return 0;
}
