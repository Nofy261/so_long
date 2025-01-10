/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:33:19 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/10 11:09:56 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//#include <MLX42/MLX42.h>
//#include <stdio.h>

// int main()
// {
// 	char *map;
// 	int fd;

// 	fd = open("map.ber", O_RDONLY);
// 	while (1)
// 	{
// 		map = get_next_line(fd);
// 		printf("%s", map);
// 		if (map == NULL)
// 			break;
// 		free (map);
// 	}
// 	close (fd);
// 	return (0);
// }

// affiche la fenetre
int main(void)
{
	// initialise mlx42 et creer une fenetre de 800*600
    mlx_t* mlx = mlx_init(800, 600, "so_long", false);
    if (!mlx)
    {
        //fprintf(stderr, "Erreur : %s\n", mlx_strerror(mlx_errno));
		printf("Error\n");
        return (1);
    }
	//ajouter loop hook ici pour afficher les sprites 
	
	//mlx_texture_t* mlx_load_png(const char* path);
	// charger l'image en tant que texture
	mlx_texture_t* texture = mlx_load_png("pictures/rabit.png");
	if (!texture)
	{
		printf("Error de chargement de la texture\n");
		return(1);
	}

	// mlx_image_t* mlx_texture_to_image(mlx_t* mlx, mlx_texture_t* texture);
	// convertir la texture en une image mlx 
	mlx_image_t *image = mlx_texture_to_image(mlx, texture);
	if (!image)
	{
		printf("Error de conversion en image\n");
		return(1);
	}
	
	// affiche l'image dans la fenetre a la position (0.0)
	mlx_image_to_window(mlx, image, 0, 0);
	
    // Démarrer la boucle d'événements
    mlx_loop(mlx);

    // Terminer MLX avant de quitter
    mlx_terminate(mlx);
    return (0);
}


// //recuperer la map.ber = ouvrir , lire, traiter le contenu de la map
// // une ligne = un node
// // mettre dans une liste chainee 

// char *map = get_next_line() // recupere ligne par ligne de la map

