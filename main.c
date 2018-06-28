#include <fcntl.h>
#include "get_next_line.h"
#include "libft.h"

int		main()
{
	int		fd;
	int		ret;
	char	*buf;

	fd = open("testfile", O_RDONLY);
	ft_putstr("fd: ");
	ft_putnbr(fd);
	ft_putchar('\n');
	ret = get_next_line(fd, &buf);
	ft_putstr("buf: \"");
	ft_putstr(buf);
	ft_putstr("\"\n");
	ft_putstr("ret: ");
	ft_putnbr(ret);
	ft_putchar('\n');
	ft_putchar('\n');
	ret = get_next_line(fd, &buf);
	ft_putstr("buf: \"");
	ft_putstr(buf);
	ft_putstr("\"\n");
	ft_putstr("ret: ");
	ft_putnbr(ret);
	ft_putchar('\n');
	ft_putchar('\n');
	ret = get_next_line(fd, &buf);
	ft_putstr("buf: \"");
	ft_putstr(buf);
	ft_putstr("\"\n");
	ft_putstr("ret: ");
	ft_putnbr(ret);
	ft_putchar('\n');
	ft_putchar('\n');
	ret = get_next_line(fd, &buf);
	ft_putstr("buf: \"");
	ft_putstr(buf);
	ft_putstr("\"\n");
	ft_putstr("ret: ");
	ft_putnbr(ret);
	ft_putchar('\n');
	ft_putchar('\n');
	ret = get_next_line(fd, &buf);
	ft_putstr("buf: \"");
	ft_putstr(buf);
	ft_putstr("\"\n");
	ft_putstr("ret: ");
	ft_putnbr(ret);
	ft_putchar('\n');
	return (0);
}
