/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:07:58 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/12/19 11:27:47 by nacho            ###   ########.fr       */
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

//	INIT

t_map	*ft_init_map(void);
t_pos	*ft_pos_init(int x, int y);

int		ft_give_coords(t_pos *vector, int x, int y);
void	ft_rgb(t_rgb *rgb, char *r, char *g, char *b);
int		ft_aredigit_atoi(char *str);
char	*ft_space(char *str);

//  Open File

char	**ft_file(char *argv);
int		ft_open_file(char *argv);

#endif