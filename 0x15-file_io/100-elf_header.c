#include "main.h"

/**
 * print_error - Prints an error message to stderr and exits with status 98.
 * @msg: The error message to print.
 *
 * Return: None.
 */
void print_error(const char *msg)
{
	fprintf(stderr, "Error: %s\n", msg);
	exit(98);
}

/**
 * print_elf_header - Prints the information in the ELF header.
 * @header: A pointer to the ELF header structure.
 *
 * Return: None.
 */
void print_elf_header(Elf64_Ehdr *header)
{
	printf("ELF Header:\n");
       	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", header->e_ident[i]);
	}
	printf("\n");
	printf("  Class:                             %s\n",
			(header->e_ident[EI_CLASS] == ELFCLASS64) ? "ELF64" : "ELF32");
	printf("  Data:                              %s\n",
			(header->e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" : "Unknown");
	printf("  Version:                           %d (current)\n",
			header->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n",
			(header->e_ident[EI_OSABI] == ELFOSABI_SYSV) ? "UNIX - System V" : "Unknown");
	printf("  ABI Version:                       %d\n",
			header->e_ident[EI_ABIVERSION]);
	printf("  Type:                              %s\n",
			(header->e_type == ET_EXEC) ? "EXEC (Executable file)" : "Unknown");
	printf("  Entry point address:               0x%lx\n", header->e_entry);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		print_error("Usage: elf_header elf_filename");
	}

	int fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		print_error("Unable to open file");
	}

	Elf64_Ehdr header;
	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		print_error("Unable to read ELF header");
	}

	if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0)
	{
		print_error("Not an ELF file");
	}

	print_elf_header(&header);
	close(fd);
	return (0);
}

