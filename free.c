/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:51:58 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/22 15:14:38 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_struct(t_game *game)
{
	free(game);
	exit(1);
}

void	free_texture(t_game *game)
{
	mlx_delete_texture(game->textures.texture_carot);
	mlx_delete_texture(game->textures.texture_gate);
	mlx_delete_texture(game->textures.texture_wall);
	mlx_delete_texture(game->textures.texture_floor);
	mlx_delete_texture(game->textures.texture_rabit_end);
	mlx_delete_texture(game->textures.texture_rabit);
}

void	*ft_free(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

void	ft_free_all(t_game *game)
{
	ft_free(game->mapcopy);
	mlx_terminate(game->mlx);
	free_texture(game);
}
