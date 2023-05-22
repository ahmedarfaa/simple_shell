#include "main.h"

/**
 * execute_setenv - E
 * @args: ..
 */
void execute_setenv(char **args)
{
	_setenv(&environ, args[1], args[2]);
}
/**
 * execute_unsetenv - E
 * @args: ..
 */
void execute_unsetenv(char **args)
{
	int name_l, i, j;
	char err_message[50];

	if (args[1] == NULL)
	{
	const char *error_message = "Usage: unsetenv VARIABLE\n";

	write(STDERR_FILENO, error_message, _strlen(error_message));
	return;
	}

	name_l = _strlen(args[1]);
	for (i = 0; environ[i] != NULL; i++)
	{
	if (_strncmp(environ[i], args[1], name_l) == 0 && environ[i][name_l] == '=')
	{
	free(environ[i]);
	for (j = i; environ[j + 1] != NULL; j++)
	{
	environ[j] = environ[j + 1];
	}
	environ[j] = NULL;
	return;
	}
	}

	_sprintf(err_message, "Variable %s not found\n", args[1]);
	write(STDERR_FILENO, err_message, _strlen(err_message));
}
