#include "main.h"
#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

int
create_file(const char *filename, char *text_content)
{
	int fd1, w;

	if (!filename)
		return (-1);
	fd1 = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (text_content == NULL)
	{
		write(fd1, "", 0);
		close(fd1);
		return (1);
	}
	w = write(fd1, text_content, strlen(text_content));
	if ((fd1 < 0) | (w < 0))
		return (-1);
	close(fd1);
	return (1);
}