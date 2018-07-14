/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 20:52:54 by abarnett          #+#    #+#             */
/*   Updated: 2018/07/13 20:58:48 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include "libft.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("gnl10.txt", O_RDONLY);
	line = NULL;
	get_next_line(fd, &line);
	close(fd);
	ft_strdel(&line);
	return (0);
}
