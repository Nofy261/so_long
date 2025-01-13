/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:17:57 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/13 16:56:05 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_texture(t_game *game)
{
	// charger les textures a partir des images
	game->textures.texture_carot = mlx_load_png("images/carot.png");
	game->textures.texture_floor = mlx_load_png("images/floor.png");
	game->textures.texture_gate = mlx_load_png("images/gate.png");
	game->textures.texture_rabit = mlx_load_png("images/rabit.png");
	game->textures.texture_rabit_end = mlx_load_png("images/rabit_end.png");
	game->textures.texture_wall = mlx_load_png("images/wall.png");

	if (!game->textures.texture_carot || !game->textures.texture_gate ||
        !game->textures.texture_wall || !game->textures.texture_floor ||
        !game->textures.texture_rabit || !game->textures.texture_rabit_end)
	{
        ft_putstr("Error: loading textures\n"); // +ft_free();
        exit(EXIT_FAILURE);  // Arrêter l'exécution du programme en cas d'erreur
    }
}

// convertir les textures en images mlx pour pouvoir les afficher
static void	convert_texture_to_image(t_game *game)
{
	
	game->images.image_carot = mlx_texture_to_image(game->mlx, game->textures.texture_carot);
	game->images.image_floor = mlx_texture_to_image(game->mlx, game->textures.texture_floor);
	game->images.image_gate = mlx_texture_to_image(game->mlx, game->textures.texture_gate);
	game->images.image_rabit_end = mlx_texture_to_image(game->mlx, game->textures.texture_rabit_end);
	game->images.image_rabit = mlx_texture_to_image(game->mlx, game->textures.texture_rabit);
	game->images.image_wall = mlx_texture_to_image(game->mlx, game->textures.texture_wall);

	if (!game->images.image_carot || !game->images.image_floor ||
		!game->images.image_gate || !game->images.image_rabit_end ||
		!game->images.image_rabit || !game->images.image_wall)
	{
		ft_putstr("Error: Failed to convert texture to image\n");
		exit(EXIT_FAILURE);
	}
}

// affiche l'image dans la fenetre a la position (0.0)
// mlx_image_to_window(mlx, image, 0, 0);
// int32_t mlx_image_to_window(mlx_t* mlx, mlx_image_t* img, int32_t x, int32_t y);
// int32_t conserve la valeur precis des coordonnees (y,x) de l'image;

// static void display_image_to_window(t_game *game, int x, int y)
// {
// 	mlx_image_to_window(game->mlx, game->images.image_carot, x, y);
// 	mlx_image_to_window(game->mlx, game->images.image_floor, x, y);
// 	mlx_image_to_window(game->mlx, game->images.image_gate, x, y);
// 	mlx_image_to_window(game->mlx, game->images.image_rabit_end, x, y);
// 	mlx_image_to_window(game->mlx, game->images.image_rabit, x, y);
// 	mlx_image_to_window(game->mlx, game->images.image_wall, x, y);


// 	if (mlx_image_to_window(game->mlx, game->images.image_carot, x, y) == -1 ||
// 		mlx_image_to_window(game->mlx, game->images.image_floor, x, y) == -1 ||
// 		mlx_image_to_window(game->mlx, game->images.image_gate, x, y) == -1 ||
// 		mlx_image_to_window(game->mlx, game->images.image_rabit_end, x, y) == -1 ||
// 		mlx_image_to_window(game->mlx, game->images.image_rabit, x, y) == -1 ||
// 		mlx_image_to_window(game->mlx, game->images.image_wall, x, y) == -1)
// 	{
// 		ft_putstr("Error: failed to draw carrot image\n");
// 		exit(EXIT_FAILURE);
// 	}
// }

void	display_element_at_position(t_game *game, char element, int x, int y)
{
	mlx_image_to_window(game->mlx, game->images.image_floor, x, y);
	if (element == 'C')
		mlx_image_to_window(game->mlx, game->images.image_carot, x, y);
	else if (element == 'P')
	{
		mlx_image_to_window(game->mlx, game->images.image_rabit, x, y);
		game->x = x;
		game->y = y;
	}
	else if (element == '1')
		mlx_image_to_window(game->mlx, game->images.image_wall, x, y);
	else if (element == 'E')
	{
		mlx_image_to_window(game->mlx, game->images.image_gate, x, y);
		game->x_gate = x;
		game->y_gate = y;
	}
}



// void	display_sprites_to_the_map(t_game *game, int x, int y)
// {
// 	game->mlx = mlx_init(game->width * SPRITE_PIXEL, game->height * SPRITE_PIXEL, "So_long", true);
// 	if (!game->mlx)
// 		exit(EXIT_FAILURE);
// 	init_texture(game);
// 	convert_texture_to_image(game);
// 	display_image_to_window(game, x, y);
	
	
// }





/**
 * Initializes a new MLX42 Instance.
 * 
 * @param[in] width The width of the window.
 * @param[in] height The height of the window.
 * @param[in] title The title of the window.
 * @param[in] resize Enable window resizing.
 * @returns Ptr to the MLX handle or null on failure.
 */
//mlx_t* mlx_init(int32_t width, int32_t height, const char* title, bool resize);


