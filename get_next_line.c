/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 12:15:00 by abarnett          #+#    #+#             */
/*   Updated: 2018/07/14 17:51:56 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_file	*new_file(int fd)
{
	t_file	*file;

	file = (t_file *)ft_memalloc(sizeof(t_file));
	if (!file)
		return (0);
	file->fd = fd;
	file->buf = 0;
	return (file);
}

t_list	*get_fd(t_list *head, int fd)
{
	t_file	*file;

	if (!head)
	{
		file = new_file(fd);
		head = ft_lstnew(file, sizeof(t_file));
		if (head && head->content)
			BUF(head) = ft_strnew(BUFF_SIZE);
		ft_memdel((void **)&file);
	}
	while (head && head->content)
	{
		if (FD(head) == fd)
			return (head);
		if (!head->next)
		{
			file = new_file(fd);
			head->next = ft_lstnew(file, sizeof(t_file));
			if (head->next && head->next->content)
				BUF(head->next) = ft_strnew(BUFF_SIZE);
			ft_memdel((void **)&file);
		}
		head = head->next;
	}
	return (0);
}

char	*stresize(char **buf, int start, size_t size)
{
	char	*new;

	new = ft_strnew(ft_strlen(*buf + start) + size);
	if (!new)
		return (0);
	new = ft_strncpy(new, *buf + start, ft_strlen(*buf + start));
	ft_strdel(buf);
	return (new);
}

int		process_line(t_list *cur, int ret, char **line)
{
	if (!ft_strchr(BUF(cur), '\n') && !ret)
	{
		*line = stresize(&BUF(cur), 0, 0);
		if (!*line)
			return (-1);
		if (!**line)
			return (0);
		return (1);
	}
	else
		*line = ft_strnew(ft_strchr(BUF(cur), '\n') - BUF(cur));
	if (!*line)
		return (-1);
	*line = ft_strncpy(*line, BUF(cur), ft_strchr(BUF(cur), '\n') - BUF(cur));
	BUF(cur) = stresize(&BUF(cur), ft_strchr(BUF(cur), '\n') - BUF(cur) + 1, 0);
	if (!*line || !BUF(cur))
		return (-1);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*head;
	t_list			*cur;
	int				ret;

	if (read(fd, 0, 0) == -1 || !line)
		return (-1);
	if (!head && !(head = get_fd(0, fd)))
		return (-1);
	if (!(cur = get_fd(head, fd)))
		return (-1);
	if (!BUF(cur))
		return (0);
	ret = 1;
	while (!ft_strchr(BUF(cur), '\n') && ret > 0)
	{
		BUF(cur) = stresize(&BUF(cur), 0, BUFF_SIZE);
		if (!BUF(cur))
			return (-1);
		ret = read(fd, (BUF(cur) + ft_strlen(BUF(cur))), BUFF_SIZE);
		if (ret < 0)
			return (-1);
	}
	return (process_line(cur, ret, line));
}
