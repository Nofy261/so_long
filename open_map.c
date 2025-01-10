/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:56:21 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/10 22:25:05 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int open_map(const char *path, t_game *game)
{
    int fd;
    int i;
    char *line;

    i = 0;
    fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        ft_putstr("Error, map cant'be opened or read\n");
        return (1);
    }
    game->map = ft_calloc(1024, sizeof(char *)); // 1024 est une taille arbitraire maximale pour les lignes
    if (!game->map)
    {
        ft_putstr("Error: Memory allocation failed\n");
        close(fd);
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        game->map[i] = line; // Stocke la ligne dans game->map
        i++;
    }
    game->map[i] = NULL; // Termine le tableau avec un pointeur NULL
    close(fd);
    return (0);
}
