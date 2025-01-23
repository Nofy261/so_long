/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_and_read_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:56:21 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/23 13:58:54 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_map(int fd, t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		game->map[i] = line;
		game->mapcopy[i] = ft_strdup(line);
		if (!game->mapcopy[i])
		{
			ft_putstr("Error: Memory allocation failed during map reading\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	open_map(const char *path, t_game *game)
{
	int	fd;
	int	i;

	i = 0;
	get_height_and_width(path, game);
	if (game->height <= 0 || game->width <= 0)
	{
		ft_putstr("Error: Invalid size of map\n");
		return (1);
	}
	fd = open_file(path);
	if (fd < 0)
		return (1);
	if (allocate_map_memory(game) == 1 || read_map(fd, game) == 1)
	{
		close(fd);
		return (1);
	}
	close(fd);
	while (i < game->height)
	{
		trim_newline(game->map[i]);
		i++;
	}
	return (0);
}
