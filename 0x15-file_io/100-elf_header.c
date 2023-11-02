/*
 * File: 100-elf_header.c
 * Auth: Jole Iziren
 */

#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * check_elf - Checks if the provided file is an ELF file
 * @e_ident: a pointer to an array that contains Elf magic numbers
 *
 * Description: if it is not an Elf file - exit code 98
 */
void check_elf(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_ident[index] != 127 &&
				e_ident[index] != 'E' &&
				e_ident[index] != 'L' &&
				e_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an Elf file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - prints magic of an Elf header
 * @e_ident: a pointer to an array that contains the Elf class
 */
void print_magic(unsigned char *e_ident)
{
	int index;

	printf("  Magic:   ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - prints the class of Elf header
 * @e_ident: a pointer to an array that contains Elf class
 */
void print_class(unsigned char *e_ident)
{
	printf("  Class:                         ");

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
 * print_data - prints the data of an Elf header
 * @e_ident: a pointer to an array that contains an Elf class
 */
void print_data(unsigned char *e_ident)
{
	printf("  Data:                        ");

	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_version - Prints the version of an Elf haeder
 * @e_ident: a pointer to an array containing the Elf version
 */
void print_version(unsigned char *e_ident)
{
	printf("  Version:                                 %d",
			e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (1\n");
			break;
		default:
			printf("\n");
			break;
	}
}

/**
 * print_abi - prints the ABI version of an ELF header
 * @e_ident: a pointer to an array containing the Elf ABI version
 */
void print_abi(unsigned char *e_ident)
{
	printf("   ABI Version:                 %d\n",
			e_ident[EI_ABIVERSION]);
}

/**
 * print_osabi - prints the OS/ABI of an Elf header
 * @e_ident: a pointer to an array that contains the Elf version
 */
void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                              ");

	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("Unknown\n");
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
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_type - prints the type of an Elf header
 * @e_type: the Elf type
 * @e_ident: a pointer to an array that contains the Elf class
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                             ");

	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("(EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - to print the entry of an Elf header
 * @e_entry: the address of the Elf entry point
 * @e_ident: a pointer to an array that contains the Elf class
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("Entry point address:            0x%lx\n", e_entry);

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#lx\n", e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - closes an Elf file
 * @elf: the file description of the Elf file
 *
 * Description: if the file cannot be closed - exit code 98
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - display the info that is in the Elf header at the start of an Elf fil
 * @argc: the number of arguments supplied to the program
 * @argv: an array of pointers to the arguments
 *
 * Return: 0 on success
 *
 * Descripton: if the file is not an Elf file - exit code 98
 */
int main(int argc, char *argv[])
{
	int o = open(argv[1], O_RDONLY);
	ssize_t r;
	Elf64_Ehdr *header;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <elf_filename>\n", argv[0]);
		return (1);
	}

	if (o == -1)
	{
		perror("Error opening file");
		return (1);
	}

	header = malloc(sizeof(Elf64_Ehdr));

	if (header == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: can't allocate memory for header\n");
		exit(98);
	}

	r = read(o, header, sizeof(Elf64_Ehdr));

	if (r == -1)
	{
		free(header);
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: '%s': no such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type,
			header->e_ident);
	print_entry(header->e_entry,
			header->e_ident);

	free(header);
	close_elf(o);

	return (0);
}
