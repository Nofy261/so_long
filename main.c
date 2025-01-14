/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:33:19 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/14 18:56:04 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// A ENLEVER !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// void    print_map(t_game *game)
// {
//     int i;

//     i = 0; 
//     while (game->map[i])
//     {
//         printf("%s\n", game->map[i]);
//         i++;
//     }
// }

// static void get_height_and_width(t_game *game)
// {
//     int i = 0;
//     int j = 0;

//     while (game->map[j])
//     {
//         j = 0;
//         while (game->map[j][i])
//             i++;
//         j++;
//     }
//     game->width = j - 1;// taille de la largeur -1 pour '\0' 
//     game->height = i - 1; // taille de la hauteur
// }

#include <stdio.h> // A ENLEVER !!!!!!!!!!!!!!!!!!
int main(int argc, char **argv)
{
    t_game game;
    game.count_e = 0;
    game.count_p = 0;
    game.count_c = 0;
    game.width = 0;
    game.height = 0;
    if (argc != 2)
    {
        ft_putstr("Error: Invalid argument\n");
        return (1);
    }
    // game = ft_calloc(sizeof(t_game), 1);
    // if (!&game)
    // {
    //     ft_putstr("Error: Memory allocation failed\n");
    //     return (1);
    // }
	verif_extension_ber(&game, argv);
    if (open_map(argv[1], &game) != 0)
    {
        //free(&game);
        return (1);
    }
    if (check_invalid_elements(&game) == 1)
        return (1);
    if (check_collectible(&game) == 1)
        return (1);
    if (check_exit(&game) == 1)
        return (1);
    if (check_player(&game) == 1)
        return (1);
    if (check_form(&game) == 1)
        return (1);
    if  (check_horizontal_walls(game.map[0]) == 1 || 
        check_horizontal_walls(game.map[game.height - 1]) == 1)
        return (1);
    if (check_vertical_walls(&game) == 1)
        return (1);
    //print_map(&game);
    if (validate_flood_fill(&game) == 1)// rajout
      return (1);// rajout
    //printf("\n");
    //print_map(&game);
    mlx_set_setting(MLX_STRETCH_IMAGE, true);// permet d'adapter l'image quand on retrecit l'ecran
    game.mlx = mlx_init(game.width * SPRITE_PIXEL, game.height * SPRITE_PIXEL, "Rabbit Party", true);
    printf("je passe 9\n");
    display_map(&game);
    printf("je passe 10\n");
    mlx_loop(game.mlx);
    // free(&game);
    return (0);
}




// char **game;
// game = ft_calloc(sizeof(t_game), 1);
// if (!game)
// {
//     ft_putstr("Error: Memory allocation failed\n");
//     return (1);
// }




	
// affiche la fenetre
	// // initialise mlx42 et creer une fenetre de 800*600
    // mlx_t* mlx = mlx_init(800, 600, "so_long", false);
    // if (!mlx)
    // {
    //     //fprintf(stderr, "Erreur : %s\n", mlx_strerror(mlx_errno));
	// 	printf("Error\n");
    //     return (1);
    // }
	
	// //mlx_texture_t* mlx_load_png(const char* path);
	// // charger l'image en tant que texture
	// mlx_texture_t* texture = mlx_load_png("pictures/carot.png");
	// if (!texture)
	// {
	// 	printf("Error de chargement de la texture\n");
	// 	return(1);
	// }

	// // mlx_image_t* mlx_texture_to_image(mlx_t* mlx, mlx_texture_t* texture);
	// // convertir la texture en une image mlx 
	// mlx_image_t *image = mlx_texture_to_image(mlx, texture);
	// if (!image)
	// {
	// 	printf("Error de conversion en image\n");
	// 	return(1);
	// }
	
	// // affiche l'image dans la fenetre a la position (0.0)
	// mlx_image_to_window(mlx, image, 0, 0);
	
    // // Démarrer la boucle d'événements
    // mlx_loop(mlx);

    // // Terminer MLX avant de quitter
    // mlx_terminate(mlx);
    // return (0);



// //recuperer la map.ber = ouvrir , lire, traiter le contenu de la map

// char *map = get_next_line() // recupere ligne par ligne de la map

