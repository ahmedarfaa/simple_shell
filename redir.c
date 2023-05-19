#include "main.h"

/**
 * execute_command_with_redirection - E
 * @args: ..
 * @full_path: ..
 * @env: ..
 */

void execute_command_with_redirection(char **args, char *full_path, char **env)
{
	int i;
	int input_fd, output_fd;
	bool has_input_redirection = false;
	bool has_output_redirection = false;

	for (i = 0; args[i] != NULL; i++)
	{
		if (_strcmp(args[i], "<") == 0)
		{
			has_input_redirection = true;
			input_fd = open(args[i + 1], O_RDONLY);
		if (input_fd == -1)
		{
			perror("open");
			exit(1);
		}
		if (dup2(input_fd, STDIN_FILENO) == -1)
		{
			perror("dup2");
			exit(1);
		}
			close(input_fd);
			args[i] = NULL;
			break;
		}
	}

	for (i = 0; args[i] != NULL; i++)
	{
		if (_strcmp(args[i], ">") == 0)
		{
			has_output_redirection = true;
			output_fd = open(args[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (output_fd == -1)
		{
			perror("open");
			exit(1);
		}
		if (dup2(output_fd, STDOUT_FILENO) == -1)
		{
			perror("dup2");
			exit(1);
		}
			close(output_fd);
			args[i] = NULL;
			break;
		}
	}

	if (has_input_redirection || has_output_redirection)
	{
		if (execve(full_path, args, env) == -1)
		{
			perror("execve");
			exit(1);
		}
	}
	else
	{
		if (execve(full_path, args, env) == -1)
		{
			perror("execve");
			exit(1);
		}
		}
}
