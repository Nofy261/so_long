/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:33:19 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/21 11:07:55 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// gerer la taille d'une grande map dans flood fill(limiter)
// Makefile remake??
// image rabit_end

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		ft_putstr("Error: Invalid argument\n");
		return (1);
	}
	game = ft_calloc(sizeof(t_game), 1);
	if (!game)
	{
		ft_putstr("Error: Memory allocation failed\n");
		free(game);// ajout
		return (1);
	}
	verif_extension_ber(game, argv);
	if (open_map(argv[1], game) != 0)
	{
		ft_free(game->map);
		//free(game);// modif
		return (1);
	}
	if (map_conditions(game) == 1)
	{
		ft_free(game->map);
		//free_map(game);//ajout
		return (1);
	}
	game->mlx = mlx_init(game->width * SPRITE_PIXEL, game->height
			* SPRITE_PIXEL, "Rabit Party", true);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	display_map(game);
	mlx_key_hook(game->mlx, key_events, game);
	mlx_loop(game->mlx);
	//ft_free(game->map); // ajout
	ft_free(game->mapcopy); // ajout
	free_struct(game);// ajout
	//free(game);
	
	return (0);
}
