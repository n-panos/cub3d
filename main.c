#include "cub3d.h"

void	leaks(void)
{
	system("leaks -q cub3D");
}

int	main(int argc, char **argv)
{
	atexit(leaks);
	if (argc != 2)
		return (ft_error());
	ft_parse();
	return (0);
}
