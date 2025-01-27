/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:30:20 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/23 16:15:18 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(int x, int y, t_game *game)
{
	game->mapcopy[y][x] = '1';
	if (game->mapcopy[y - 1][x] != '1')
	{
		game->mapcopy[y - 1][x] = '1';
		flood_fill(x, y - 1, game);
	}
	if (game->mapcopy[y][x + 1] != '1')
	{
		game->mapcopy[y][x + 1] = '1';
		flood_fill(x + 1, y, game);
	}
	if (game->mapcopy[y + 1][x] != '1')
	{
		game->mapcopy[y + 1][x] = '1';
		flood_fill(x, y + 1, game);
	}
	if (game->mapcopy[y][x - 1] != '1')
	{
		game->mapcopy[y][x - 1] = '1';
		flood_fill(x - 1, y, game);
	}
}

int	validate_flood_fill(t_game *game)
{
	int	i;
	int	j;

	flood_fill(game->player_x, game->player_y, game);
	i = 0;
	while (game->mapcopy[i])
	{
		j = 0;
		while (game->mapcopy[i][j])
		{
			if (game->mapcopy[i][j] == 'C')
			{
				ft_putstr_fd("Error: Items still uncollected.\n", 2);
				return (1);
			}
			if (game->mapcopy[i][j] == 'E')
			{
				ft_putstr_fd("Error: door inaccessible\n", 2);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	map_conditions(t_game *game)
{
	if (check_invalid_elements(game) == 1
		|| check_collectible(game) == 1
		|| check_exit(game) == 1
		|| check_player(game) == 1
		|| check_form(game) == 1
		|| check_horizontal_walls(game->map[0]) == 1
		|| check_horizontal_walls(game->map[game->height - 1]) == 1
		|| check_vertical_walls(game) == 1
		|| validate_flood_fill(game) == 1)
	{
		if (game->mapcopy)
			ft_free(game->mapcopy);
		if (game->map)
			ft_free(game->map);
		free(game);
		exit (1);
	}
	return (0);
}
