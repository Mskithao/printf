#include <stdio.h>
#include "main.h"
#include <unistd.h>

/**
 * _putchar - function that writes a character.
 *  @a: character to be written.
 *
 *  Return: 1 on success.
 */
int _putchar(char a)
{
	return (write(1, &a, 1));
}

