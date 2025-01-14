/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:30:20 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/14 15:41:05 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void     flood_fill(int x, int y, t_game *game)
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


int validate_flood_fill(t_game *game)
{
    flood_fill(game->player_x, game->player_y, game);
    int	i;
    int j;

	i = 0;
    while(game->mapcopy[i])
    {
        j = 0;
	    while (game->mapcopy[i][j])
	    {
		    if (game->mapcopy[i][j] == 'C')
		    {
		    	ft_putstr("Error: Items still uncollected.\n");
			    return (1);
		    }
            if (game->mapcopy[i][j] == 'E')
		    {
		    	ft_putstr("Error: door inaccessible\n");
			    return (1);
		    }
		    j++;
        }
        i++;
	}
	return (0);   
}

