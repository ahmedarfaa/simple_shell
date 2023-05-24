#include "main.h"


/**
 * execute_clear - this function execute the clear
 *
 */
void execute_clear(void)
{
	system("clear");
}

/**
 * execute_cd - a function that executes the change directory
 * @args: input arguements
 *
 */

void execute_cd(char **args)
{
	char *home = _getenv("HOME");

	if (args[1] == NULL || _strncmp(args[1], "$HOME", 5) == 0)
	{
		chdir(home);
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("cd");
		}
	}
}

/**
 * execute_exit - a function that execute exit
 * @args: input args
 * @status: status input
 */
void execute_exit(char **args, int status)
{
	if (args[1] != NULL)
	{
		int exit_code = _atoi(args[1]);

		exit(exit_code);
	}
	else
	{
		char exit_status[10];

		_sprintf(exit_status, "%d", WEXITSTATUS(status));
		exit(_atoi(exit_status));
	}
}
