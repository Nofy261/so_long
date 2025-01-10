/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:10:05 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/10 20:50:20 by nolecler         ###   ########.fr       */
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
	int		row;
	int		colum;
	int		move_x; //pos_x
	int		move_y; //pos_y

	// int					count_p;
	// int					count_c;
	// int					count_e;
	// int					count_moves;
	

}				t_game;

/* Utils */
int		ft_putstr(char *str);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);


int 	open_map(const char *path);
void	verif_extension_ber(t_game *game, char **argv);


#endif