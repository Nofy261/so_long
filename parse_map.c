/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:34:32 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/05 16:36:28 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// revoir les noms des fonctions et l'ordre

// creer une fonction qui verifie que la carte est entouree de 1
int	check_horizontal_walls(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1') // Erreur : un mur est absent
			return (1);
		i++;
	}
	return (0); // Les murs sont valides
}

// creer une fct qui verifie que les bords a gauche et a droite est bien  = 1
int check_vertical_walls(t_game *map)
{
	// !!! syntaxe de structure 
	// map[0][0] = 1 et map[0][size - 1] = 1;
	// j'incremente un int i de 0 jusqu'a la hauteur et je verifie si i = 1 sinon erreur et la carte n'est pas valide 
	//  cad tant que i < height ; i++
}

// Verifie que c'est rectangle
int check_form(t_game *map)
{
	// taille de la hauteur < taille de largeur = valide sinon erreur; 
	// les lignes ont la meme longueur
}

// verifie que la carte ne contient pas autre chose que P , E, C
int check_elements(char *map) // a renommer
{
	// parcourir la map jusqu a la fin '\0' et verifier s'il rencontre un P , E, C = valide sinon erreur
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '0' && map[i] != 'P' && map[i] != 'C' && map[i] != 'E' && map[i] != '1')
			return (1); // erreur 
			// afficher un message d'erreur ou pas??
		i++;
	}
	return (0);
}

//verifie que P, E, C, sont bien present dans la carte : Mettre cette verification en 1er
// verifier le tableau entier et non seulement ligne par ligne char **map ou char *map??

int validate_map_elements(char *map) // plutot char **map??? donc rajouter la hauteur en parametre
{
	int	i;
	int	count_p;
	int	count_e;
	int	count_c;

	i = 0;
	count_p = 0;
	count_e = 0;
	count_c = 0;
	
	//pour chaque ligne de la carte
	// pour chaque caractere de la ligne
	while (map[i]) // la on parcours que la premiere ligne de la carte
	{
		if (map[i] == 'P')
			count_p++;
		else if (map[i] == 'E')
			count_e++;
		else if (map[i] == 'C')
			count_c++;
		i++;
	}
	if (count_p != 1 || count_e != 1 || count_c < 1)
		return (1); // + message d'erreur ou pas??
	return (0);
}

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
// - regarder en haut : si c'est 0 , on le transforme en 1, si c'est 1 on regarde a droite, puis en bas et a gauche.
// - regarder a droite : si c'est 0 , on le transforme en 1, si c'est 1 on regarde en haut, si c'est 1 en haut on regarde a droite.
// - regarder en bas : si c'est 0 , on le transforme en 1, si c'est 1 on regarde .
// - regarder a gauche : si c'est 0 , on le transforme en 1, si c'est 1 on regarde .
// tant qu'on trouve 0 on continue a explorer . La recursivite s'arrete quand il n'y a plus que des 1 et retourne a celui d'avant et ainsi de suite.

// Apres avoir passer flood fill, on verifier la map ligne par ligne , s'il reste des C ou 0 , la carte n'est pas valide car cela veut dire que l'on a pas tout collectee.

// une fois la carte valide , on commence a deplacer le personnage.

