#include "main.h"

/**
 * read_textfile - Reads and prints a text file to the POSIX standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters it should read and print.
 *
 * Return: The actual number of letters it could read and print. If an error
 * occurs or the file cannot be opened, read, or written to STDOUT,
 * return 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file;
	char *buffer;
	ssize_t bytes_read;
	ssize_t bytes_written;

	if (filename == NULL)
		return (0);

	file = open(filename, O_RDONLY);

	if (file == -1)
		return (0);

	buffer = malloc(letters);

	if (buffer == NULL)
	{
		close(file);
		return (0);
	}

	bytes_read = read(file, buffer, letters);

	if (bytes_read == -1)
	{
		close(file);
		free(buffer);
		return (0);
	}
	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

	if (bytes_written == -1 || bytes_written != bytes_read)
	{
		close(file);
		free(buffer);
		return (0);
	}
	close(file);
	free(buffer);
	return (bytes_written);
}

