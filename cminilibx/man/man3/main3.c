#include "cub3D.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265359
#define VIEW_ANGLE M_PI/2
#define CELL_SIZE 64
#define EPSILON 0.02f
#define rotation 0.1f
#define player->table_lenght 33
#define player->max 25
#define move_right 100
#define move_left 115
#define move_up 97
#define move_down 119
#define left_arrow 65361
#define right_arrow 65363
#define key_press_ev 2
#define XPM_PATH "/home/claire/Desktop/texture.xpm"

init_struct_side(t_player *player)
{
//	player->struct_side.he = 0;
//	player->struct_side.wi = 0;
    player->struct_side.north = 0;
    player->struct_side.south = 0;
    player->struct_side.east = 0;
    player->struct_side.west = 0;
}

unsigned int	get_pixel(t_player *player, int x, int y)
{
	if (y > 0 && x > 0 && y < player->struct_screen.y && x < player->struct_screen.x)
	return (player->ids.xpm_data + (((player->struct_screen.x * y) + x) * player->ids.img_bpp));
}

unsigned int rgb3(unsigned int r, unsigned int g, unsigned int b) {
    return (r * 256*256) + (g * 256) + b;
}

void	camera_right(int keycode, t_player *player)
{
	if (player->teta < -M_PI)
		player->teta = M_PI;
	player->teta-=rotation;
//	init_struct_side(player);
}

void	camera_left(int keycode, t_player *player)
{
	if (player->teta > M_PI)
		player->teta = -M_PI;
	player->teta+=rotation;
//	init_struct_side(player);
    printf("player teta %f\n", player->teta);
}

void	walk_up(int keycode, t_player *player)
{
	if (player->teta >= 0)
	{
		if (player->teta >= 0 && player->teta < M_PI / 4)
    	player->x = (player->map[(int)((player->x + CELL_SIZE)/ CELL_SIZE)][(int)(player->y / 
		CELL_SIZE)] != '1' && (int)((player->x + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x + CELL_SIZE) / 
		CELL_SIZE) < player->table_lenght) ? player->x + CELL_SIZE : player->x;
		else if (player->teta >= M_PI / 4 && player->teta < M_PI / 1.5)
			player->y = (player->map[(int)(player->x / CELL_SIZE)][(int)((player->y - CELL_SIZE) / 
		CELL_SIZE)] != '1' && (int)((player->y - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y - CELL_SIZE) / 
		CELL_SIZE) < player->max) ? player->y - CELL_SIZE : player->y;
		else
			player->x = (player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE)][(int)(player->y / 
		CELL_SIZE)] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) / 
		CELL_SIZE) < player->table_lenght) ? player->x - CELL_SIZE : player->x;
	}
	else
	{
		if (player->teta >= -M_PI && player->teta < -M_PI / 1.5)
			player->x = (player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE)][(int)(player->y / 
		CELL_SIZE)] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) / 
		CELL_SIZE) < player->table_lenght) ? player->x - CELL_SIZE : player->x;
		else if (player->teta >= (-M_PI / 1.5) && player->teta < -M_PI / 4)
			player->y = (player->map[(int)(player->x / CELL_SIZE)][(int)((player->y + CELL_SIZE) / 
		CELL_SIZE)] != '1' && (int)((player->y + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y + CELL_SIZE) / 
		CELL_SIZE) < player->max) ? player->y + CELL_SIZE : player->y;
		else
			player->x = (player->map[(int)((player->x + CELL_SIZE) / CELL_SIZE)][(int)(player->y / 
		CELL_SIZE)] != '1' && (int)((player->x + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x + CELL_SIZE) / 
		CELL_SIZE) < player->table_lenght) ? player->x + CELL_SIZE : player->x;
	}
}

