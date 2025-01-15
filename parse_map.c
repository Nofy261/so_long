/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:34:32 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/15 11:04:54 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	verif_extension_ber(t_game *game, char **argv)
{
    int len;

    len = ft_strlen(argv[1]);
	if ((len < 4) || ft_strncmp(&argv[1][len - 4], ".ber", 4) != 0)
	{
		free(game);
		ft_putstr("Error: Invalid file extension\n");
		exit(EXIT_FAILURE);
	}
}

int	check_horizontal_walls(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
		{
			ft_putstr("Error: horizontal wall is not surrounded by walls\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int check_vertical_walls(t_game *game)
{
    int j;
    int last_col;

    j = 0;
    last_col = ft_strlen(game->map[0]) - 1;
    while (game->map[j])
    {
        if (game->map[j][0] != '1')
        {
            ft_putstr("Error: Left wall is not surrounded by walls\n");
            //ft_free(game->map);
            free(game);
            return (1);
        }
        if (game->map[j][last_col] != '1')
        {
            ft_putstr("Error: Right wall is not surrounded by walls\n");
            //ft_free(game->map);
            free(game);
            return (1);
        }
        j++;
    }
    return (0);
}

int check_form(t_game *game)
{   
    int  i;
    int  j;
    int  size;

    i = 0;
    j = 0;
    while (game->map[i][j])
        j++;
    size = j;
    while (i < game->height)
    {
        j = 0;
        while (game->map[i][j])
            j++;
        if (j != size)
        {
            ft_putstr("Error: Invalid form of map\n");
            return (1);
        }
        i++;
    }
    return (0);
}


int check_invalid_elements(t_game *game)
{
	int	i;
    int j;

    j = 0;
	i = 0;
    while (i < game->height)
    {
        j = 0;
	    while (game->map[i][j])
	    {
		    if (game->map[i][j] != '0' && game->map[i][j] != 'P' && game->map[i][j] != 'C' && game->map[i][j] != 'E' && game->map[i][j] != '1')
		    {
		    	ft_putstr("Error: Unknown element\n");
			    return (1);
		    }
		    j++;
        }
        i++;
	}
	return (0);
}
