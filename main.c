#include <fcntl.h>
#include "get_next_line.h"
#include "libft.h"

int		main(int argc, char **argv)
{
	int		fd1;
	//int		fd2;
	char	*buf;
	int		ret;

	/*
	if (argc != 3)
	{
		ft_putendl("usage: ./gnl <fildes1> <fildes2>");
		return (0);
	}
	*/
	if (argc != 2)
	{
		ft_putendl("usage: ./gnl <fildes1>"/* <fildes2>"*/);
		return (0);
	}
	if (!ft_strequ(argv[1], "stdin"))
	{
		fd1 = open(argv[1], O_RDONLY);
		ft_putstr("fd1: ");
		ft_putnbr(fd1);
		ft_putchar('\n');
	}
	else
		fd1 = 0;
	/*
	if (!ft_strequ(argv[2], "stdin"))
	{
		fd2 = open(argv[1], O_RDONLY);
		ft_putstr("fd2: ");
		ft_putnbr(fd2);
		ft_putchar('\n');
	}
	else
		fd2 = 0;
	*/
	ft_putstr("BUFF_SIZE: ");
	ft_putnbr(BUFF_SIZE);
	ft_putchar('\n');
	while ((ret = get_next_line(fd1, &buf)) && ret != -1)
	{
		ft_putstr("fd1: \"");
		ft_putstr(buf);
		ft_putstr("\"\n");
	}
	ft_putstr("buf: \"");
	ft_putstr(buf);
	ft_putstr("\"\n");
	if (ret == -1)
		ft_putstr("gnl: error\n");
	if (ret == 0)
		ft_putstr("gnl: done\n");
	return (0);
}
