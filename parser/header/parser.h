/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:07:58 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/02/07 16:34:56 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_pos_int
{
	int		x;
	int		y;
}			t_pos_int;

typedef struct s_pos
{
	double	x;
	double	y;
}			t_pos;

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
}			t_rgb;


typedef struct s_map
{
	char		**map;
	char		*error_ret;
	char		*north_path;
	char		*south_path;
	char		*west_path;
	char		*east_path;
	t_rgb		*floor;
	t_rgb		*ceiling;
	char		spawn_orient;
	t_pos_int	*spawn;
}			t_map;

int		ft_parse(t_map *map, char *argv);
void	ft_solve_map(t_map *map, char **mtx);
void	ft_parse_line(t_map *map, char *str);
int		ft_parse_textures(t_map *map, char *line);
int		ft_parse_rgb(t_map *map, char *line);

//	DISTRIBUTE

t_rgb	*ft_distribute_rgb(char *line, t_map *map);
char	*ft_distribute_line(char *line, t_map *map);
void	ft_distribute_map(t_map *map, char **mtx, int i);
int		ft_empty_line(char *line);

//	VALIDATE MAP

void    ft_valid_texture(t_map *map);
void	ft_valid_chars(t_map *map);
int		ft_valid_map(t_map *map);

//	MAP PAINT

int		ft_paint_map(char **map);
int		ft_only_ones(char *str);
int		ft_search_sides(char **map, int i, int j);
int		ft_search_mtx(char **map);
int		ft_change_ps(char **map, int i, int j, int ret);

//	INIT

t_map		*ft_init_map(void);
t_pos_int	*ft_posint_init(int x, int y);
t_rgb		*ft_rgb(char *r, char *g, char *b);
void		ft_map_error(t_map *map, char *str);

int		ft_give_coords(t_pos_int *vector, int x, int y);
int		ft_aredigit_atoi(char *str);
char	*ft_space(char *str);

//  Open File

char	**ft_file(char *argv);
int		ft_open_file(char *argv);

#endif