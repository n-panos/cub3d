#include "cub3d.h"

void	leaks(void)
{
	system("leaks -q cub3D");
}

int	main(int argc, char **argv)
{
	//atexit(leaks);
	if (argc != 2)
		return (ft_putstr_fd("argc diferente de 2", 2), 0);
	ft_parse(argv[1]);
	return (0);
}

void	ft_exit_err(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	ft_mtx_print(char **mtx)
{
	int	i;

	i = 0;
	while (mtx[i])
	{
		printf("%s\n", mtx[i]);
		++i;
	}
}
