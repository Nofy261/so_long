/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:06:58 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/16 10:49:35 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up_down(t_game *game, int movement)
{
	mlx_delete_image(game->mlx, game->images.image_floor);
	game->images.image_floor = mlx_new_image(game->mlx, game->width, game->height);
	game->images.image_rabit = mlx_texture_to_image(game->mlx,
		game->textures.texture_rabit);
	mlx_image_to_window(game->mlx, game->images.image_rabit, game->player_x,
		game->player_y + movement);
	game->player_y += movement;
	game->move_count++;
	//ft_printf("%d\n", game->move_count);
}

void	move_left_right(t_game *game, int movement)
{
	mlx_delete_image(game->mlx, game->images.image_floor);
	game->images.image_floor = mlx_new_image(game->mlx, game->width, game->height);
	game->images.image_rabit = mlx_texture_to_image(game->mlx, game->textures.texture_rabit);
	mlx_image_to_window(game->mlx, game->images.image_rabit, game->player_x + movement, game->player_y);
	game->player_x += movement;
	game->move_count++;
	//ft_printf("%d\n", game->move_count);	
}