/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 22:48:06 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/16 11:41:10 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_collectible(t_game *game)
{
    int i;
    int j;

    j = 0;
    while (game->map[j])
    {
        i = 0;
        while (game->map[j][i])
        {
            if (game->map[j][i] == 'C')
                game->count_c++;        
            i++;
        }
        j++;
    }
    if (game->count_c < 1)
    {
        ft_putstr("Error: Missing collectible\n");
        return (1);
    }
    return (0);  
}

int check_player(t_game *game)
{
    int i;
    int j;

    j = 0;
    while (game->map[j])
    {
        i = 0;
        while (game->map[j][i])
        {
            if (game->map[j][i] == 'P')
            {
                game->player_x = i;
                game->player_y = j;
                game->count_p++;
            }  
            i++;
        }
        j++;
    }
    if (game->count_p != 1)
    {
        ft_putstr("Error: Invalid number of player\n");
        return (1);
    }
    return (0);
}

int check_exit(t_game *game)
{
    int i;
    int j;

    j = 0;
    while (game->map[j])
    {
        i = 0;
        while (game->map[j][i])
        {
            if (game->map[j][i] == 'E')
            {
                game->gate_x = i;
                game->gate_y = j;
                game->count_e++;
            }        
            i++;
        }
        j++;
    }
    if (game->count_e != 1)
    {
        ft_putstr("Error: Invalid number of exit\n");
        return (1);
    }
    return (0);
}


