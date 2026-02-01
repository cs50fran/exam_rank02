/*

Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100  0001
     ||
     \/
 1000  0010

*/

#include <unistd.h>

unsigned char	reverse_bits(unsigned char octet)
{
    unsigned char result = 0;
    int i = 0;

    while (i < 8)
    {
        result <<= 1;
        result |= (octet & 1);
        octet >>= 1;
        i++;
    }
    return result;
}

void	print_bits(unsigned char octet)
{
	int i = 7;
	while (i >= 0) 
	{
		if (octet & (1 << i))
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i--;
	}
}

int main()
{
	char c = 'A';
	print_bits(c);
	write(1, "\n", 1);
	char rev = reverse_bits(c);
	print_bits(rev);
}


	