void	walk_down(int keycode, t_player *player)
{
	if (player->teta >= 0)
	{
		if (player->teta >= 0 && player->teta < M_PI / 4)
    	player->x = (player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE)][(int)(player->y / 
		CELL_SIZE)] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) / 
		CELL_SIZE) < player->table_lenght) ? player->x - CELL_SIZE : player->x;
		else if (player->teta >= M_PI / 4 && player->teta < M_PI / 1.25)
			player->y = (player->map[(int)(player->x / CELL_SIZE)][(int)((player->y + CELL_SIZE) / 
		CELL_SIZE)] != '1' && (int)((player->y + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y + CELL_SIZE) / 
		CELL_SIZE) < player->max) ? player->y + CELL_SIZE : player->y;
		else
			player->x = (player->map[(int)((player->x + CELL_SIZE) / CELL_SIZE)][(int)(player->y / 
		CELL_SIZE)] != '1' && (int)((player->x + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x + CELL_SIZE) / 
		CELL_SIZE) < player->table_lenght) ? player->x + CELL_SIZE : player->x;
	}
	else
	{
		if (player->teta >= -M_PI && player->teta < -M_PI / 1.25)
			player->x = (player->map[(int)((player->x + CELL_SIZE) / CELL_SIZE)][(int)(player->y / 
		CELL_SIZE)] != '1' && (int)((player->x + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x + CELL_SIZE) / 
		CELL_SIZE) < player->table_lenght) ? player->x + CELL_SIZE : player->x;
		else if (player->teta >= (-M_PI / 1.25) && player->teta < -M_PI / 4)
			player->y = (player->map[(int)(player->x / CELL_SIZE)][(int)((player->y - CELL_SIZE) / 
		CELL_SIZE)] != '1' && (int)((player->y - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y - CELL_SIZE) / 
		CELL_SIZE) < player->max) ? player->y - CELL_SIZE : player->y;
		else
			player->x = (player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE)][(int)(player->y / 
		CELL_SIZE)] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) / 
		CELL_SIZE) < player->table_lenght) ? player->x - CELL_SIZE : player->x;
	}
}

void	walk_right(int keycode, t_player *player)
{
    	if (player->teta >= 0)
	{
		if (player->teta >= 0 && player->teta < M_PI / 4)
    	player->y = (player->map[(int)(player->x / CELL_SIZE)][(int)((player->y - CELL_SIZE) / 
		CELL_SIZE)] != '1' && (int)((player->y - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y - CELL_SIZE) / 
		CELL_SIZE) < player->max) ? player->y - CELL_SIZE : player->y;
		else if (player->teta >= M_PI / 4 && player->teta < M_PI / 1.25)
			player->x = (player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE)][(int)(player->y / 
		CELL_SIZE)] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) / 
		CELL_SIZE) < player->table_lenght) ? player->x - CELL_SIZE : player->x;
		else
			player->y = (player->map[(int)(player->x / CELL_SIZE)][(int)((player->y + CELL_SIZE) / 
		CELL_SIZE)] != '1' && (int)((player->y + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y + CELL_SIZE) / 
		CELL_SIZE) < player->max) ? player->y + CELL_SIZE : player->y;
	}
	else
	{
		if (player->teta >= -M_PI && player->teta < -M_PI / 1.25)
			player->y = (player->map[(int)(player->x / CELL_SIZE)][(int)((player->y + CELL_SIZE) / 
		CELL_SIZE)] != '1' && (int)((player->y + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y + CELL_SIZE) / 
		CELL_SIZE) < player->max) ? player->y + CELL_SIZE : player->y;
		else if (player->teta >= (-M_PI / 1.25) && player->teta < -M_PI / 4)
			player->x = (player->map[(int)((player->x + CELL_SIZE) / CELL_SIZE)][(int)(player->y / 
		CELL_SIZE)] != '1' && (int)((player->x + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x + CELL_SIZE) / 
		CELL_SIZE) < player->table_lenght) ? player->x + CELL_SIZE : player->x;
		else
			player->y = (player->map[(int)(player->x / CELL_SIZE)][(int)((player->y - CELL_SIZE) / 
		CELL_SIZE)] != '1' && (int)((player->y - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y - CELL_SIZE) / 
		CELL_SIZE) < player->max) ? player->y - CELL_SIZE : player->y;
	}
}

