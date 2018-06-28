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
		head->content = new_file(fd);
		BUF(head) = ft_strnew(BUFF_SIZE);
		head->content_size = sizeof(t_file *);
	}
	while (head && head->content)
	{
		if (FD(head) == fd)
		{
			ft_putstr("fd match\n");
			return (head);
		}
		if (!head->next)
			head->next = ft_lstnew(new_file(fd), sizeof(t_file *));
		head = head->next;
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*head;
	t_list			*cur;
	//char			*tmp;

	if (!head)
		head = get_fd(0, fd);
	cur = get_fd(head, fd);
	printf("%p\n", head);
	printf("%p\n", cur);
	ft_putnbr(FD(cur));
	ft_putchar('\n');
	if (!line || !cur)
		return (-1);
	/*
	ft_putstr("how about here?\n");
	tmp = BUF(cur);
	ft_putstr("?\n");
	for (int i = 0; i < BUFF_SIZE; ++i)
	{
		ft_putstr("?\n");
		ft_putchar(*tmp + 48);
		ft_putchar('\n');
		++tmp;
	}
	*/
	if (!BUF(head))
		ft_putstr("no BUF(head)\n");
	printf("%p\n", BUF(cur));
	if (!BUF(cur))
		ft_putstr("no BUF(cur)\n");
	ft_putstr("before buf dereference\n");
	if (!*BUF(cur))
	{
		ft_putstr("reading\n");
		read(fd, BUF(cur), BUFF_SIZE);
	}
	ft_putstr("after buf dereference\n");
	ft_putnbr(ft_strlen(BUF(cur)));
	ft_putchar('\n');
	ft_putnbr(ft_strlen(*line));
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
		printf("%p - %p = ", ft_strchr(BUF(cur), '\n'), BUF(cur));
		printf("%ld\n", ft_strchr(BUF(cur), '\n') - BUF(cur));
		*line = ft_strsub(BUF(cur), 0, ft_strchr(BUF(cur), '\n') - BUF(cur));
	}
		return (1);
	}
