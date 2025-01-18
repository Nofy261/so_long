/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:36:01 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/18 15:43:53 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// //game->images.image_rabit->instances[0].x = game->player_y * SPRITE_PIXEL;
void	collect_carot(t_game *game)
{
	int	i;
	
	i = 0;
	while (1)
	{
		if (game->count_c != 0)
		{
			if (game->player_y * SPRITE_PIXEL == game->images.image_carot->instances[i].y &&
				game->player_x * SPRITE_PIXEL == game->images.image_carot->instances[i].x)
			{
				game->images.image_carot->instances[i].enabled = false;
				game->map[game->player_y][game->player_x] = '0';
				game->count_c--;
				break ;	
			}
		}
		i++;
	}
	// if (game->count_c == 0)
	// {
	// 	mlx_image_to_window(game->mlx, game->images.image_rabit_end,
	// 		game->gate_x, game->gate_y);
	// 	if (game->map[(game->player_x)][(game->player_y)] == 'E')
	// 		mlx_close_window(game->mlx);
	// }
}




void move(t_game *game, int key)
{
    if (key == MLX_KEY_D || key == MLX_KEY_RIGHT)
    {
        if (game->map[game->player_y][game->player_x + 1] != '1')
            move_right(game);
    }
	if (key == MLX_KEY_A || key == MLX_KEY_LEFT)
    {
        if (game->map[game->player_y][game->player_x - 1] != '1')
            move_left(game);
    }
    if (key == MLX_KEY_W || key == MLX_KEY_UP)
    {
        if (game->map[game->player_y - 1][game->player_x] != '1')
            move_up(game);
    }
   	if (key == MLX_KEY_S || key == MLX_KEY_DOWN)
    {
        if (game->map[game->player_y + 1][game->player_x] != '1')
            move_down(game);
    }
	if (game->map[game->player_y][game->player_x] == 'C')
		collect_carot(game);	
}

void	key_events(mlx_key_data_t keydata, void *param)
{
	t_game *game;
	int	keycode;
	int	action;
	
	game = (t_game *)param;
	keycode = keydata.key;
	action = keydata.action;
	if (keycode == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
	else if(action == MLX_PRESS)
		move(game, keycode);
}
