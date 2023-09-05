#include "main.h"

/**
 * check_elf - checks if it is an elf file
 * @e_ident: pointer to array that contains elf numbers
 * If file is not ELF file - exit code 98
 */

void check_elf(unsigned char *e_ident)
{
	int ind;

	for (ind = 0; ind < 4; ind++)
	{
		if (e_ident[ind] != 127 &&
				e_ident[ind] != 'E' &&
				e_ident[ind] != 'L' &&
				e_ident[ind] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not ELF file\n");
			exit(98);
		}
	}
}
/**
 * print_magic - Prints magic numbers of elf header
 * @e_ident: pointer to array that contains elf numbers
 * Magic numbers are separated by spaces.
 */

void print_magic(unsigned char *e_ident)
{
	int ind;

	printf(" MAGIC: ");
	for (ind = 0; ind < EI_NIDENT; ind++)
	{
		printf("%02x", e_ident[ind]);

		if (ind == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - class of an elf header
 * @e_ident: pointer to array that contains elf class
 */

void print_class(unsigned char *e_ident)
{
	printf(" CLASS: ");

	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;

		case ELFCLASS32:
			printf("ELF32\n");
			break;

		case ELFCLASS64:
			printf("ELF64\n");
			break;

		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_data - Data of an elf header
 * @e_ident: pointer to array that contains elf class
 */

void print_data(unsigned char *e_ident)
{
	printf(" DATA: ");

	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;

		case ELFDATA2LSB:
			printf("2's complement, endian little\n");
			break;

		case ELFDATA2MSB:
			printf("2's complement, endian big");
			break;

		default: printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_version - the version of elf header
 * @e_ident: pointer to array that contain elf version
 */

void print_version(unsigned char *e_ident)
{
	printf(" VERSION: %d", e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;

		default:
			printf("\n");
			break;
	}
}

/**
 * print_abi - the ABI version of elf header
 * @e_ident: pointer to array containing elf abi version
 */

void print_abi(unsigned char *e_ident)
{
	printf(" ABI VERSION: %d\n", e_ident[EI_ABIVERSION]);
}


/**
 * print_osabi - prints OS/ABI of elf header
 * @e_ident: pointer to array containing elf version
 */

void print_osabi(unsigned char *e_ident)
{
	printf(" OS/ABI: ");

	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;

		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;

		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;


		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;

		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;

		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;

		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;

		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;

		case ELFOSABI_ARM:
			printf("ARM\n");
			break;

		case ELFOSABI_STANDALONE:
			printf("Standalone APP\n");
			break;

		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_type - prints type of elf header
 * @e_type: elf type
 * @e_ident: pointer to array containing elf class
 */

void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)

		e_type >>= 8;
	printf(" TYPE: ");

	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;

		case ET_REL:
			printf("REL (Relocatable FILE)\n");
			break;

		case ET_EXEC:
			printf("EXEC (Executable FILE)\n");
			break;

		case ET_DYN:
			printf("DYN (Shared Object FILE)\n");
			break;

		case ET_CORE:
			printf("CORE (core FILE)\n");
			break;

		default:
			printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - entry point of elf header
 * @e_entry: address of elf entry point
 * @e_ident: pointer to array containing elf class
 */

void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf(" ENTRY POINT ADDRESS: ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			((e_entry >> 8) & 0XFF00FF);
		e_entry = (e_entry << 16 ) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - closes an elf file
 * @elf: file descriptor of elf file
 * If file cannot close - exit code 98
 */

void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - shows information conntained in elf file from the start
 * @argc: number of arguments
 * @argv: array of pointers to argument
 * Return: 0 (success)
 * if file is not elf file or function fails - exit code 98
 */

int main(int __attribute__((__unused__))argc, char *argv[])
{
	Elf64_Ehdr *head;
	int p,k;

	p = open(argv[1], O_RDONLY);

	if (p == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	head = malloc(sizeof(Elf64_Ehdr));
	if (head == NULL)
	{
		close_elf(p);

		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	k = read(p, head, sizeof(Elf64_Ehdr));
	if (k == -1)
	{
		free(head);
		close_elf(p);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(head->e_ident);
	printf("ELF HEADER:\n");
	print_magic(head->e_ident);
	print_class(head->e_ident);
	print_data(head->e_ident);
	print_version(head->e_ident);
	print_abi(head->e_ident);
	print_osabi(head->e_ident);
	print_type(head->e_type, head->e_ident);
	print_entry(head->e_entry, head->e_ident);

	free(head);
	close_elf(p);

	return (0);
}
