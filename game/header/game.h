/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:28:30 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/02/08 12:59:02 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

typedef struct s_image
{
	void	*ptr;
	int		*addr;
	int		width;
	int		height;
	int		bits;
	int		size_line;
	int		endian;
}			t_image;

typedef struct s_play
{
	t_pos	pos;
	t_pos	dir;
	t_pos	x_dir;
	t_pos	plane;
	t_image	image;
	double	turn_speed;
	double	move_speed;
}			t_play;

typedef struct s_line
{
	int		draw_start;
	int		draw_end;
	int		x;
	int		y;
	int		y0;
	int		y1;
	int		tex_x;
	int		tex_y;
	int		line_height;
	char	wall_tex;
}			t_line;

typedef struct s_ray
{
	int		side;
	int		hit;
	double	perp_wall_dist;
	double	camera_x;
	int		curent_col;
	int		current_row;
	t_pos	ray_dir;
	t_pos	mpos;
	t_pos	side_dist;
	t_pos	delta_dist;
	t_pos	step;
	double	wall_x;
	t_line	*line;
}			t_ray;

typedef struct s_text
{
	struct s_image	*n;
	struct s_image	*s;
	struct s_image	*e;
	struct s_image	*w;
}			t_text;

typedef struct s_game
{
	t_map	*map;
	void	*mlx;
	void	*window;
	t_image	*render;
	t_text	*textures;
	t_play	*player;
}			t_game;

int		ft_game(t_map *map);
int		ft_keys(int key_code, t_game *cubd);
void	ft_render(t_game *cubd);

//		INIT

t_game	*ft_init_game(t_map *map);
t_ray	*ft_init_ray(char c);
t_ray	*ft_start_dir(t_ray *ray, char c);
t_image	*ft_generate_image(t_game *cubd, int width, int height);
t_image	*ft_png_to_image(t_game *cubd, char *dir);

//		END

int		ft_end_game(t_game *game);
void	ft_free_map(t_map *map);
void	ft_free_ray(t_ray *ray);
void	ft_free_image(t_image *image, void *mlx);

//		IMAGE - DRAWING

void	ft_minimap(t_game *cubd);
void	ft_draw_map(t_game *cubd);
void	ft_draw_player(t_game *cubd, int color);
void	ft_cuadriculas(t_game *cubd, int x_init, int y_init);

//	UTILS

//		RAYCASTING

void	ft_raycasting(t_game *cubd);
void	ft_set_pos(t_play *p, t_ray *ray, int x);
void	ft_raydir_and_dist(t_ray *ray, t_play *p, int x);
void	ft_step(t_ray *ray, t_play *p);

//		RAY - DDA

char	ft_dda(t_game *cubd, t_ray *ray);
char	ft_what_tex(t_ray *ray);

//		RAY - WALLS

void	ft_walldist(t_ray *ray);
void	ft_v_line(t_line *line, t_ray *ray);
void	ft_texture(t_game *cubd, t_line *line, t_ray *ray);
t_image *ft_get_texture(t_line *line, t_game *cubd, t_ray *ray);

void	my_img_pixel_put(t_image *image, int x, int y, int color);
void	ft_put_pixel(t_image *image, int x, int y, int color);

//		RAY - PAINT

void	ft_paint_pixels(t_game *cubd, t_line *line, t_ray *ray, int x);
void	ft_wall(t_game *cubd, t_ray *ray, double *step, double *tex_pos);

//		MOVE

void	ft_move(t_game *cubd, int dir);
void	ft_turn(t_game *cubd, int dir);
void	ft_move_up(t_play *p, char **map);
void	ft_move_down(t_play *p, char **map);
void	ft_move_left(t_play *p, char **map);
void	ft_move_right(t_play *p, char **map);
void    ft_turn_left(t_game *cubd, double turn_speed);
void    ft_turn_right(t_game *cubd, double turn_speed);

#endif