void	walk_left(int keycode, t_player *player)
{
    	if (player->teta >= 0)
	{
		if (player->teta >= 0 && player->teta < M_PI / 4)
    	player->y = (player->map[(int)(player->x / CELL_SIZE)][(int)((player->y + CELL_SIZE) / 
		CELL_SIZE)] != '1' && (int)((player->y + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y + CELL_SIZE) / 
		CELL_SIZE) < player->max) ? player->y + CELL_SIZE : player->y;
		else if (player->teta >= M_PI / 4 && player->teta < M_PI / 1.5)
			player->x = (player->map[(int)((player->x + CELL_SIZE) / CELL_SIZE)][(int)(player->y 
			 / CELL_SIZE)] != '1' && (int)((player->x + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x + 
			 CELL_SIZE) / CELL_SIZE) < player->table_lenght) ? player->x + CELL_SIZE : player->x;
		else
			player->y = (player->map[(int)(player->x / CELL_SIZE)][(int)((player->y - CELL_SIZE) / 
		CELL_SIZE)] != '1' && (int)((player->y - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y - CELL_SIZE) /
		CELL_SIZE) < player->max) ? player->y - CELL_SIZE : player->y;
	}
	else
	{
		if (player->teta >= -M_PI && player->teta < -M_PI / 1.5)
			player->y = (player->map[(int)(player->x / CELL_SIZE)][(int)((player->y - CELL_SIZE) / 
		CELL_SIZE)] != '1' && (int)((player->y - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y - CELL_SIZE) / 
		CELL_SIZE) < player->max) ? player->y - CELL_SIZE : player->y;
		else if (player->teta >= (-M_PI / 1.5) && player->teta < -M_PI / 4)
			player->x = (player->map[(int)((player->x - CELL_SIZE) / CELL_SIZE)][(int)(player->y / 
		CELL_SIZE)] != '1' && (int)((player->x - CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->x - CELL_SIZE) / 
		CELL_SIZE) < player->table_lenght) ? player->x - CELL_SIZE : player->x;
		else
			player->y = (player->map[(int)(player->x / CELL_SIZE)][(int)((player->y + CELL_SIZE) / 
		CELL_SIZE)] != '1' && (int)((player->y + CELL_SIZE) / CELL_SIZE) > 1 && (int)((player->y + CELL_SIZE) / 
		CELL_SIZE) < player->max) ? player->y + CELL_SIZE : player->y;
	}
}
/*
void     event_management(t_ids *refs, char **map, t_player *player, t_screen screen)
{
    printf("refs ev !!!!! %d\n", refs->ev);
    if (refs->ev == right_arrow)
		camera_right(player, screen, map, refs);
	if (refs->ev == left_arrow)
		camera_left(player, screen, map, refs);
	if (refs->ev == move_up)
		walk_up(player, screen, map, refs);
	if (refs->ev == move_down)
		walk_down(player, screen, map, refs);
	if (refs->ev == move_right)
		walk_right(player, screen, map, refs);
	if (refs->ev == move_left)
		walk_left(player, screen, map, refs);
    display_view(map, player, screen, refs);
}*/

int		key_press(int keycode, t_player *player)
{
		if (keycode == right_arrow)
			camera_right(keycode, player);
		if (keycode == left_arrow)
			camera_left(keycode, player);
		if (keycode == move_up)
			walk_left(keycode, player);
		if (keycode == move_down)
			walk_right(keycode, player);
		if (keycode == move_right)
			walk_down(keycode, player);
		if (keycode == move_left)
			walk_up(keycode, player);
   display_view(player->map, player, player->struct_screen, &player->ids);
  return (0);
}

void display_map(char **map)
{
	int i = 0;
	int j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		i++;
		j = 0;
	}
}

