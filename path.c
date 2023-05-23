#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

/**
 * path_handle - handle the path
 * fork must not be called if the command doesn’t exist
 * Return: 0
 */

int path_handle(void)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *dir = strtok(path_copy, ":");
	char *command = "ls";
	int found = 0;

	while (dir != NULL)
	{
		char full_path[1024];

		snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
		if (access(full_path, X_OK) == 0)
		{
			found = 1;
			break;
		}
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	if (found)
	{
		pid_t pid = fork();

		if (pid == 0)
		{
			execlp(command, command, NULL);
			exit(0);
		}
		else
		{
			wait(NULL);
		}
	}
	else
	{
		printf("%s: command not found\n", command);
	}
}
