#include "main.h"

/**
 * create_file - Creates a file with specific permissions and writes content.
 * @filename: The name of the file to create.
 * @text_content: A NULL-terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int file, length, write_status;

	if (filename == NULL)
		return (-1);

	file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

	if (file == -1)
		return (-1);

	if (text_content != NULL)
	{
		length = 0;

		while (text_content[length])
			length++;

		write_status = write(file, text_content, length);

		if (write_status == -1)
		{
			close(file);
			return (-1);
		}
	}

	close(file);
	return (1);
}

