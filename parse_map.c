/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:34:32 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/03 16:05:51 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// creer une fonction qui verifie que la carte est entouree de 1
// creer une fct qui verifie que le premier et le dernier est bien 1 partout

int	check_wall(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '1') //on returne erreur et on arrete car la carte n'est pas valide
			return (1);
		i++;
	}
	return (0);
}
