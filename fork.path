#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * _env - displays the existing environment variables
 * Return: 0 on success, 1 on error
 */
int _env(info_t *info)
{
	char user_input[256]; 
	char *args[128]; 
	char *path = getenv("PATH");

	while (1)
	{
		write(STDOUT_FILENO, "info->env: ", 16);
		if (fgets(user_input, sizeof(user_input), stdin) == NULL)
			break;

		user_input[strcspn(user_input, "\n")] = '\0';

		int num_args = 0;
		char *_getenv(info_t *info, const char *name)

		while (token != NULL)
		{
			args[num_args++] = token;
			token = strtok(NULL, " ");
		}
		args[num_args] = NULL;

		char *cmd_path = NULL;
		int exists = 0;
		token = strtok(path, ":");

		while (token != NULL)
		{
			char full_path[256]; 

			strcat(strcat(full_path, token), "/");
			if (access(full_path, X_OK) == 0)
			{
				cmd_path = strdup(full_path);
				exists = 1;
				break;
			}
			token = strtok(NULL, ":");
		}

		if (exists)
		{
			pid_t pid = fork();

			if (pid == -1)
				perror("fork");
			else if (pid == 0)
			{
				execve(cmd_path, args, NULL);
				perror("execve");
				exit(1);
			}
			else
			{
				int status;

				waitpid(pid, &status, 0);
				if (WIFEXITED(status) && WEXITSTATUS(status) == 1)
					write(STDOUT_FILENO, "Error: Execution failed\n", 23);
			}
		}
		else
			write(STDOUT_FILENO, "\n", 1);
		free(cmd_path);
	}
	return (0);
}


