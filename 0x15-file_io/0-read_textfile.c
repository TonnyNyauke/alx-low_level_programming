#include "main.h"

/**
 * read_textfile - Reads and prints the contents of a file to stdout.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The number of letters read and printed, or 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t bytes_read, bytes_written;
	char *buffer;
	/* Check if the filename is NULL */
	if (filename == NULL)
		return (0);

	/* Allocate memory for the buffer */
	buffer = malloc(letters);
	if (buffer == NULL)
		return (0);

	/* Open the file for reading */
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buffer);
		return (0);
	}
	/* Read data from the file into the buffer */
	bytes_read = read(fd, buffer, letters);
	if (bytes_read == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}
	/* Write the data from the buffer to stdout */
	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
	if (bytes_written == -1 || bytes_written != bytes_read)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	/* Cleanup and return the number of bytes written */
	free(buffer);
	close(fd);
	return (bytes_written);
}
