/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:30:20 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/10 20:32:38 by nolecler         ###   ########.fr       */
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

