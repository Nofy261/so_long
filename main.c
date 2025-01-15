/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:33:19 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/15 11:37:08 by nolecler         ###   ########.fr       */
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
    verif_extension_ber(game, argv);
    if (open_map(argv[1], game) != 0)
    {
        free(game);
        return (1);
    }
    if (check_invalid_elements(game) == 1)
        return (1);
    if (check_collectible(game) == 1)
        return (1);
    if (check_exit(game) == 1)
        return (1);
    if (check_player(game) == 1)
        return (1);
    if (check_form(game) == 1)
        return (1);
    if  (check_horizontal_walls(game->map[0]) == 1 || 
        check_horizontal_walls(game->map[game->height - 1]) == 1)
        return (1);
    if (check_vertical_walls(game) == 1)
        return (1);
    if (validate_flood_fill(game) == 1)
      return (1);
    game->mlx = mlx_init(game->width * SPRITE_PIXEL, game->height * SPRITE_PIXEL, "Rabbit Party", true);
    mlx_set_setting(MLX_STRETCH_IMAGE, true);
    display_map(game);
    mlx_loop(game->mlx);
    free(game);
    return (0);
}
