/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:34:32 by nolecler          #+#    #+#             */
/*   Updated: 2025/01/04 11:36:40 by nolecler         ###   ########.fr       */
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
int check_vertical_walls(t_map *map)
{
	// !!! syntaxe de structure 
	// map[0][0] = 1 et map[0][size - 1] = 1;
	// j'incremente un int i de 0 jusqu'a la hauteur et je verifie si i = 1 sinon erreur et la carte n'est pas valide 
	//  cad tant que i < height ; i++
}

// Verifie que c'est rectangle
int check_form(t_map *map)
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
		if (map[i] != '0' || map[i] != 'P' || map[i] != 'C' || map[i] != 'E' || map[i] != '1')
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

// Verifie qu'il y a un chemin valide cad les 0 = flood fill 


