#include "shell.h"

/**
 * _memset- fills memory with constant bytes
 * @s: chararacter
 * @b: character
 * @n: unsigned integer
 *
 * Return: bytes character
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}

/**
 * _memcpy - copies memory area
 * @dest: destination
 * @src: source
 * @n: amount of bytes
 *
 * Return: a pointer to the address of the copied memory (dest)
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * _realloc - resizes an allocated memory
 * @ptr: memory location to resize
 * @size: the new size of the memory
 *
 * Description: creates a new memory location with size and
 * copies the content of the previous memory to it before freeing it.
 *
 * Return: void
*/
void *_realloc(void *ptr, size_t size)
{
	void *new_mem;

	if (ptr == NULL)
		return (malloc(size));

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}

	new_mem = malloc(size);
	if (new_mem == NULL)
		return (NULL);

	/*Reset garbage values and copy data to new memory location*/
	_memset(new_mem, 0, size);
	_memcpy(new_mem, ptr, size);

	free(ptr);
	return (new_mem);
}
