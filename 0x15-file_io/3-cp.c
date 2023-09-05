#include "main.h"

char *make_buffer(char *file);
void close_file(int fd);

/**
 * make_buffer - allocates 1024 bytes for a buffer
 * @file: Name of the file buffer is storing chars
 * Return: A pointer to the newly allocated buffer
 */

char *make_buffer(char *file)
{
	char *huffer;

	huffer = malloc(sizeof(char) * 1024);

	if (huffer == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", file);
		exit(99);
	}
	return (huffer);
}

/**
 * close_file - closes file descriptors
 * @fd: File desciptor to be closed
 */

void close_file(int fd)
{
	int d;

	d = close(fd);
	if (d == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the content of a file to another file
 * @argc: number of arguments supplied
 * @argv: array of pointers.
 * Return: 0 on success.
 * if argc is incorrect - exit code is 97
 * if file_from does not exist - exit code is 98
 * if file_to cannot be crreated - exit code is 99
 * if file_to or file_from cannot be closed - exit code is 100
 */

int main(int argc, char *argv[])
{
	int form, tee, r, w;
	char *cute;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	cute = make_buffer(argv[2]);
	form = open(argv[1], O_RDONLY);
	r = read(form, cute, 1024);
	tee = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do{
		if (form == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n", argv[1]);
			free(cute);
			exit(98);
		}

		w = write(tee, cute, r);
		if (tee == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", argv[2]);
			free(cute);
			exit(99);
		}

		r = read(form, cute, 1024);
		tee = open(argv[2], O_WRONLY | O_APPEND);
	}
	while (r > 0);

	free(cute);
	close_file(form);
	close_file(tee);

	return (0);
}
