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
			printf("%s\n", value);
		}
		else
		{
			char error_message[50];

			_sprintf(error_message, "%s: environment variable not found\n", var);
			write(STDERR_FILENO, error_message, strlen(error_message));
		}
	}
	else
	{
		envp = env;
		while (*envp != NULL)
		{
		printf("%s\n", *envp);
		envp++;
		}
	}
}
