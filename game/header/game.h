
#ifndef GAME_H
# define GAME_H

typedef struct s_game
{
	t_map	*map;
	void	*mlx;
	void	*window;
	t_pos	*player;
	t_pos	*ray;
}			t_game;

int 	ft_game(t_map *map);
int		ft_keys(int key_code, t_game *cubd);

//		INIT - FREE

t_game	*ft_init_game(t_map *map);
int		ft_end_game(t_game *game);

//		IMAGE - DRAWING

void	ft_draw_map(t_game *cubd);
void	ft_minimap(t_game *cubd);
void	ft_cuadriculas(t_game *cubd, int x_init, int y_init);

#endif