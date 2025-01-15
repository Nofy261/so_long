#include "so_long.h"

void    print_map(t_game *game)
{
    int i;

    i = 0; 
    while (game->map[i])
    {
        printf("%s\n", game->map[i]);
        i++;
    }
}
