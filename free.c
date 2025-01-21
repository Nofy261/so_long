/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:51:58 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/21 09:52:14 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    free_texture(t_game *game)
{
    mlx_delete_texture(game->textures.texture_carot);
    mlx_delete_texture(game->textures.texture_gate);
    mlx_delete_texture(game->textures.texture_wall);
    mlx_delete_texture(game->textures.texture_floor);
    mlx_delete_texture(game->textures.texture_rabit_end);
    mlx_delete_texture(game->textures.texture_rabit);
}

void    free_struct(t_game *game)
{
    free_texture(game);
    mlx_terminate(game->mlx);
    if (game->map != NULL)
        ft_free(game->map);
    free(game);
}

