/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:56:21 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/11 10:29:12 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void trim_newline(char *line)
{
    int len;
    
    len = ft_strlen(line);
    if (len > 0 && line[len - 1] == '\n')
        line[len - 1] = '\0';
}

static int get_map_height(const char *path)
{
    int fd;
    char *line;
    int height;
    
    height = 0;
    fd = open(path, O_RDONLY);
    if (fd < 0)
        return (-1); // Erreur si le fichier ne peut pas être ouvert
    while ((line = get_next_line(fd)) != NULL)
    {
        height++;
        free(line); // Libère la mémoire allouée par get_next_line
    }
    close(fd);
    return (height);
}

int open_map(const char *path, t_game *game)
{
    int fd;
    int i;
    int j;
    char *line;

    i = 0;
    j = 0;
    game->height = get_map_height(path);
    if (game->height <= 0)
    {
        ft_putstr("Error: Invalid map file\n");
        return (1);
    }
    fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        ft_putstr("Error: Map can't be opened or read\n");
        return (1);
    }
    game->map = ft_calloc(game->height + 1, sizeof(char *));
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

    // Nettoyage des lignes pour supprimer les '\n'
    while (j < game->height)
    {
        trim_newline(game->map[j]);
        j++;
    }
    return (0);
}
