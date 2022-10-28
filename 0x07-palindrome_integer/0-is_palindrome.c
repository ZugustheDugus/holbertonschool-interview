#include "palindrome.h"

/**
 * is_palindrome - Determines if n is palindrome.
 * @n: Number to determine if palindrome.
 *
 * Return: 1 if palindrome, 0 if not.
 */
int is_palindrome(unsigned long n)
{
	unsigned long int reversed = 0;
	int remainder;
	unsigned long int copy_n = n;

	while (copy_n != 0)
	{
		remainder = copy_n % 10;
		reversed = reversed * 10 + remainder;
		copy_n /= 10;
	}

	if (n == reversed)
		return (1);
	return (0);
}