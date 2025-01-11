/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:33:19 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/11 17:23:24 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_game *game;

    if (argc != 2)
    {
        ft_putstr("Error: Invalid argument\n");
        return (1);
    }
    game = ft_calloc(sizeof(t_game), 1);
    if (!game)
    {
        ft_putstr("Error: Memory allocation failed\n");
        return (1);
    }
    // Parsing map 
	verif_extension_ber(game, argv);
    if (open_map(argv[1], game) != 0)
    {
        free(game);
        return (1);
    }
    if (check_collectible(game) == 1)
        return (1);
    if (check_player(game) == 1)
        return (1);
    if (check_exit(game) == 1)
        return (1);
    if (check_form(game) == 1)
        return (1);
    if (check_horizontal_walls(game->map[0]) == 1 || 
        check_horizontal_walls(game->map[game->height - 1]) == 1)
        return (1);
    if (check_vertical_walls(game) == 1)
        return (1);
    free(game);
    return (0);
}


























































	
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
// // une ligne = un node
// // mettre dans une liste chainee 

// char *map = get_next_line() // recupere ligne par ligne de la map

