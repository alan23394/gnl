/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 12:15:00 by abarnett          #+#    #+#             */
/*   Updated: 2018/06/26 16:07:28 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_file	*new_file(int fd)
{
	t_file	*file;
	//char	*tmp;

	file = (t_file *)ft_memalloc(sizeof(t_file));
	if (!file)
		return (0);
	file->fd = fd;
	file->buf = ft_strnew(BUFF_SIZE);
	ft_nmemset(file->buf, 0, BUFF_SIZE + 1);
	/*
	tmp = file->buf;
	for (int i = 0; i < BUFF_SIZE; ++i)
	{
		ft_putchar(*tmp + 48);
		ft_putchar('\n');
		++tmp;
	}
	*/
	//ft_strcpy(file->buf, "hello");
	if (!file->buf)
		return (0);
	return (file);
}

t_list	*get_fd(t_list *head, int fd)
{
	t_file	*file;
	//char	*tmp;

	//write(1,"1",1);
	if (!head)
	{
		//write(1,"2",1);
		file = new_file(fd);
		ft_nmemset(file->buf, 0, BUFF_SIZE);
		//tmp = file->buf;
		head = ft_lstnew(file, sizeof(t_file *));
		write(1,"n3",2);
		/*
		for (int i = 0; i < BUFF_SIZE; ++i)
		{
			ft_putchar(*tmp);
			ft_putchar('\n');
			++tmp;
		}
		*/
		write(1,"4",1);
	}
	if (!head->content)
	{
		ft_putstr("not doing this\n");
		head->content = new_file(fd);
		head->content_size = sizeof(t_file *);
	}
	while (head && head->content)
	{
		if (FD(head) == fd)
		{
			ft_putstr("should be here\n");
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
	static t_list	*head = 0;
	t_list			*cur;
	//char			*tmp;

	cur = get_fd(head, fd);
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
	if (!BUF(cur))
	{
		ft_putstr("reading\n");
		read(fd, BUF(cur), BUFF_SIZE - 1);
	}
	if (!BUF(cur))
		ft_putstr("what the hell it should have read");
	write(1,"a",1);
	/*
	ft_putstr("not reading\n");
	ft_putnbr(ft_strlen(BUF(cur)));
	ft_putchar('\n');
	ft_putnbr(ft_strlen(*line));
	ft_putchar('\n');
	ft_putnbr(BUFF_SIZE);
	ft_putchar('\n');
	ft_putstr(BUF(cur));
	ft_putchar('\n');
	*/
	/*
	if (!ft_strchr(BUF(cur), '\n'))
	{
		ft_putstr("before this part\n");
		*line = ft_strcpy(ft_memalloc(ft_strlen(*line) + BUFF_SIZE), *line);
		ft_putstr("after this part\n");
	}
	else
	{
		write(1,"e",1);
		*line = ft_strsub(BUF(cur), 0, ft_strchr(BUF(cur), '\n') - BUF(cur));
	}
	*/
	return (1);
}
