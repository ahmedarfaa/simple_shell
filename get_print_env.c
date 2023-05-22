#include "main.h"

/**
 * _getenv - E
 * @name: ..
 * Return: ..
 */

char *_getenv(const char *name)
{
	char **env = environ;
	size_t name_len = _strlen(name);

	while (*env != NULL)
	{
		if (_strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
		{
			return (*env + name_len + 1);
		}
			env++;
			}

		return (NULL);
}

/**
 * execute_printenv - E
 * @env: ..
 * @var: ..
 */

void execute_printenv(char **env, char *var)
{
	char *value;
	char **envp;

	if (var != NULL)
	{
		value = _getenv(var);
		if (value != NULL)
		{
			write(STDOUT_FILENO, value, _strlen(value));
			write(STDOUT_FILENO, "\n", 1);
		}
		else
		{
			char error_message[50];

			_sprintf(error_message, "%s: environment variable not found\n", var);
			write(STDERR_FILENO, error_message, _strlen(error_message));
		}
	}
	else
	{
		envp = env;
		while (*envp != NULL)
		{
			write(STDOUT_FILENO, *envp, _strlen(*envp));
			write(STDOUT_FILENO, "\n", 1);
			envp++;
		}
	}
}
