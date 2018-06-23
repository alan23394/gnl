#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>

# define BUFF_SIZE 1024

int		get_next_line(const int fd, char **line);

#endif
