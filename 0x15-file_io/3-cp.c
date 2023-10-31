#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFSIZE 1024

/**
 * print_error_and_exit - Prints an error message and exits the program.
 *
 * @exit_code: The exit code to be used when exiting.
 * @message: The error message to be printed.
 * @file_name: The name of the file associated with the error.
 * @fd: The file descriptor (if applicable) associated with the error.
 *
 * Return: None
 */
void print_error_and_exit(int exit_code, const char *message,
		const char *file_name, int fd);

/**
 * main - Entry point of the program.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Return: Returns 0 on successful execution, or a non-zero value on error.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t bytes_read, bytes_written;
	char buffer[BUFSIZE];

	/* Check if the correct number of arguments is provided */
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	/* Open the source file for reading */
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	/* Open or create the destination file for writing */
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	/* Copy data from source to destination */
	while ((bytes_read = read(fd_from, buffer, BUFSIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
		{
			print_error_and_exit(99, "Error: Can't write to %s\n", argv[2], fd_from);
		}
	}

	/* Check for read error */
	if (bytes_read == -1)
	{
		print_error_and_exit(98, "Error: Can't read from file %s\n",
							 argv[1], fd_from);
	}

	/* Close file descriptors */
	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd \n");
		exit(100);
	}

	return (0);
}

/**
 * print_error_and_exit - Prints an error message and exits the program.
 *
 * @exit_code: The exit code to be used when exiting
 * @message: The error message to be printed
 * @file_name: The name of the file associated with the error
 * @fd: The file descriptor (if applicable) associated with the error
 *
 * Return: None
 */
void print_error_and_exit(int exit_code, const char *message,
						  const char *file_name, int fd)
{
	dprintf(STDERR_FILENO, message, file_name);
	if (fd != -1)
		close(fd);
	exit(exit_code);
}
