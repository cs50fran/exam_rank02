/*

Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);

*/

#include <stdio.h>
#include <stdlib.h>



int	ft_atoi(const char *str)
{
	int store = 0;
	int neg = 1;
	int i = 0;

	while(str[i] == ' ' || str[i] == '\t')
		i++;
	if(str[i] == '-' || str[i] == '+')
	{
		if(str[i++] == '-')
			neg = -1;
	}
	while(str[i] >= '0' && str[i] <= '9')
		store = store * 10 + str[i++] - '0';
	return (store * neg);
}

int main(void)
{
    const char *tests[] = {
        "42",
        "-42",
        "0",
        "123456",
        "-98765",
        "   123",        // leading whitespace
        "   -456",       // leading whitespace + sign
        "+789",          // explicit plus sign
        "2147483647",    // INT_MAX
        "-2147483648",   // INT_MIN
        "2147483648",    // overflow (undefined behavior)
        "-2147483649",   // underflow (undefined behavior)
        "123abc",        // stops at first non-digit
        "abc123",        // no valid conversion
        "",              // empty string
        "   ",           // whitespace only
        "+",             // sign only
        "-",             // sign only
        "00123",         // leading zeros
        "12 34"          // stops at space
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < num_tests; i++)
    {
        int result = ft_atoi(tests[i]);
        printf("Test %2d: atoi(\"%s\") = %d\n", i + 1, tests[i], result);
    }

    return 0;
}

/* int main(int ac, char **av)
{
	if (ac == 2)
	{
		char* i = av[1];
		printf("Original: %d\n", atoi(i));
		printf("ft_atoi!: %d\n", ft_atoi(i));
	}
} */