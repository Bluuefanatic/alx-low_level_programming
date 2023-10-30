#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

ssize_t read_textfile(const char *filename, size_t letters) {
    int fd;
    char *buffer;
    ssize_t bytesRead, bytesWritten;

    if (filename == NULL)
        return 0;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return 0;

    buffer = malloc(letters);
    if (buffer == NULL) {
        close(fd);
        return 0;
    }

    bytesRead = read(fd, buffer, letters);
    if (bytesRead == -1) {
        free(buffer);
        close(fd);
        return 0;
    }

    bytesWritten = write(STDOUT_FILENO, buffer, bytesRead);
    free(buffer);
    close(fd);

    if (bytesRead == bytesWritten)
        return bytesRead;
    else
        return 0;
}
