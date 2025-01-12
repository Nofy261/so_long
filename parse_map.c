/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:34:32 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/12 19:01:41 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// creer une fonction qui verifie que la carte est entouree de 1
int	check_horizontal_walls(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
		{
			ft_putstr("Error: horizontal wall is not surrounded by walls\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int check_vertical_walls(t_game *game)
{
    int j;
    int last_col;

    j = 0;
    last_col = ft_strlen(game->map[0]) - 1;
    while (game->map[j])
    {
        if (game->map[j][0] != '1')
        {
            ft_putstr("Error: Left wall is not surrounded by walls\n");
            //ft_free(game->map);
            free(game);
            return (1);
        }
        if (game->map[j][last_col] != '1')
        {
            ft_putstr("Error: Right wall is not surrounded by walls\n");// Ne s'affiche pas en erreur a revoir
            //ft_free(game->map);
            free(game);
            return (1);
        }
        j++;
    }
    return (0);
}

int check_form(t_game *game)
{   
    int  i;
    int  j;
    int  size;

    i = 0;
    j = 0;
    while (game->map[i][j])
        j++;
    size = j;
    while (i < game->height)
    {
        j = 0;
        while (game->map[i][j])
            j++;
        if (j != size)
        {
            ft_putstr("Error: Invalid form of map\n");
            return (1);
        }
        i++;
    }
    return (0);
}


int check_invalid_elements(t_game *game)
{
	int	i;
    int j;

    j = 0;
	i = 0;
    while (i < game->height)
    {
        j = 0;
	    while (game->map[i][j])
	    {
		    if (game->map[i][j] != '0' && game->map[i][j] != 'P' && game->map[i][j] != 'C' && game->map[i][j] != 'E' && game->map[i][j] != '1')
		    {
		    	ft_putstr("Error: Unknown element\n");
			    return (1);
		    }
		    j++;
        }
        i++;
	}
	return (0);
}






// largeur de la carte au cas ou c'est necessaire
// int	get_map_width(char *line)
// {
// 	int	i;
//     int width;

//     width = 0;
// 	i = 0;
// 	while (line[i])
// 		i++;
//     width = i + 1;
// 	return (width);
// }

// int	get_map_width(const char *path)
// {
// 	int		fd;
// 	int		width;/height); (a proteger si jamais un echec)
// 	if (fd < 0)
// 		ft_putstr("Error opening map\n");
// 	line = get_next_line(fd);
// 	if (!line)
// 	{
// 		close(fd);
// 		return (0);
// 	}
// 	width = ft_strlen(line) - 1;
// 	free(line);
// 	close(fd);
// 	return (width);
// }




// Verifie qu'il y a un chemin valide cad on peut aller de P a E tout en collectant les C = flood fill (recursion)
// si C ou P ou E est entoure de mur = carte invalide
// verifie que C , E, P n'est pas entoure que des murs


// flood_fill met toute la carte a 1 : dessine le chemin valide.
// - a la position P : mettre a 1.
// - regarder en haut : sint	check_horizontal_walls(char *line)i c'est 0 , on le transforme en 1, si c'est 1 on regarde a droite, puis en bas et a gauche.
// - regarder a droite : si c'est 0 , on le transforme en 1, si c'est 1 on regarde en haut, si c'est 1 en haut on regarde a droite.
// - regarder en bas : si c'est 0 , on le transforme en 1, si c'est 1 on regarde .
// - regarder a gauche : si c'est 0 , on le transforme en 1, si c'est 1 on regarde .
// tant qu'on trouve 0 on continue a explorer . La recursivite s'arrete quand il n'y a plus que des 1 et retourne a celui d'avant et ainsi de suite.

// Apres avoir passer flood fill, on verifier la map ligne par ligne , s'il reste des C ou 0 , la carte n'est pas valide car cela veut dire que l'on a pas tout collectee.

// une fois la carte valide , on commence a deplacer le personnage.

void     flood_fill(int x, int y, t_game *game)
{
    game->mapcopy[y][x] = '1';
	if (game->mapcopy[y - 1][x] != '1')
	{
		game->mapcopy[y - 1][x] = '1';
		flood_fill(x, y - 1, game);
	}
	if (game->mapcopy[y][x + 1] != '1')
	{
		game->mapcopy[y][x + 1] = '1';
		flood_fill(x + 1, y, game);
	}
	if (game->mapcopy[y + 1][x] != '1')
	{
		game->mapcopy[y + 1][x] = '1';
		flood_fill(x, y + 1, game);
	}
	if (game->mapcopy[y][x - 1] != '1')
	{
		game->mapcopy[y][x - 1] = '1';
		flood_fill(x - 1, y, game);
	}
}
// mettre toute la carte a 1
// apres cela , parcourir la carte et verifier si tout n'est pas = 1, la carte n'est pas valide
// parcourir la carte , tab de tab , returne un int 0 si tout est 1 et retuen 1 si tout n est as a 1 

int validate_pathfinder(t_game *game)
{
    flood_fill(game->player_x, game->player_y, game);
    int	i;
    int j;

	i = 0;
    //while (i < game->height)
    while(game->mapcopy[i])
    {
        j = 0;
	    while (game->mapcopy[i][j])
	    {
		    if (game->mapcopy[i][j] == 'C')
		    {
		    	ft_putstr("Error: Items still uncollected.\n");
			    return (1);
		    }
            if (game->mapcopy[i][j] == 'E')
		    {
		    	ft_putstr("Error: door inaccessible\n");
			    return (1);
		    }
		    j++;
        }
        i++;
	}
	return (0);   
}


//parsing texture





