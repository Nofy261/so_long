/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:33:19 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/05 17:21:15 by nolecler         ###   ########.fr       */
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

int main(void)
{
    mlx_t* mlx = mlx_init(800, 600, "so_long", false);
    if (!mlx)
    {
        //fprintf(stderr, "Erreur : %s\n", mlx_strerror(mlx_errno));
		printf("Error\n");
        return (1);
    }
	//ajouter hook ici 

	
    // Démarrer la boucle d'événements
    mlx_loop(mlx);

    // Terminer MLX avant de quitter
    mlx_terminate(mlx);
    return (0);
}

// char	**map = recupere la totalite de la map
// //recuperer la map.ber = ouvrir , lire, traiter le contenu de la map
// // une ligne = un node
// // mettre dans une liste chainee 

// char *map = get_next_line() // recupere ligne par ligne de la map

