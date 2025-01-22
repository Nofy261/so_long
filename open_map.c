/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:56:21 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/22 15:04:53 by nolecler         ###   ########.fr       */
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
		ft_putstr("First Error of opening map\n");
		//ft_free(game->map);
		if (game)
			free(game); //ajout
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

static int	allocate_map_memory(t_game *game)
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

static int	open_file(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_putstr("Second error of opening map\n");
	return (fd);
}

static int	read_map(int fd, t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		game->map[i] = line;
		game->mapcopy[i] = ft_strdup(line);
		if (!game->mapcopy[i])
		{
			ft_putstr("Error: Memory allocation failed during map reading\n");
			return (1);
		}
		i++;
	}
	game->map[i] = NULL;
	game->mapcopy[i] = NULL;
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

// int	open_map(const char *path, t_game *game)
// {
// 	int		fd;
// 	int		i;
// 	char	*line;

// 	i = 0;
// 	get_height_and_width(path, game);
// 	if (game->height <= 0 || game->width <= 0)
// 	{
// 		ft_putstr("Error: Invalid size of map\n");
// 		return (1);
// 	}
// 	fd = open(path, O_RDONLY);
// 	if (fd < 0)
// 	{
// 		ft_putstr("Error opening map\n");
// 		return (1);
// 	}
// 	game->map = ft_calloc(game->height + 1, sizeof(char *));
// 	game->mapcopy = ft_calloc(game->height + 1, sizeof(char *));
// 	if (!game->map || !game->mapcopy)
// 	{
// 		ft_putstr("Error: Memory allocation failed\n");
// 		close(fd);
// 		return (1);
// 	}
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		game->map[i] = line;
// 		game->mapcopy[i] = ft_strdup(line);
// 		i++;
// 	}
// 	game->map[i] = NULL;
// 	game->mapcopy[i] = NULL;
// 	close(fd);
// 	i = 0;
// 	while (i < game->height)
// 	{
// 		trim_newline(game->map[i]);
// 		i++;
// 	}
// 	return (0);
// }