// ange en radian
float raycast(t_player *player, char **map, float angle)
{
	float d;
	char p = '0';
	int x, y;
	double count = 0;

	x = player->x / CELL_SIZE;
	y = player->y / CELL_SIZE;
	d = 0;
	player->struct_side.an = angle;
//	init_struct_side(player);
	while (p != '1')
	{
		if ((int)(x + d * sin(angle)) > player->table_lenght || (int)(x + d * sin(angle)) < 0)
			break;
		if ((int)(y + d * cos(angle)) > player->max || (int)(y + d * cos(angle)) < 0)
			break;

		p = map[(int)(x + d * sin(angle))][(int)(y + d * cos(angle))];
		
		d += EPSILON;	
	}
		player->struct_side.he_tmp = player->struct_side.he;
		player->struct_side.wi_tmp = player->struct_side.wi;
		player->struct_side.he = (int)(x + d * sin(angle));
		player->struct_side.wi = (int)(y + d * cos(angle));
		if (player->struct_side.distance > d && angle < VIEW_ANGLE)
		{
		//	init_struct_side(player);
			player->struct_side.east = 1;
			player->struct_side.boolean = 1;
		}
		if (player->struct_side.distance > d && angle > -VIEW_ANGLE)
		{
		//	init_struct_side(player);
			player->struct_side.south = 1;
			player->struct_side.boolean = 2;
		}
		else if (player->struct_side.distance < d && angle > VIEW_ANGLE)
		{
		//	init_struct_side(player);
			player->struct_side.north = 1;
			player->struct_side.boolean = 3;
		}
		else if (player->struct_side.distance < d && angle < VIEW_ANGLE)
		{
		//	init_struct_side(player);
			player->struct_side.west = 1;
			player->struct_side.boolean = 4;
		}
		player->struct_side.distance = d;
		printf("diff he %d\n", player->struct_side.he - player->struct_side.he_tmp);
		printf("diff wi %d\n", player->struct_side.wi - player->struct_side.wi_tmp);
	return d * cos (fabs(angle - player->teta));
}

void display_view(char **map, t_player *player, t_screen screen, t_ids *refs)
{
	int i = 0;
	float teta;
	float dist;
	int y;
	double wall_h = 0;
	unsigned char pixel[4];
	unsigned int color;
	int wid = 0;
	int hei = 0;
//	unsigned int len = (unsigned int)ft_strlen(refs->xpm_data);
//	printf("strlen %d\n", screen.x * screen.y);
//	init_struct_side(player);
	while (i < screen.x)
	{
		teta = player->teta + VIEW_ANGLE/2 - i * VIEW_ANGLE / (float)screen.x;
		dist = raycast(player, map, teta);
		wall_h = (screen.y / 2) / dist;
		y = 0;
		// PRINT SKY
		while (y < screen.y / 2 - (int)wall_h) {
			mlx_pixel_put(refs->mlx_ptr, refs->mlx_win, i, y, 0x000000);
			y++;
		}
		// PRINT WALL
		while (y  < screen.y / 2 + (int)wall_h)
		{	
			if (player->struct_side.boolean == 1)
			{
			if (((int)(((y * screen.x * 4) + (i * 4) + 3))) <= (screen.x * screen.y * 4) && (int)(((y * screen.x * 4) + (i * 4))) >= 0)
			{pixel[0] = (unsigned int)refs->xpm_data[(y * screen.x * 4) + (i * 4)];
			pixel[1] = (unsigned int)refs->xpm_data[(y * screen.x * 4) + (i * 4) + 1];
			pixel[2] = (unsigned int)refs->xpm_data[(y * screen.x * 4) + (i * 4) + 2];
			pixel[3] = (unsigned int)refs->xpm_data[(y * screen.x * 4) + (i * 4) + 3];}
			color = rgb3(pixel[2], pixel[1], pixel[0]);
			mlx_pixel_put(refs->mlx_ptr, refs->mlx_win, i, y, color);}
			else if (player->struct_side.boolean == 2)
				mlx_pixel_put(refs->mlx_ptr, refs->mlx_win, i, y, 0x0097A7);
			else if (player->struct_side.boolean == 3)
				mlx_pixel_put(refs->mlx_ptr, refs->mlx_win, i, y, 0x000000);
			else if (player->struct_side.boolean == 4)
				mlx_pixel_put(refs->mlx_ptr, refs->mlx_win, i, y, 0xFFFFFF);
		//	printf("segf = %u\n", (y * screen.x * 4) + (i * 4) + 3);
		//	printf("strlen %d\n", ft_strlen(refs->xpm_data));
			y++;
		}
		// PRINT FLOOR
		while (y < screen.y)
		{
			mlx_pixel_put(refs->mlx_ptr, refs->mlx_win, i, y, 0x000000);
			y++;
		}
		i++;
	}

};

