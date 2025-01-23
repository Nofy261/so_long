/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_open_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:33:55 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/23 14:40:56 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	trim_newline(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

void	get_height_and_width(const char *path, t_game *game)
{
	int		fd;
	char	*line;

	game->width = 0;
	game->height = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("First Error of opening map\n");
		if (game)
			free(game);
		exit(1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (game->height == 0)
			game->width = ft_strlen(line) - 1;
		game->height++;
		free(line);
	}
	close(fd);
}

int	allocate_map_memory(t_game *game)
{
	game->map = ft_calloc(game->height + 1, sizeof(char *));
	game->mapcopy = ft_calloc(game->height + 1, sizeof(char *));
	if (!game->map || !game->mapcopy)
	{
		ft_putstr("Error: Memory allocation failed\n");
		return (1);
	}
	return (0);
}

int	open_file(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_putstr("Second error of opening map\n");
	return (fd);
}
