/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:20:09 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/05 17:46:07 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// mlx42
// affiche une fenetre 
// initialiser la bibliotheque mlx
// mlx_t* mlx_init(int32_t width, int32_t height, const char* title, bool resize)
// mlx_t* mlx = mlx_init(800, 600, "so_long", true); 
// Retour : Si l'initialisation réussit, un pointeur valide (mlx) est retourné. Sinon, NULL est retourné, ce qui signifie que quelque chose s'est mal passé.


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

//void mlx_resize_hook(mlx_t* mlx, mlx_resizefunc func, void* param);

/**
 * Generic loop hook for any custom hooks to add to the main loop. 
 * Executes a function per frame, so be careful.
 * 
 * @param[in] mlx The MLX instance handle.
 * @param[in] f The function.
 * @param[in] param The parameter to pass on to the function.
 * @returns Whether or not the hook was added successfully. 
 */