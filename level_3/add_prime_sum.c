/*

Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>

*/

#include <unistd.h>
#include <stdio.h>

int is_prime(int n)
{
    int i = 2;

    if (n == 1)
        return 0;
    while(i < n)
    {
        if(n % i == 0)
            return 0;
        i++;
    }
    return 1;
}

int ft_atoi(char *str)
{
    int i = 0;
    int neg = 1;
    int result;

    while(str[i] == ' ')
        i++;
    if(str[i] == '+' || str[i] == '-')
    {
        if(str[i] == '-')
            neg = -1;
        i++;
    }
   
    while(str[i] >= '0' && str[i] <= '9')
        result = result * 10 + (str[i++] - '0');
    return result * neg;
}

int add_prime_sum(int n)
{
    int i = 1;
    int result = 0;

    while(i <= n)
    {
        if(is_prime(i))
            result += i;
        i++;
    }
    return result;
}

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(int n)
{
    if(n >= 10)
        ft_putnbr(n / 10);
    ft_putchar(n % 10 + '0');
}

int main(int ac, char **av)
{
    if (ac == 2)
        ft_putnbr(add_prime_sum(ft_atoi(av[1])));
    write(1, "\n", 1);
}