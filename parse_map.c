/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:34:32 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/11 18:02:23 by nolecler         ###   ########.fr       */
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





// Verifie qu'il y a un chemin valide cad on peut aller de P a E tout en collectant les C = flood fill (recursion)
// si C ou P ou E est entoure de mur = carte invalide
// verifie que C , E, P n'est pas entoure que des murs



// void	flood_fill(t_game *game, int move_x, int move_y)
// {
// 	if (move_x < 0 || move_y < 0 || move_x >= game->colum
// 		|| move_y >= game->row || game->mapcopy[move_x][move_y] == '1'
// 			|| game->mapcopy[move_x][move_y] == 'X')
// 		return ;
// 	if (((game->mapcopy[move_x + 1][move_y] == 'E')
// 		|| (game->mapcopy[move_x - 1][move_y] == 'E'))
// 		&& ((game->mapcopy[move_x][move_y + 1] == '1')
// 			|| (game->mapcopy[move_x][move_y - 1] == '1')))
// 		return ;
// 	if (((game->mapcopy[move_x][move_y + 1] == 'E')
// 		|| (game->mapcopy[move_x][move_y - 1] == 'E'))
// 		&& ((game->mapcopy[move_x + 1][move_y] == '1')
// 		|| (game->mapcopy[move_x - 1][move_y] == '1')))
// 		return ;
// 	if (game->mapcopy[move_x][move_y] == 'E' ||
// 		game->mapcopy[move_x][move_y] == 'C')
// 		game->mapcopy[move_x][move_y] = '0';
// 	game->mapcopy[move_x][move_y] = 'X';
// 	flood_fill(game, move_x - 1, move_y);
// 	flood_fill(game, move_x + 1, move_y);
// 	flood_fill(game, move_x, move_y - 1);
// 	flood_fill(game, move_x, move_y + 1);
// }

// bool mlx_resize_image(mlx_image_t* img, uint32_t nwidth, uint32_t nheight); (a proteger si jamais un echec)

// flood_fill met toute la carte a 1 : dessine le chemin valide.
// - a la position P : mettre a 1.
// - regarder en haut : sint	check_horizontal_walls(char *line)i c'est 0 , on le transforme en 1, si c'est 1 on regarde a droite, puis en bas et a gauche.
// - regarder a droite : si c'est 0 , on le transforme en 1, si c'est 1 on regarde en haut, si c'est 1 en haut on regarde a droite.
// - regarder en bas : si c'est 0 , on le transforme en 1, si c'est 1 on regarde .
// - regarder a gauche : si c'est 0 , on le transforme en 1, si c'est 1 on regarde .
// tant qu'on trouve 0 on continue a explorer . La recursivite s'arrete quand il n'y a plus que des 1 et retourne a celui d'avant et ainsi de suite.

// Apres avoir passer flood fill, on verifier la map ligne par ligne , s'il reste des C ou 0 , la carte n'est pas valide car cela veut dire que l'on a pas tout collectee.

// une fois la carte valide , on commence a deplacer le personnage.

