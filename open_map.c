/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:56:21 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/10 15:01:22 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int open_map(int fd, char *map)
{
	fd = open("map.ber", O_RDONLY);
	while (1)
	{
		map = get_next_line(fd);
		printf("%s", map); // ft_printf
		if (map == NULL)
			break;
		free (map);
	}
	close (fd);
	return (0);
}