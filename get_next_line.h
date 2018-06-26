/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 12:4:58 by abarnett          #+#    #+#             */
/*   Updated: 2018/06/26 15:29:37 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
