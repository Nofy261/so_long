/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:06:58 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/17 14:55:02 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_up(t_game *game)
{
	game->player_y -= 1;

    game->images.image_rabit->instances[0].x = game->player_x * SPRITE_PIXEL;
    game->images.image_rabit->instances[0].y = game->player_y * SPRITE_PIXEL;

    game->move_count++;
    //ft_printf("%d\n", game->move_count);
}

void move_down(t_game *game)
{
	game->player_y += 1;

    game->images.image_rabit->instances[0].x = game->player_x * SPRITE_PIXEL;
    game->images.image_rabit->instances[0].y = game->player_y * SPRITE_PIXEL;

    game->move_count++;
	 //ft_printf("%d\n", game->move_count);
}

void move_right(t_game *game)
{
   game->player_x += 1;

    game->images.image_rabit->instances[0].x = game->player_x * SPRITE_PIXEL;
    game->images.image_rabit->instances[0].y = game->player_y * SPRITE_PIXEL;

    game->move_count++;
	 //ft_printf("%d\n", game->move_count);
}

void	move_left(t_game *game)
{
	game->player_x -= 1;

	game->images.image_rabit->instances[0].x = game->player_x * SPRITE_PIXEL;
    game->images.image_rabit->instances[0].y = game->player_y * SPRITE_PIXEL;
	game->move_count++;
	 //ft_printf("%d\n", game->move_count);
}




