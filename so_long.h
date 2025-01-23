/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:10:05 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/23 16:02:34 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include <MLX42/MLX42.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define SPRITE_PIXEL 64

typedef struct s_textures
{
	mlx_texture_t	*texture_carot;
	mlx_texture_t	*texture_floor;
	mlx_texture_t	*texture_gate;
	mlx_texture_t	*texture_rabit;
	mlx_texture_t	*texture_wall;
}					t_textures;

typedef struct s_images
{
	mlx_image_t		*image_carot;
	mlx_image_t		*image_floor;
	mlx_image_t		*image_gate;
	mlx_image_t		*image_rabit;
	mlx_image_t		*image_wall;
}					t_images;

typedef struct s_game
{
	mlx_t			*mlx;
	t_textures		textures;
	t_images		images;
	char			**map;
	char			**mapcopy;
	int				width;
	int				height;
	int				gate_x;
	int				gate_y;
	int				player_x;
	int				player_y;
	int				collectible_x;
	int				collectible_y;
	int				count_p;
	int				count_c;
	int				count_e;
	int				move_count;
}					t_game;

void				ft_putstr_fd(char *str, int fd);
void				*ft_calloc(size_t nmemb, size_t size);
void				*ft_memset(void *s, int c, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					open_map(const char *path, t_game *game);
void				trim_newline(char *line);
void				get_height_and_width(const char *path, t_game *game);
int					allocate_map_memory(t_game *game);
int					open_file(const char *path);
int					check_collectible(t_game *game);
int					check_player(t_game *game);
int					check_exit(t_game *game);
void				verif_extension_ber(t_game *game, char **argv);
int					check_horizontal_walls(char *line);
int					check_vertical_walls(t_game *game);
int					check_form(t_game *game);
int					check_invalid_elements(t_game *game);
void				flood_fill(int x, int y, t_game *game);
int					validate_flood_fill(t_game *game);
int					map_conditions(t_game *game);
void				display_map(t_game *game);
void				display_sprites_in_start_position(t_game *game,
						char element, int x, int y);
void				convert_texture_to_image(t_game *game);
void				move(t_game *game, int key);
void				key_events(mlx_key_data_t keydata, void *param);
void				collect_carrot(t_game *game);
void				move_up(t_game *game);
void				move_down(t_game *game);
void				move_right(t_game *game);
void				move_left(t_game *game);
int					ft_putchar(char c);
int					ft_putnbr(int n);
void				*ft_free(char **str);
void				free_texture(t_game *game);
void				ft_free_all(t_game *game);

#endif