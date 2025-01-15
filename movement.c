/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:06:58 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/15 18:22:01 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up_down(t_game *game, int movement)
{
	
	mlx_delete_image(game->mlx, game->images.image_floor);
	game->images.image_floor = mlx_new_image(game->mlx,
	game->height, game->width);


	
	
	vars->images.img_knight = mlx_texture_to_image(vars->mlx,
			vars->textures.texture_knight);
	mlx_image_to_window(vars->mlx, vars->images.img_knight, vars->x,
		vars->y + movement);
	vars->y += movement;
	vars->move_count++;
	ft_printf("%d\n", vars->move_count);
}