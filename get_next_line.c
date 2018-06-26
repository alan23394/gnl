#include "get_next_line.h"

t_file	*new_file(int fd)
{
	t_file *file;

	file = (t_file *)ft_memalloc(sizeof(t_file));
	if (!file)
		return (0);
	file->fd = fd;
	file->buf = ft_strnew(BUFF_SIZE);
	if (!file->buf)
		return (0);
	return (file);
}

t_list	*get_fd(t_list *head, int fd)
{
	if (!head)
	{
		head = ft_lstnew(new_file(fd), sizeof(t_file *));
		ft_bzero(BUF(head), BUFF_SIZE);
	}
	if (!head->content)
	{
		head->content = new_file(fd);
		head->content_size = sizeof(t_file *);
	}
	while (head && head->content)
	{
		if (FD(head) == fd)
			return (head);
		if (!head->next)
			head->next = ft_lstnew(new_file(fd), sizeof(t_file *));
		head = head->next;
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*head = 0;
	t_list			*cur;

	cur = get_fd(head, fd);
	if (!line || !cur)
		return (-1);
	if (!*BUF(cur))
	{
		ft_putstr("reading\n");
		 read(fd, BUF(cur), BUFF_SIZE - 1);
	}
	ft_putnbr(ft_strlen(BUF(cur)));
	ft_putchar('\n');
	ft_putnbr(ft_strlen(*line));
	ft_putchar('\n');
	ft_putnbr(BUFF_SIZE);
	ft_putchar('\n');
	ft_putstr(BUF(cur));
	ft_putchar('\n');
	if (!ft_strchr(BUF(cur), '\n'))
	{
		ft_putstr("before this part\n");
		*line = ft_strcpy(ft_memalloc(ft_strlen(*line) + BUFF_SIZE), *line);
		ft_putstr("after this part\n");
	}
	else
	{
		*line = ft_strsub(BUF(cur), 0, ft_strchr(BUF(cur), '\n') - BUF(cur));
	}
	return (1);
}
