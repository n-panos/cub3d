#include "cub3d.h"

void	leaks(void)
{
	system("leaks -q cub3D");
}

int	main(int argc, char **argv)
{
	atexit(leaks);
	if (argc != 2)
		return (ft_putstr_fd("argc diferente de 2", 1), 0);
	ft_parse(argv);
	return (0);
}
