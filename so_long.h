/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:10:05 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/13 16:55:42 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <MLX42/MLX42.h>
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# define SPRITE_PIXEL 64

typedef struct s_game
{
	mlx_t	*mlx;
	t_textures	textures;
	t_images	images;
	char	**map; // la carte 2D
	char	**mapcopy;
	int		width; // largeur
	int		height; // hauteur

	int		move_x; //pos_x
	int		move_y; //pos_y
	int				x_gate;
	int				y_gate;
	int		player_x;
	int		player_y;
	int					count_p;
	int					count_c;
	int					count_e;
}				t_game;

typedef struct s_textures
{
	mlx_texture_t *texture_carot;
	mlx_texture_t *texture_floor;
	mlx_texture_t *texture_gate;
	mlx_texture_t *texture_rabit_end;
	mlx_texture_t *texture_rabit;
	mlx_texture_t *texture_wall;

	
} t_textures;


typedef struct s_images
{
	mlx_image_t *image_carot;
	mlx_image_t *image_floor;
	mlx_image_t *image_gate;
	mlx_image_t *image_rabit_end;
	mlx_image_t *image_rabit;
	mlx_image_t *image_wall;
	
} t_images;


/* Utils */
int		ft_putstr(char *str);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/* open_map */
int open_map(const char *path, t_game *game);

/* check_pec*/
int check_collectible(t_game *game);
int check_player(t_game *game);
int check_exit(t_game *game);

/* parse_map */
void	verif_extension_ber(t_game *game, char **argv);
int	check_horizontal_walls(char *line);
int check_vertical_walls(t_game *game);
int check_form(t_game *game);
int check_invalid_elements(t_game *game);

/* parsing*/
void flood_fill(int x, int y, t_game *game);
int validate_flood_fill(t_game *game);



#endif