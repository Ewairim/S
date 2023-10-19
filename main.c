#include "shell.h"

/**
 * main - simple-shell
 *
 * Return: always 0
 */
int main(void)
{
	char *input;
	ssize_t bytes;
	size_t len;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		bytes = getline(&input, &len, stdin);
		if (bytes == -1)
		{
			exit(54);
		}
	}
	return (0);
}
