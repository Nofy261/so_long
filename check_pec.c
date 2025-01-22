/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 22:48:06 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/22 13:45:06 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_collectible(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				game->count_c++;
			j++;
		}
		i++;
	}
	if (game->count_c < 1)
	{
		ft_putstr("Error: Missing collectible\n");
		return (1);
	}
	return (0);
}

int	check_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				game->count_p++;
			}
			j++;
		}
		i++;
	}
	if (game->count_p != 1)
	{
		ft_putstr("Error: Invalid number of player\n");
		return (1);
	}
	return (0);
}

int	check_exit(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
			{
				game->gate_x = j;
				game->gate_y = i;
				game->count_e++;
			}
			j++;
		}
		i++;
	}
	if (game->count_e != 1)
	{
		ft_putstr("Error: Invalid number of exit\n");
		return (1);
	}
	return (0);
}
