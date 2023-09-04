#include "main.h"

/**
 * check_arguments - Checks if the program arguments are valid.
 * @argc: Number of arguments.
 * @argv: Array of arguments.
 */
void check_arguments(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}
}

/**
 * open_source_file - Opens the source file for reading.
 * @filename: The name of the source file.
 * @permissions: The permissions to use when creating the destination file.
 * @source_fd: A pointer to the source file descriptor.
 */
void open_source_file(const char *filename, mode_t permissions __attribute__((unused)), int *source_fd)
{
	*source_fd = open(filename, O_RDONLY);

	if (*source_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(98);
	}
}

/**
 * open_dest_file - Opens the destination file for writing.
 * @filename: The name of the destination file.
 * @permissions: The permissions to use when creating the destination file.
 * @dest_fd: A pointer to the destination file descriptor.
 */
void open_dest_file(const char *filename, mode_t permissions, int *dest_fd)
{
	*dest_fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, permissions);

	if (*dest_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}
}

/**
 * copy_file_content - Copies content from source to destination file.
 * @source_fd: The source file descriptor.
 * @dest_fd: The destination file descriptor.
 */
void copy_file_content(int source_fd, int dest_fd)
{
	char buffer[BUFSIZE];
	ssize_t read_result, write_result;

	while ((read_result = read(source_fd, buffer, 1024)) > 0)
	{
		write_result = write(dest_fd, buffer, read_result);

		if (write_result == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to destination file\n");
			exit(99);
		}
	}

	if (read_result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from source file\n");
		exit(98);
	}
}

/**
 * close_files - Closes source and destination file descriptors.
 * @source_fd: The source file descriptor.
 * @dest_fd: The destination file descriptor.
 */
void close_files(int source_fd, int dest_fd)
{
	if (close(source_fd) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close source file descriptor %d\n", source_fd);
		exit(100);
	}

	if (close(dest_fd) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close destination file descriptor %d\n", dest_fd);
		exit(100);
	}
}

