#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/**
 * create_file - Creates a file and writes text content to it.
 * @filename: Name of the file to create
 * @text_content: NULL terminated string to write to the filr.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		ssize_t bytesWritten = write(fd, text_content, strlen(text_content));

		if (bytesWritten == -1)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
