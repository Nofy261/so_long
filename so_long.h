/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:10:05 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/04 09:13:19 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_map
{
	char **map; // la carte 2D
	int		width; // largeur
	int		height; // hauteur

}				t_map;



// typedef struct pos_s
// {
// 	int		x;
// 	int		y;
// }				t_pos;





#endif