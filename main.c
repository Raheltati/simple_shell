#include "shell.h"

/**
 * main - entry point
 * @ac : number of command line arguments
 * @av : additional command line arguments
 * @env : environment variables
 * Return: 0
 */
int main(int ac, char **av, char **env)
{
	if (ac == 1)
	{
		print_prompt(av, env);
	}
	return (0);
}
