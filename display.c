/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:17:57 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/14 19:04:20 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>
// charger les textures a partir des images
static void	init_texture(t_game *game)
{
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
void	convert_texture_to_image(t_game *game) // SEG FAULT
{
	printf("convert texture to image1\n");

	// game->mlx = mlx_init(game->height * SPRITE_PIXEL,
	// 		game->width * SPRITE_PIXEL, "Rabit party", true);
	// if (!game->mlx)
	// 	exit(EXIT_FAILURE);
	// init_texture(game);
	// if (!game->textures.texture_gate || !game->textures.texture_floor
	// 	|| !game->textures.texture_carot
	// 	|| !game->textures.texture_rabit_end || !game->textures.texture_rabit
	// 	|| !game->textures.texture_wall)
	// {
	// 	//free_struct(vars);
	// 	ft_putstr("Error: convert textures to image \n");
	// 	exit(EXIT_FAILURE);
	// }

	game->images.image_carot = mlx_texture_to_image(game->mlx, game->textures.texture_carot);
	game->images.image_floor = mlx_texture_to_image(game->mlx, game->textures.texture_floor);
	game->images.image_gate = mlx_texture_to_image(game->mlx, game->textures.texture_gate);
	game->images.image_rabit_end = mlx_texture_to_image(game->mlx, game->textures.texture_rabit_end);
	game->images.image_rabit = mlx_texture_to_image(game->mlx, game->textures.texture_rabit);
	game->images.image_wall = mlx_texture_to_image(game->mlx, game->textures.texture_wall);
	

	// if (!game->images.image_carot || !game->images.image_floor ||
	// 	!game->images.image_gate || !game->images.image_rabit_end ||
	// 	!game->images.image_rabit || !game->images.image_wall)
	// {
	// 	ft_putstr("Error: Failed to convert texture to image\n");
	// 	exit(EXIT_FAILURE);
	// }
}

// mlx_image_to_window(mlx, image, 0, 0);
// int32_t mlx_image_to_window(mlx_t* mlx, mlx_image_t* img, int32_t x, int32_t y);
// int32_t conserve la valeur precis des coordonnees (y,x) de l'image;
// quand P arrive sur C, on enleve C
// mettre le sol en premier , ensuite le collectible
// mlx init = pont entre le programme et la fenetre


// fonction qui met tous les sprites a leur position de depart sauf le Personnage
void	display_sprites_in_start_position(t_game *game, char element, int x, int y)
{
	mlx_image_to_window(game->mlx, game->images.image_floor, x * SPRITE_PIXEL, y * SPRITE_PIXEL); // mettre le fond(les zeros) au depart 
	if (element == 'C')
		mlx_image_to_window(game->mlx, game->images.image_carot, x * SPRITE_PIXEL, y * SPRITE_PIXEL);
	else if (element == '1')
		mlx_image_to_window(game->mlx, game->images.image_wall, x * SPRITE_PIXEL, y * SPRITE_PIXEL);
	else if (element == 'E')
		mlx_image_to_window(game->mlx, game->images.image_gate, game->gate_x * SPRITE_PIXEL, game->gate_y * SPRITE_PIXEL);
}

void	display_map(t_game *game)
{
    int i;
    int j;

    j = 0;
	// game->mlx = mlx_init(game->width * SPRITE_PIXEL, game->height * SPRITE_PIXEL, "Rabbit Party", true);// rajout
	init_texture(game);
	printf("display map 2\n");
	convert_texture_to_image(game);
	printf("display map 3\n");
    while (game->map[j])
    {
		printf("display map 4\n");
        i = 0;
        while (game->map[j][i])
        {
			printf("display map 5\n");
            display_sprites_in_start_position(game, game->map[j][i], i, j);
            i++;
        }
        j++;
    }
	printf("display map 6\n");
	// on affiche le P en dernier pour eviter le pb de superposition d image
	mlx_image_to_window(game->mlx, game->images.image_rabit, game->player_x * SPRITE_PIXEL, game->player_y * SPRITE_PIXEL);
}

//mlx_t* mlx_init(int32_t width, int32_t height, const char* title, bool resize);


