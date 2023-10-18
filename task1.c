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

        // Function declaration
        char** split_line(const char* line);
        if (args == NULL)
            continue;

        /* Execute the command with the arguments */
        int execute_command(char **args, char **envp);

        if (execve(args[0], args, envp) == -1) {
            perror("execve");
            return -1;
       
       
        /* Free the memory allocated for the arguments */
       arg_array = info->argv ;
    }

    /* Free the memory allocated for the line */
    free(line);

    return (0);
}

