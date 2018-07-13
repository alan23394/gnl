#include <fcntl.h>
#include "get_next_line.h"
#include "libft.h"

int		main()
{
	/*
	int		fd;
	char	*buf;
	int		ret;

	if (argc != 2)
	{
		ft_putendl("usage: ./gnl <fildes>");
		return (0);
	}
	if (ft_strequ(argv[1], "stdin"))
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	ft_putstr("fd: ");
	ft_putnbr(fd);
	ft_putchar('\n');
	ft_putstr("BUFF_SIZE: ");
	ft_putnbr(BUFF_SIZE);
	ft_putchar('\n');
	while ((ret = get_next_line(fd, &buf)) && ret != -1)
	{
		ft_putstr("buf: \"");
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
	*/
	char  *line = NULL;
  	int   fd = open("gnl10.txt", O_RDONLY);
	ft_putnbr(fd);
	ft_putchar('\n');
  	get_next_line(fd, &line);
  	close(fd);
	sleep(5);
  	return (0);
}
