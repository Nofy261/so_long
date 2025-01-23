/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:17:57 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/23 16:10:29 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_texture(t_game *game)
{
	game->textures.texture_carot = mlx_load_png("images/carot.png");
	game->textures.texture_floor = mlx_load_png("images/floor.png");
	game->textures.texture_gate = mlx_load_png("images/gate.png");
	game->textures.texture_rabit = mlx_load_png("images/rabit.png");
	game->textures.texture_wall = mlx_load_png("images/wall.png");
	if (!game->textures.texture_carot || !game->textures.texture_gate
		|| !game->textures.texture_wall || !game->textures.texture_floor
		|| !game->textures.texture_rabit)
	{
		ft_putstr_fd("Error: loading textures\n", 2);
		ft_free(game->map);
		exit(EXIT_FAILURE);
	}
}

void	convert_texture_to_image(t_game *game)
{
	game->images.image_carot = mlx_texture_to_image(game->mlx,
			game->textures.texture_carot);
	game->images.image_floor = mlx_texture_to_image(game->mlx,
			game->textures.texture_floor);
	game->images.image_gate = mlx_texture_to_image(game->mlx,
			game->textures.texture_gate);
	game->images.image_rabit = mlx_texture_to_image(game->mlx,
			game->textures.texture_rabit);
	game->images.image_wall = mlx_texture_to_image(game->mlx,
			game->textures.texture_wall);
	if (!game->images.image_carot || !game->images.image_floor
		|| !game->images.image_gate
		|| !game->images.image_rabit || !game->images.image_wall)
	{
		ft_putstr_fd("Error: Failed to convert texture to image\n", 2);
		ft_free(game->map);
		exit(EXIT_FAILURE);
	}
}

void	display_sprites_in_start_position(t_game *game, char element, int x,
		int y)
{
	mlx_image_to_window(game->mlx, game->images.image_floor, x * SPRITE_PIXEL, y
		* SPRITE_PIXEL);
	if (element == 'C')
		mlx_image_to_window(game->mlx, game->images.image_carot, x
			* SPRITE_PIXEL, y * SPRITE_PIXEL);
	else if (element == '1')
		mlx_image_to_window(game->mlx, game->images.image_wall, x
			* SPRITE_PIXEL, y * SPRITE_PIXEL);
	else if (element == 'E')
		mlx_image_to_window(game->mlx, game->images.image_gate, game->gate_x
			* SPRITE_PIXEL, game->gate_y * SPRITE_PIXEL);
}

void	display_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	init_texture(game);
	convert_texture_to_image(game);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			display_sprites_in_start_position(game, game->map[i][j], j, i);
			j++;
		}
		i++;
	}
	mlx_image_to_window(game->mlx, game->images.image_rabit, game->player_x
		* SPRITE_PIXEL, game->player_y * SPRITE_PIXEL);
}
