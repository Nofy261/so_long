/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:10:05 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/11 17:55:13 by nolecler         ###   ########.fr       */
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

typedef struct s_game
{
	char	**map; // la carte 2D
	char	**mapcopy;
	int		width; // largeur
	int		height; // hauteur

	int		move_x; //pos_x
	int		move_y; //pos_y

	int					count_p;
	int					count_c;
	int					count_e;
}				t_game;

/* Utils */
int		ft_putstr(char *str);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);


int open_map(const char *path, t_game *game);
void	verif_extension_ber(t_game *game, char **argv);

/* check_pec*/
int check_collectible(t_game *game);
int check_player(t_game *game);
int check_exit(t_game *game);

/* parse_map */

int	check_horizontal_walls(char *line);
int check_vertical_walls(t_game *game);
int check_form(t_game *game);
int check_invalid_elements(t_game *game);

#endif