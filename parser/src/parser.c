#include "cub3d.h"

t_map	*ft_parse(char *argv)
{
	char	**mtx;
	t_map	*map;

	map = ft_init_map();
	mtx = ft_file(argv);
	ft_mtx_print(mtx);
	free(mtx);
}

t_map	*ft_init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
}
