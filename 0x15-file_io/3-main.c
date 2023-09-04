#include "main.h"

/**
 * main - Entry point of the program
 * @argc: The number of command line arguments.
 * @argv: An array of strings containing the command line arguments.
 * Return: 0 on success, or an error code on failure.
 */
int main(int argc, char *argv[])
{
	int source_fd, dest_fd;
	mode_t permissions = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	check_arguments(argc, argv);
	open_source_file(argv[1], permissions, &source_fd);
	open_dest_file(argv[2], permissions, &dest_fd);

	copy_file_content(source_fd, dest_fd);

	close_files(source_fd, dest_fd);

	return (0);
}

