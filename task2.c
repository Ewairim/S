#include "shell.h"

/**
 *  int _myinfo - this is a local variable within the main function
 * @argc: Count of Arguments
 * @argv: array of arguments
 * Return: 0 on success, 1 on failure
 */
int _myinfo(info_t data);
{
    char *text_data= NULL;
    char **args = NULL;
    int status = 1;

    /* Check if arguments are valid */
    if (argc != 1)
    {
        write(STDERR_FILENO, "Usage: ./hsh\n", 14);
        return (1);
    }

    /* Loop until EOF or exit */
    while (node)
    {
        /* Print prompt if interactive mode */
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "$ ", 2);

        /* Read a line from stdin */
        line = hsh_getline();

        /* Check for EOF or error */
        if (line == NULL)
            break;

        /* Tokenize the line into arguments */
        args = hsh_tokenizer(line);

        /* Execute the arguments */
        status = hsh_execute(args);

        /* Free memory */
        free(line);
        free(args);
    }

    return (0);
}

