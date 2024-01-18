/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipanos-o <ipanos-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:28:30 by ipanos-o          #+#    #+#             */
/*   Updated: 2024/01/18 13:02:44 by ipanos-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

typedef struct s_image
{
	void	*ptr;
	char	*addr;
	int		width;
	int		height;
	int		bits;
	int		size_line;
	int		endian;
}			t_image;

typedef struct s_ray
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	time;
	double	oldtime;
	t_pos	*map;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	t_pos	*step;
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		color;
}			t_ray;

typedef struct s_game
{
	t_map	*map;
	void	*mlx;
	void	*window;
	t_image	*render;
	t_pos	*player;
	t_ray	*ray;
}			t_game;

int		ft_game(t_map *map);
int		ft_keys(int key_code, t_game *cubd);
void	ft_render(t_game *cubd);

//		INIT

t_game	*ft_init_game(t_map *map);
t_ray	*ft_init_ray(t_pos *player, char c);
t_ray	*ft_start_dir(t_ray *ray, char c);
t_image	*ft_generate_image(t_game *cubd, int width, int height);

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

void	ft_draw_rect(t_game *cubd, t_pos start, t_pos end, int color);
void	ft_draw_dir(t_game *cubd, int color, int len);
void	ft_draw(t_game *cubd, t_ray *ray);
void	ft_calculos(t_game *cubd, t_ray *ray, \
		double rayDirX, double rayDirY);
void	ft_draw_vertical(t_game *cubd, int drawStart, int drawEnd, int x);
void	ft_put_pixel(t_image *image, int x, int y, int color);

//		MOVE

void	ft_move(t_game *cubd, int dir);
void	ft_turn(t_game *cubd, int dir);

#endif