/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:20:09 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/05 16:32:43 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// mlx42
// affiche une fenetre 
// initialiser la bibliotheque mlx
// mlx_t* mlx_init(int32_t width, int32_t height, const char* title, bool resize)
// mlx_t* mlx = mlx_init(800, 600, "so_long", true); 

// 800, 600 définissent la largeur et la hauteur de la fenêtre (en pixels).
// "so_long" est le titre de la fenêtre.
// true : un booléen qui indique si la fenêtre doit être en plein écran (true) ou en mode fenêtre (false).
// true indique que MLX doit gérer le contexte graphique.
// mlx_t* mlx :

// mlx_t est un type défini par MLX pour représenter le contexte graphique.
// mlx est un pointeur qui stocke toutes les informations nécessaires pour gérer la fenêtre et son contenu.

// Retour : Si l'initialisation réussit, un pointeur valide (mlx) est retourné. Sinon, NULL est retourné, ce qui signifie que quelque chose s'est mal passé.


// #include <MLX42/MLX42.h>
// #include <stdio.h>

// int main(void)
// {
//     mlx_t* mlx = mlx_init(800, 600, "so_long", false);
//     if (!mlx)
//     {
//         fprintf(stderr, "Erreur : %s\n", mlx_strerror(mlx_errno));
//         return 1;
//     }

//     // Démarrer la boucle d'événements
//     mlx_loop(mlx);

//     // Terminer proprement MLX avant de quitter
//     mlx_terminate(mlx);
//     return 0;
// }