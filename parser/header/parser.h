/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:07:58 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/12/19 20:46:34 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
}			t_rgb;


typedef struct s_map
{
	char	**map;
	char	*north_path;
	char	*south_path;
	char	*west_path;
	char	*east_path;
	t_rgb	floor;
	t_rgb	ceiling;
	char	spawn_orient;
	t_pos	*spawn;
}			t_map;

t_map	*ft_parse(char *argv);
void	ft_solve_map(t_map *map, char **mtx);
char	*ft_parse_line(t_map *map, char *str);
char	*ft_parse_textures(t_map *map, char *line);

//	DISTRIBUTE

char	*ft_distribute_rgb(char *line, t_rgb *rgb);
char	*ft_distribute_line(char *line, char *path);
char	*ft_distribute_map(t_map *map, char **mtx, int i);
int		ft_empty_lines(char **mtx, int i);

//	VALIDATE MAP

void    ft_valid_texture(t_map *map);
void	ft_valid_chars(t_map *map);
int		ft_valid_map(char **map):

//	INIT

t_map	*ft_init_map(void);
t_pos	*ft_pos_init(int x, int y);
void	ft_map_error(t_map *map, char *str);

int		ft_give_coords(t_pos *vector, int x, int y);
void	ft_rgb(t_rgb *rgb, char *r, char *g, char *b);
int		ft_aredigit_atoi(char *str);
char	*ft_space(char *str);

//  Open File

char	**ft_file(char *argv);
int		ft_open_file(char *argv);

#endif