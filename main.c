/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:33:19 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/23 17:20:51 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_game	*init_game(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		ft_putstr_fd("Error: Invalid argument\n", 2);
		exit(EXIT_FAILURE);
	}
	game = ft_calloc(sizeof(t_game), 1);
	if (!game)
	{
		ft_putstr_fd("Error: Memory allocation failed\n", 2);
		exit(EXIT_FAILURE);
	}
	verif_extension_ber(game, argv);
	return (game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = init_game(argc, argv);
	if (open_map(argv[1], game) == 1)
	{
		ft_free_all(game);
		exit(EXIT_FAILURE);
	}
	map_conditions(game);
	game->mlx = mlx_init(game->width * SPRITE_PIXEL, game->height
			* SPRITE_PIXEL, "S0_LONG", true);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	if (!game->mlx)
	{
		ft_putstr_fd("Error: Mlx can't be created\n", 2);
		ft_free_all(game);
		return (1);
	}
	display_map(game);
	mlx_key_hook(game->mlx, key_events, game);
	mlx_loop(game->mlx);
	if (game)
		ft_free_all(game);
	return (0);
}
