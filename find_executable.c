#include "main.h"


/**
 * find_executable - E
 * @fname: input name
 * @env: input enviroment
 * Return: Null
 *
 */
char *find_executable(char *fname, char **env)
{
	char *full_path = NULL;
	char *path_env = NULL;
	char *path = NULL;
	char *token = NULL;
	size_t path_len;
	size_t fname_len;
	int i;

	if (fname[0] == '/')
	{
	if (access(fname, X_OK) == 0)
	{
		full_path = _strdup(fname);
	if (full_path == NULL)
	{
		perror("_strdup");
		exit(127); }
		return (full_path); }
	else
		return (NULL); }
	else if (_strncmp(fname, "./", 2) == 0)
	{
	if (access(fname + 2, X_OK) == 0)
	{
	full_path = _strdup(fname + 2);
	if (full_path == NULL)
	{
		perror("_strdup");
		exit(127); }
		return (full_path); }
	else
		return (NULL); }

	for (i = 0; env[i] != NULL; i++)
	{
	if (_strncmp(env[i], "PATH=", 5) == 0)
	{
		path_env = env[i] + 5;
		break; }}
	if (path_env == NULL)
	{
		const char *error_message = "PATH environment variable not set\n";

		write(STDERR_FILENO, error_message, _strlen(error_message));
		return (NULL); }
		path = _strdup(path_env);
	if (path == NULL)
	{
		perror("_strdup");
		exit(127); }
		token = _stringtok(path, ":");
	while (token != NULL)
	{
		path_len = _strlen(token);
		fname_len = _strlen(fname);
		full_path = malloc(path_len + fname_len + 2);
	if (full_path == NULL)
	{
		perror("malloc");
		free(path);
		exit(127); }
	if (_snprintf(full_path, path_len + fname_len + 2, "%s/%s", token, fname) < 0)
	{
		free(full_path);
		free(path);
		return (NULL); }
	if (access(full_path, X_OK) == 0)
	{
		free(path);
		return (full_path); }
		free(full_path);
		token = _stringtok(NULL, ":"); }
		free(path);
	return (NULL); }
