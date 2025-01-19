/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:56:21 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/19 17:08:36 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	trim_newline(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

static void	get_height_and_width(const char *path, t_game *game)
{
	int		fd;
	char	*line;
	int		width;
	int		height;

	width = 0;
	height = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Error opening map\n");
		exit(1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		if (height == 0)
			width = ft_strlen(line) - 1;
		height++;
		free(line);
	}
	close(fd);
	game->width = width;
	game->height = height;
}

int	open_map(const char *path, t_game *game)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	get_height_and_width(path, game);
	if (game->height <= 0 || game->width <= 0)
	{
		ft_putstr("Error: Invalid size of map\n");
		return (1);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Error opening map\n");
		return (1);
	}
	game->map = ft_calloc(game->height + 1, sizeof(char *));
	game->mapcopy = ft_calloc(game->height + 1, sizeof(char *));
	if (!game->map || !game->mapcopy)
	{
		ft_putstr("Error: Memory allocation failed\n");
		close(fd);
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		game->map[i] = line;                // Stocke la ligne dans game->map
		game->mapcopy[i] = ft_strdup(line); // copier la ligne pour mapcopy
		i++;
	}
	game->map[i] = NULL; // Termine le tableau avec un pointeur NULL
	game->mapcopy[i] = NULL;
	close(fd);
	i = 0;
	// Nettoyage des lignes pour supprimer les '\n'
	while (i < game->height)
	{
		trim_newline(game->map[i]);
		i++;
	}
	return (0);
}