char **create_map(int i, char **map)
{
    int fd;
    char *line;
    int x;
    int y;

    y = 0;
    x = 0;
    fd = open("map2.txt", O_RDONLY); 
    if (!(map = malloc(sizeof(char *) * (player->table_lenght + 1))))
      return (0); 
    while (i = get_next_line(fd, &line))
    {
        if (!(map[y] = malloc(sizeof(char) * (player->max + 1))))
          return (0);
        while (x < ft_strlen(line)) 
        {
            map[y][x] = line[x]; 
            x++;
        }
        y++;
        x = 0;
        free(line); 
    }
    map[y] = line;
    map[y + 1] = 0;
    return (map);
}

int main() 
{
    char const *title;
    t_ids refs;
    t_ray ray;
	t_player player;
	t_screen screen;
	int keycode;
    int x;
    int y;
    char **map;
    int w;
    int h;
    
	player.x = 2 * CELL_SIZE + CELL_SIZE / 2;
	player.y = 3 * CELL_SIZE + CELL_SIZE / 2;
    printf("player.y %d\n", player.y);
    printf("player.x %d\n", player.x);
	player.teta = M_PI / 2;
	screen.x = 800;
	screen.y = 600;
    player.teta = 1;
	player.struct_screen.x = screen.x;
	player.struct_screen.y = screen.y;
    title = "cub3D";
    x = 0;
    y = 0;
    map = create_map(0, map); 
	player.map = map;
	player.struct_side.boolean = 0;
	display_map(map);
    refs.mlx_ptr = mlx_init(); 
	player.ids.mlx_ptr = refs.mlx_ptr;
    refs.mlx_win = mlx_new_window(refs.mlx_ptr, screen.x, screen.y, title);  
	player.ids.mlx_win = refs.mlx_win;
    refs.img_ptr = mlx_new_image(refs.mlx_ptr, screen.x, screen.y); 
	player.ids.img_ptr = refs.img_ptr;
    refs.img_data = mlx_get_data_addr(refs.img_ptr, &refs.img_bpp, 
    &refs.img_size_line, &refs.img_endian); 
	player.ids.img_data = refs.img_data;
	refs.xpm_img = mlx_xpm_file_to_image(refs.mlx_ptr, XPM_PATH, &screen.x, &screen.y);
	player.ids.xpm_img = refs.xpm_img;
	refs.xpm_data = mlx_get_data_addr(refs.xpm_img, &refs.img_bpp, 
    &refs.img_size_line, &refs.img_endian); 
	player.ids.xpm_data = refs.xpm_data;
    mlx_put_image_to_window(refs.mlx_ptr, refs.mlx_win, refs.img_ptr, 0, 0);
//	mlx_put_image_to_window(refs.mlx_ptr, refs.mlx_win, refs.xpm_img, 0, 0);
    mlx_key_hook(refs.mlx_win, &key_press, &player);
	display_view(map, &player, screen, &refs);
    mlx_hook(refs.mlx_win, key_press_ev, 0, &key_press, &player);
    mlx_loop(refs.mlx_ptr); 
}