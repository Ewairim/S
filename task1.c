#include "shell.h"

int main(int argc, char **argv, char **envp) {
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    char **args = NULL;

    /* Ignore the arguments */
    (void)argc;
    (void)argv;

    /* Print the prompt and wait for user input */
    signal(SIGINT, signal_handler); /* Handle Ctrl+C */
    while (1) {
        write(STDOUT_FILENO, "537sh$ ", 7);
        fflush(stdout);
        nread = getline(&line, &len, stdin);
        if (nread == -1) { /* Handle Ctrl+D or error */
            if (errno)
                perror("getline");
            else
                write(STDOUT_FILENO, "\n", 1);
            break;
        }
        line[nread - 1] = '\0'; /* Remove the newline character */

        args = split_line(line); /* Split the line into arguments */
        if (args == NULL) {
            continue; // Handle empty input or other errors
        }

        if (execve(args[0], args, envp) == -1) {
            perror("execve");
            free(args);
            return -1;
        }

        free(args); /* Free the memory allocated for the arguments */
    }

    free(line); /* Free the memory allocated for the line */
    return 0;
}
