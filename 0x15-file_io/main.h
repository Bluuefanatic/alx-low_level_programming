#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>

typedef struct
{
	uint8_t magic[16];
	uint8_t class;
}
ElfHeader;

int is_elf_file(int fd);
int read_elf_header(int fd, ElfHeader *header);
void display_elf_header(const ElfHeader *header);

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

#endif /* MAIN_H */

