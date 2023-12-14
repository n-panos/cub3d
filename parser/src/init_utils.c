#include "cub3d.h"

int	ft_give_coords(t_pos *vector, int x, int y)
{
	if (!vector || x < 0 || y < 0)
		return (1);
	vector->x = x;
	vector->y = y;
	return (0);
}

void	ft_rgb(t_rgb *rgb, char *r, char *g, char *b)
{
	rgb->r = ft_aredigit_atoi(r);
	rgb->g = ft_aredigit_atoi(g);
	rgb->b = ft_aredigit_atoi(b);
}

int	ft_aredigit_atoi(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		i++;
	}
	return (ft_atoi(str));
}

char	*ft_space(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return (str);
}
