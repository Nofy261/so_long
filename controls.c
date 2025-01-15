/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:36:01 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/15 18:27:22 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// creer une fonction qui gere les entrees du clavier

// mouvement personnage 
// key_press
// gere les touches a appuyer

// void    key_press(mlx_key_data_t keydata, void *param)
// mlx_key_hook(3 arguments)

// free texture a la fin

// caster en void * la structure t_game pour adapter a mlx_key_hook


//void	key_press(mlx_key_data_t keydata, void *param) // original
void	key_events(mlx_key_data_t keydata, t_game *game)
{
	t_game *game;

	//(void) keydata ;
	keydata;
	//game = param;
	
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE)) //si la touche echap est enfoncee , on ferme la fenetre
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W) || mlx_is_key_down(game->mlx, MLX_KEY_UP)); // manque une parenthese??
		move(game, MLX_KEY_W, -SPRITE_PIXEL);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A) || mlx_is_key_down(game->mlx, MLX_KEY_LEFT));
		move(game, MLX_KEY_A, -SPRITE_PIXEL);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S) || mlx_is_key_down(game->mlx, MLX_KEY_DOWN));
		move(game, MLX_KEY_S, SPRITE_PIXEL);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D) || mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		move(game, MLX_KEY_D, SPRITE_PIXEL);
	//if (game->map[(game->player_x)][(game->player_y)] == 'C') //quand P sur 'C' = image P devient l'image avec carot a la main
	//	mlx_image_to_window(game->mlx, game->images.image_rabit_end,
	//		game->collectible_x, game->collectible_y);
	if (game->count_c == 0)
	{
		mlx_image_to_window(game->mlx, game->images.image_rabit_end,
			game->gate_x, game->gate_y);
		if (game->map[(game->player_x)][(game->player_y)] == 'E')
			mlx_close_window(game->mlx);
		
		//if (game->map[(game->player_y / SPRITE_PIXEL)][game->player_x / SPRITE_PIXEL] == 'E')// original
		//	mlx_close_window(game->mlx);
	}
}

