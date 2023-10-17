#include "shell.h"

/**
 * custom_exit - Exits the shell
 * @param_count: Number of parameters
 * @arg_array: Array containing command-line arguments
 * @envp: Array of environment variables
 *  Returns: Terminates with a specified exit condition*/
int main(int argc, char **argv, char **envp)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    char **args = NULL;
    int status = 0;

    /* Ignore the arguments */
    (void)argc;
    (void)argv;

    /* Print the prompt and wait for user input */
    signal(SIGINT, signal_handler); /* Handle Ctrl+C */
    while (1)
    {
        write(STDOUT_FILENO, "537sh$ ", 7);
        fflush(stdout);
        nread = getline(&line, &len, stdin);
        if (nread == -1) /* Handle Ctrl+D or error */
        {
            if (errno)
                perror("getline");
            else
                write(STDOUT_FILENO, "\n", 1);
            break;
        }
        line[nread - 1] = '\0'; /* Remove the newline character */

        /* Parse the line into arguments */
        args = split_line(line);
        if (args == NULL)
            continue;

        /* Execute the command with the arguments */
        status = execute_command(args, envp);

        /* Free the memory allocated for the arguments */
       arg_array = info->argv ;
    }

    /* Free the memory allocated for the line */
    free(line);

    return (0);
}

