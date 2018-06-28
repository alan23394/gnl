#include <fcntl.h>
#include "get_next_line.h"
#include "libft.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*buf;
	int		ret;

	if (argc != 2)
	{
		ft_putendl("usage: ./gnl <file>");
		return (0);
	}
	if (!ft_strequ(argv[1], "stdin"))
	{
		fd = open(argv[1], O_RDONLY);
		ft_putstr("fd: ");
		ft_putnbr(fd);
		ft_putchar('\n');
	}
	else
		fd = 0;
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
	else
		ft_putstr("gnl: done\n");
	return (0);
}
