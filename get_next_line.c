/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 12:15:00 by abarnett          #+#    #+#             */
/*   Updated: 2018/06/27 20:17:08 by marvin           ###   ########.fr       */
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
	if (!head)
	{
		ft_putstr("no head\n");
		head = ft_lstnew(new_file(fd), sizeof(t_file *));
		BUF(head) = ft_strnew(BUFF_SIZE);
	}
	if (!head->content)
	{
		ft_putstr("no head->content\n");
		head->content = new_file(fd);
		BUF(head) = ft_strnew(BUFF_SIZE);
		head->content_size = sizeof(t_file *);
	}
	while (head && head->content)
	{
		if (FD(head) == fd)
			return (head);
		if (!head->next)
		{
			head->next = ft_lstnew(new_file(fd), sizeof(t_file *));
			BUF(head->next) = ft_strnew(BUFF_SIZE);
		}
		head = head->next;
	}
	return (0);
}

char	*strextend(char *buf)
{
	char	*new;

	new = ft_strnew(ft_strlen(buf) + BUFF_SIZE);
	if (!new)
		return (0);
	new = ft_strncpy(new, buf, ft_strlen(buf));
	return (new);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*head;
	t_list			*cur;
	int				ret;

	if (fd < 0)
		return (-1);
	if (!head)
		head = get_fd(0, fd);
	cur = get_fd(head, fd);
	if (!line || !cur || !cur->content || !BUF(cur))
		return (-1);
	ret = 1;
	while (!ft_strchr(BUF(cur), '\n') && ret > 0)
	{
		if (!(ft_strlen(BUF(cur)) % BUFF_SIZE))
			BUF(cur) = strextend(BUF(cur));
		ret = read(fd, (BUF(cur) + ft_strlen(BUF(cur))), (BUFF_SIZE - (ft_strlen(BUF(cur)) % BUFF_SIZE)));
		ft_putstr("ret: ");
		ft_putnbr(ret);
		ft_putchar('\n');
		if (ret == -1)
			return (-1);
	}
	if (!ft_strchr(BUF(cur), '\n') && !ret)
	{
		*line = ft_strnew(ft_strlen(BUF(cur)));
		*line = ft_strncpy(*line, BUF(cur), ft_strlen(BUF(cur)));
		return (0);
	}
	else
		*line = ft_strnew(ft_strchr(BUF(cur), '\n') - BUF(cur));
	if (!*line)
		return (-1);
	*line = ft_strncpy(*line, BUF(cur), ft_strchr(BUF(cur), '\n') - BUF(cur));
	BUF(cur) = ft_strsub(BUF(cur), ft_strchr(BUF(cur), '\n') - BUF(cur) + 1, BUFF_SIZE);
	if (!ret)
		return (0);
	return (1);
}
