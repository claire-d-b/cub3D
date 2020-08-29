

#include "cub3d.h"

void	init_struct_screen(t_player *player)
{
	player->struct_screen.x = -1;
	player->struct_screen.y = -1;
	player->struct_screen.i = 0;
	player->struct_screen.j = 0;
}

void	init_elements(t_player *player)
{
	int i;

	i = 0;
	player->key_r = 0;
	player->waste = 0;
	player->xpm_path_no = 0;
	player->xpm_path_so = 0;
	player->xpm_path_we = 0;
	player->xpm_path_ea = 0;
	player->xpm_path_sp = 0;
	while (i < 4)
	{
		player->ceil_color[i] = -1;
		player->floor_color[i] = -1;
		i++;
	}
}

void	init_struct_player(t_player *player)
{
	init_elements(player);
	player->map_start = 0;
	player->bool_start = 0;
	player->save = 0;
	player->nb_sprites = 0;
	player->sprite = 0;
	player->table_lenght = 0;
	player->max = 0;
	player->start = 0;
	player->p = 0;
	player->distance = 0;
	player->x = 0;
	player->y = 0;
	player->ray_x = 0;
	player->ray_y = 0;
	player->ry = 0;
	player->rx = 0;
	player->teta = 0;
	player->map = 0;
}

void	init_struct_side(t_player *player)
{
	player->struct_side.north = 0;
	player->struct_side.south = 0;
	player->struct_side.east = 0;
	player->struct_side.west = 0;
}
