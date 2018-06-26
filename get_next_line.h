#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include "libft.h"

# define BUFF_SIZE 16
# define FD(cur) (((t_file *)(cur->content))->fd)
# define BUF(cur) (((t_file *)(cur->content))->buf)

typedef struct	s_file
{
	int			fd;
	char		*buf;
}				t_file;

t_file	*new_file(int fd);
t_list	*get_fd(t_list *head, int fd);
int		get_next_line(const int fd, char **line);

#endif
