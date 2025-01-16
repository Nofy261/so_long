/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:36:01 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/16 14:55:31 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collect_carot(t_game *game)
{
	if (game->map[game->player_x][game->player_y] == 'C')
	{
		mlx_image_to_window(game->mlx, game->images.image_floor,
			game->player_x, game->player_y);
		mlx_image_to_window(game->mlx, game->images.image_rabit_end,
			game->player_x, game->player_y);
		game->count_c--;	
	}
	if (game->count_c == 0)
	{
		mlx_image_to_window(game->mlx, game->images.image_rabit_end,
			game->gate_x, game->gate_y);
		if (game->map[(game->player_x)][(game->player_y)] == 'E')
			mlx_close_window(game->mlx);
	}	
}

// void	collectible_capture(t_vars *vars)
// {
// 	mlx_image_to_window(vars->mlx, vars->images.img_ground, vars->x, vars->y);
// 	mlx_image_to_window(vars->mlx, vars->images.img_knight, vars->x, vars->y);
// 	vars->map[(vars->y / SPRITE_PIXEL)][vars->x / SPRITE_PIXEL] = '0';
// 	vars->apple_count--;
// }

void move(t_game *game, int key, int movement)
{
	if (key == MLX_KEY_W || key == MLX_KEY_UP ||
		key == MLX_KEY_S || key == MLX_KEY_DOWN)
	{
		if (game->map[game->player_x][game->player_y + movement] != '1')
		move_up_down(game,movement);	
	}
	if (key == MLX_KEY_D || key == MLX_KEY_RIGHT ||
		key == MLX_KEY_A || key == MLX_KEY_LEFT)
	{
		if (game->map[game->player_x + movement][game->player_y] != '1')
		move_left_right(game, movement);
	}
	if (game->map[game->player_x][game->player_y] == 'C')
	{
		// fonctions qui capture C
		collect_carot(game);
	}	
}

// free texture a la fin

// caster en void * la structure t_game pour adapter a mlx_key_hook



// void	key_events(mlx_key_data_t keydata, void *param) // original
// //void	key_events(mlx_key_data_t keydata, t_game *game)
// {
// 	t_game *game;

// 	(void) keydata ;
// 	//keydata;
// 	game = param;
	
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE)) //si la touche echap est enfoncee , on ferme la fenetre
// 		mlx_close_window(game->mlx);
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_W) || mlx_is_key_down(game->mlx, MLX_KEY_UP)) // manque une parenthese??
// 		move(game, MLX_KEY_W, -SPRITE_PIXEL);
// 		//move(game, MLX_KEY_W);
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_A) || mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
// 		move(game, MLX_KEY_A, -SPRITE_PIXEL);
// 		//move(game, MLX_KEY_A);
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_S) || mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
// 		move(game, MLX_KEY_S, SPRITE_PIXEL);
// 		//move(game, MLX_KEY_S);
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_D) || mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
// 		move(game, MLX_KEY_D, SPRITE_PIXEL);
// 		//move(game, MLX_KEY_D);
// 	//if (game->map[(game->player_x)][(game->player_y)] == 'C') //quand P sur 'C' = image P devient l'image avec carot a la main
// 	//	mlx_image_to_window(game->mlx, game->images.image_rabit_end,
// 	//		game->player_x, game->player_y);
// 	collect_carot(game);
// 	// if (game->count_c == 0)
// 	// {
// 	// 	mlx_image_to_window(game->mlx, game->images.image_rabit_end,
// 	// 		game->gate_x, game->gate_y);
// 	// 	if (game->map[(game->player_x)][(game->player_y)] == 'E')
// 	// 		mlx_close_window(game->mlx);	
// 	// 	//if (game->map[(game->player_y / SPRITE_PIXEL)][game->player_x / SPRITE_PIXEL] == 'E')// original
// 	// 	//	mlx_close_window(game->mlx);
// 	// }
// }
// MLX_KEY_W				= 87,
// MLX_KEY_S				= 83,
// MLX_KEY_A				= 65,
// MLX_KEY_D				= 68,
// MLX_KEY_ESCAPE			= 256,

void	key_events(mlx_key_data_t keydata, void *param)
{
	t_game *game;
	int	keycode;
	
	game = (t_game *)param;
	keycode = keydata.key;
	
	
	if (keycode == MLX_KEY_ESCAPE) //echap
		mlx_close_window(game->mlx);
		
	if (keycode == MLX_KEY_W)
		move(game, MLX_KEY_W, -SPRITE_PIXEL);
	if (keycode == MLX_KEY_S)
		move(game, MLX_KEY_S, SPRITE_PIXEL);
	if (keycode == MLX_KEY_A)
		move(game, MLX_KEY_A, -SPRITE_PIXEL);
	if (keycode == MLX_KEY_D)
		move(game, MLX_KEY_D, SPRITE_PIXEL);
	
	
}

