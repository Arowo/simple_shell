#include "shell.h"

/**
 * _strlen  - Function to calculate the length of a string
 * @str: string
 *
 * Return: length of string
 */
size_t _strlen(const char *str)
{
	size_t length = 0;

	while (str[length] != '\0')
	{
		length++;
	}

	return (length);
}

/**
 * _strchr - searches for the first occurrence of a character in a string
 * @str: string
 * @character: ascii character
 *
 * Return: a pointer to that character within the string
 */
char *_strchr(const char *str, int character)
{
	while (*str != '\0')
	{
		if (*str == character)
		{
			return ((char *)str);
		}
		str++;
	}

	return (NULL);
}

/**
 * _strtok - tokenize (split) a string into substrings
 * based on a delimiter character
 * @str: string
 * @delim: delimeter
 *
 * Return: substrings (token)
 */
char *_strtok(char *str, const char *delim)
{
	static char *lastToken;
	char *endOfToken = NULL;
	char *token = NULL;

	if (str != NULL)
		lastToken = str;

	if (lastToken == NULL)
		return (NULL);

	/*Find the start of the token (skip leading delimeters)*/
	token = lastToken;
	while (*token != '\0' && _strchr(delim, *token) != NULL)
	{
		token++;
	}

	/*If end of the string, there are no more tokens*/
	if (*token == '\0')
	{
		lastToken = NULL;
		return (NULL);
	}

	/*Find the end of the token (find the next delimiter)*/
	endOfToken = token + 1;
	while (*endOfToken != '\0' && _strchr(delim, *endOfToken) == NULL)
	{
		endOfToken++;
	}

	/*Replace delimiter with a null terminator*/
	*endOfToken = '\0';

	/*Update lastToken to point to the next character*/
	lastToken = endOfToken + 1;

	return (token);
}

/**
 * _strcpy - copies string from source to destination
 * @dest: destination
 * @src: source
 *
 * Return: pointer to the start of destination string
 */
char *_strcpy(char *dest, const char *src)
{
	/*Save starting point of dest address*/
	char *dest_start = dest;

	/*Copy char from src to dest*/
	while ((*dest++ = *src++))
		;

	return (dest_start);
}

/**
 * _strdup - duplicates a given string
 * @str: string
 *
 * Return: a new dynamically allocated copy of the string
*/
char *_strdup(const char *str)
{
	size_t len = _strlen(str);
	char *duplicate;

	if (str == NULL)
		return (NULL);

	duplicate = malloc(sizeof(char *) * len + 1);
	if (duplicate == NULL)
		return (NULL);

	/*Copy string into the allocated memory*/
	_strcpy(duplicate, str);

	return (duplicate);
}
