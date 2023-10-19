#include "monty.h"

/**
 * main - entry point for the Monty Bytecode Interpreter
 * @argc: number of command-line arguments
 * @argv: array of command-line argument strings
 *
 * Return: 0 on success, EXIT_FAILURE on failure
 */

int main(int argc, char *argv[])
{
	unsigned int line_num = 1; /* Line number in Monty bytecode file */
	char *token = NULL, *buffer = malloc(sizeof(char) * 10000); /* Token and buffer for file */
	int fd = open(argv[1], O_RDONLY), ispush = 0; /* File descriptor and push flag */
	ssize_t reader = read(fd, buffer, 10000); /* Number of bytes read from file */
	stack_t *h = NULL; /* Stack data structure */

	if (argc != 2 || argv[1] == NULL)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		close(fd);
		exit(EXIT_FAILURE);
	}
	if (!buffer)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (reader == -1)
	{
		free(buffer);
		close(fd);
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, "\n\t\a\r ;:"); /* Tokenize the input buffer */
	while (token != NULL)
	{
		if (ispush == 1)
		{
			push(&h, line_num, token);
			ispush = 0;
			token = strtok(NULL, "\n\t\a\r ;:");
			line_num++;
			continue;
		}
		else if (strcmp(token, "push") == 0)
		{
			ispush = 1;
			token = strtok(NULL, "\n\t\a\r ;:");
			continue;
		}
		else
		{
			if (execute(token) != 0)
			{
				execute(token)(&h, line_num);
			}
			else
			{
				free_list(&h);
				fprintf(stderr, "L%u: unknown instruction %s\n", line_num, token);
				exit(EXIT_FAILURE);
			}
		}
		line_num++;
		token = strtok(NULL, "\n\t\a\r ;:");
	}
	free_list(&h);
	free(buffer);
	close(fd);
	return (0);
}
