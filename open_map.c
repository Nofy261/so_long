/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:56:21 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/10 16:55:59 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int open_map(const char *path)
{
    int fd;
    char *map;
    
    fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        ft_putstr("Error, map cant'be opened or read\n");
        return (1);
    }
    while (1)
    {
        map = get_next_line(fd);
        if (map == NULL)
            break;
        if (map[0] != '\0') // Vérifie que la ligne n'est pas vide
            ft_putstr(map);
        free (map);
    }
    close (fd);
    return (0);
}
