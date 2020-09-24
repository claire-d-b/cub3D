#include "cub3d.h"

int		create_sprite_tab(t_player *player)
{
	int count;
	int j;

	count = -1;
	j = -1;
	if (!(player->sprite = malloc(sizeof(float *) * (player->max *
	player->table_lenght + 1))))
		return (0);
	while (++count < player->max * player->table_lenght)
	{
		if (!(player->sprite[count] = malloc(sizeof(float) * 15)))
			return (0);
		while (++j < 14)
			player->sprite[count][j] = 0;
	}
	player->sprite[count] = NULL;
	return (0);
}

void	register_sprite_start(int i, t_player *player, float angle, float d)
{
	player->sprite[i][4] = player->ray_x + (d) * sin(angle);
	player->sprite[i][5] = player->ray_y + (d) * cos(angle);
	player->sprite[i][7] =
	player->struct_screen.i;
	player->sprite[i][10] = player->struct_screen.x / d;
	if (player->distance > player->sprite[i][10])
		player->sprite[i][10] = player->distance;
	player->nb_sprites++;
}

void	register_sprite_end(int i, t_player *player, float angle, float d)
{
	player->sprite[i][0] = player->ray_x + d * sin(angle);
	player->sprite[i][1] = player->ray_y + d * cos(angle);
	player->sprite[i][3] =
	player->struct_screen.i;
	player->sprite[i][13] = (player->sprite[i][13] == 0 && player->dist_wall
	> d * cos(fabs(angle - player->teta))) ?
	player->struct_screen.i : player->sprite[i][13];
	player->sprite[i][12] = (player->dist_wall >
	d * cos(fabs(angle - player->teta))) ?
	player->struct_screen.i : player->sprite[i][12];
	player->sprite[i][9] = (player->map[(int)(player->ray_x + (d - EPSILON)
	* sin(angle))][(int)(player->ray_y + (d - EPSILON) * cos(angle))] != '2'
	|| player->sprite[i][9] == 0) ?
		(player->struct_screen.x) / d : player->sprite[i][9];
	player->boolean = 0;
}

void	register_dist_minmax(t_player *player, float d, float angle, int i)
{
	if (((player->struct_screen.x) / (d * cos(fabs(angle - player->teta)))) >
	player->sprite[i][2] || player->sprite[i][2] == 0)
		player->sprite[i][2] = ((player->struct_screen.x) / (d * cos(fabs(angle
		- player->teta))));
	if (((player->struct_screen.x) / (d * cos(fabs(angle
		- player->teta))) > player->sprite[i][11] ||
	player->sprite[i][11] == 0))
		player->sprite[i][11] = (player->struct_screen.x) / (d * cos(fabs(angle
		- player->teta)));
	if ((player->struct_screen.x) / (d * cos(fabs(angle - player->teta))) <
	player->sprite[i][6] || player->sprite[i][6] == 0)
		player->sprite[i][6] = (player->struct_screen.x) / (d * cos(fabs(angle
		- player->teta)));
}
