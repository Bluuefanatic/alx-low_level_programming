#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * Check_Elf - this will check if it is an Elf file
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
 * print_class - prints class of an Elf header
 * @e_ident: a pointer to an array that contains the Elf class
 */
void print_class(unsigned char *e_ident)
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
	case ELFCLASSONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EL_CLASS]);
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
			printf("2's cpmplement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_version - Prints the version of an Elf haeder
 * @e_ident: a pointer to an array containing the Elf version
 */

