#include "shell.h"

/**
 * print_prompt - prints prompt display to
 * recive input and execute
 * @av : command line argument
 * @env : enviroment variable
 * Return: pid of terminated process
 */
void print_prompt(char **av, char **env)
{
	char *string = NULL;
	int status, j = 0;
	ssize_t char_num;
	char *argv[] = {NULL, NULL};
	pid_t child_id;
	size_t n = 0;

	while (1)
	{
		write(STDIN_FILENO, "#cisfun$ ", 9);

		char_num = getline(&string, &n, stdin);
		if (char_num == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		j = 0;
		while (string[j])
		{
			if (string[j] == '\n')
				string[j] = 0;
			j++;
		}
		argv[0] = string;
		child_id = fork();
		if (child_id == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		if (child_id == 0)
		{
			if (execve(argv[0], argv, env) == -1)
				printf("%s: No such file or directory\n", av[0]);
		}
		else
		wait(&status);
	}
}
