/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:07:58 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/12/11 11:18:15 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct s_map
{
	char	**map;
	char	*north_path;
	char	*south_path;
	char	*west_path;
	char	*east_path;
	int		floor_rgb[3];
	int		ceiling_rgb[3];
	char	spawn_orient;
	t_pos	*spawn;
}			t_map;

t_map	*ft_parse(char *argv);
t_map	*ft_init_map(void);

//  Open File

char	**ft_file(char *argv);
int		ft_open_file(char *argv);

#endif