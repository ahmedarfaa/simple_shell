#include "main.h"


/**
 * execute_clear - E
 *
 */
void execute_clear(void)
{
	system("clear");
}

/**
 * execute_cd -E
 * @args: ..
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
 * execute_exit - E
 * @args: ..
 *
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
