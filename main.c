/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 16:00:49 by rreedy            #+#    #+#             */
/*   Updated: 2018/11/06 15:24:12 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>

int		main(void)
{
	int		fd;
	int		fd2;
	int		fd3;
	int		diff_file_size;
//	int		ret;
	char	*line;

/* ************************************************************************** */
/*                                                                            */
/*  main using stdin                                                          */
/*                                                                            */
/* ************************************************************************** */
/*
	(void)argc;
	fd = open(argv[1], O_RDONLY);
	ret = get_next_line(fd1, &line);
	while (ret)
	{
		ft_putnbr(ret);
		ft_putendl(line);
		ft_strdel(&line);
		ret = get_next_line(fd1, &line);
	}
	ft_putnbr(ret);
	close(fd);
*/
/* ************************************************************************** */
/*                                                                            */
/*  moulitest test 41_hard_test_large_file.spec.c without timeout             */
/*                                                                            */
/* ************************************************************************** */
    system("mkdir -p sandbox");
	system("openssl rand -out sandbox/large_file.txt -base64 $((50 * 1000 * 3/4)) 2> /dev/null");

	fd = open("sandbox/large_file.txt", O_RDONLY);
	fd2 = open("sandbox/large_file.txt.mine", O_CREAT | O_RDWR | O_TRUNC, 0755);

	while (get_next_line(fd, &line) == 1)
	{
		write(fd2, line, ft_strlen(line));
		write(fd2, "\n", 1);
	}

	close(fd);
	close(fd2);

	system("diff sandbox/large_file.txt sandbox/large_file.txt.mine > sandbox/large_file.diff");
	fd3 = open("sandbox/large_file.diff", O_RDONLY);
	diff_file_size = read(fd3, NULL, 10);
	close(fd3);

	if (diff_file_size == 0)
		ft_putstr("diff_file_size == 0");
	sleep (1000);
/* ************************************************************************** */
/*                                                                            */
/*  moulitest test 42_hard_test_one_big_fat_line.spec.c without timeout       */
/*                                                                            */
/* ************************************************************************** */
/*
    system("mkdir -p sandbox");
	system("openssl rand -base64 $((30 * 1000 * 3/4)) | tr -d '\n' | tr -d '\r' > sandbox/one_big_fat_line.txt");
	system("echo '\n' >> sandbox/one_big_fat_line.txt");

	fd = open("sandbox/one_big_fat_line.txt", O_RDONLY);
	fd2 = open("sandbox/one_big_fat_line.txt.mine", O_CREAT | O_RDWR | O_TRUNC, 0755);

	while (get_next_line(fd, &line) == 1)
	{
	    write(fd2, line, ft_strlen(line));
	    write(fd2, "\n", 1);
	}
	if (line)
		write(fd2, line, ft_strlen(line));
	close(fd);
	close(fd2);

	system("diff sandbox/one_big_fat_line.txt sandbox/one_big_fat_line.txt.mine > sandbox/one_big_fat_line.diff");
	fd3 = open("sandbox/one_big_fat_line.diff", O_RDONLY);
	diff_file_size = read(fd3, NULL, 10);
	close(fd3);

	if (diff_file_size == 0)
		ft_putstr("diff_file_size == 0");
	return (0);
*/
}
