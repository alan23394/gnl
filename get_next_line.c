#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	if (!fd || !line)
		return (-1);
	read(fd, *line, BUFF_SIZE);
	return (0);
}
