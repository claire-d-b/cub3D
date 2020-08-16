#include "cub3D.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265359
#define VIEW_ANGLE M_PI/2
#define CELL_SIZE 64
#define EPSILON 0.002f
#define player->table_lenght 32
#define player->max 24
#define move_right 100
#define move_left 115
#define move_up 97
#define move_down 119
#define left_arrow 65361
#define right_arrow 65363
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_MOUSE_PRESS	4
# define X_EVENT_MOUSE_RELEASE	5
# define X_EVENT_MOUSE_MOVE		6
# define X_EVENT_EXIT			17

typedef struct s_player
{
    int x;
	int y;
	float teta;
}				t_player;

typedef struct s_screen
{
	int x;
	int y;
}				t_screen;

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
};

void	camera_right(t_player player, t_screen screen, char **map, t_ids *refs)
{
	if (player.teta == 360)
		player.teta = VIEW_ANGLE;
	player.teta++;
}

void	camera_left(t_player player, t_screen screen, char **map, t_ids *refs)
{
	if (player.teta == 0)
		player.teta = VIEW_ANGLE;
	player.teta--;
	display_view(map, player, screen, refs);
}

void	walk_up(t_player player, t_screen screen, char **map, t_ids *refs)
{
	player.y = player.y + (1 / CELL_SIZE);
}

void	walk_down(t_player player, t_screen screen, char **map, t_ids *refs)
{
	printf("a");
	player.y = player.y - (1 / CELL_SIZE);
}

void	walk_right(t_player player, t_screen screen, char **map, t_ids *refs)
{
	player.x = player.x + (1 / CELL_SIZE);
}

void	walk_left(t_player player, t_screen screen, char **map, t_ids *refs)
{
	player.x = player.x - (1 / CELL_SIZE);
}

int		key_press(int keycode, t_player player, t_screen screen, char **map, t_ids *refs)
{
	if (keycode == right_arrow)
		camera_right(player, screen, map, refs);
	if (keycode == left_arrow)
		camera_left(player, screen, map, refs);
	if (keycode == move_up)
		walk_up(player, screen, map, refs);
	if (keycode == move_down)
		walk_down(player, screen, map, refs);
	if (keycode == move_right)
		walk_right(player, screen, map, refs);
	if (keycode == move_left)
		walk_left(player, screen, map, refs);
	printf("keycode = %d\n", keycode);
	return(keycode);
}

// ange en radian
float raycast(t_player player, char **map, float angle)
{
	float d;
	char p = '0';
	int x, y;

	x = player.x / CELL_SIZE;
	y = player.y / CELL_SIZE;
	d = 0;
	while (p != '1')
	{
		if ((int)(x + d * sin(angle)) >= player->max || (int)(x + d * sin(angle)) < 0)
			break;
		if ((int)(y + d * cos(angle)) >= player->table_lenght || (int)(y + d * cos(angle)) < 0)
			break;

		p = map[(int)(x + d * cos(angle))][(int)(y + d * sin(angle))];

		d += EPSILON;
	}
	return d * cos (fabs(angle - player.teta));
}

void display_view(char **map, t_player player, t_screen screen, t_ids *refs)
{
	int i = 0;
	float teta;
	float dist;
	int y;
	player.teta = 360;
	double wall_h = 0;

	while (i < screen.x)
	{
		teta = player.teta + VIEW_ANGLE/2 - i * VIEW_ANGLE / (float)screen.x;
		dist = raycast(player, map, teta);
		wall_h = (screen.y / 2) / dist;

		y = 0;
		// PRINT SKY
		while (y < screen.y / 2 - (int)wall_h) {
			mlx_pixel_put(refs->mlx_ptr, refs->mlx_win, i, y, 0x8C3131);
			y++;
		}
		// PRINT WALL
		while (y  < screen.y / 2 + (int)wall_h)
		{
			mlx_pixel_put(refs->mlx_ptr, refs->mlx_win, i, y, 0xFFFFFF);
			y++;
		}
		// PRINT FLOOR
		while (y < screen.y)
		{
			mlx_pixel_put(refs->mlx_ptr, refs->mlx_win, i, y, 0x8C3131);
			y++;
		}
		i++;
	}

};

char **create_map(int i, char **map) // fonction qui crée la carte avec les 1 et 0
{
    int fd;
    char *line;
    int x;
    int y;

    y = 0;
    x = 0;
    fd = open("map2.txt", O_RDONLY); //on ouvre le fichier texte map2.txt et on le lit
    if (!(map = malloc(sizeof(char *) * (player->table_lenght + 1))))
      return (0); 
    // on alloue la mémoire pour un double tableau en disant qu'il contient player->table_lenghteight
    // (32 définit tout en haut) lignes (ou tableaux simples), et on rajoute 1 pour pouvoir affecter 
    // à la dernière ligne du double tableau la valeur 0. Ca permet de le parcourir par la suite
    // tant que map[i] différent de 0
    while (i = get_next_line(fd, &line)) // get_next line est une fonction qui lit une ligne du document map2.txt
    // et qui renvoie 1. Elle remplit "line" avec la ligne considérée
    {
        if (!(map[y] = malloc(sizeof(char) * (player->max + 1))))
          return (0); //on alloue la mémoire pour chaque ligne du tableau dans une boucle (tant que get_next_line renvoie 1)
        while (x < ft_strlen(line)) //ft_strlen(line) correspond à la longueur de la ligne (qui est aussi un tableau simple ou une chaine de caractères)
        {
            map[y][x] = line[x]; //on remplit chaque ligne de notre carte avec ce que contient le fichier qu'on lit
            x++;
        }
        y++;
        x = 0;
        free(line); // on libère la mémoire de line dont on ne se sert plus
    }
    map[y] = line;
    map[y + 1] = 0; // on affecte la valeur 0 à la dernière ligne du tableau pour pouvoir le parcourir après
    return (map);
}

int main(int argc, char **argv) //fonction principale et qui permet d'afficher la fenetre
{
    char const *title;
    t_ids refs;
    t_ray ray;
	t_player player;
	t_screen screen;
    int x;
    int y;
    char **map;
    int w;
    int h;
	int keycode = 0;
    
	player.x = 2 * CELL_SIZE + CELL_SIZE / 2;
	player.y = 3 * CELL_SIZE + CELL_SIZE / 2;
	player.teta = M_PI / 2;
	screen.x = 800;
	screen.y = 600;
    title = "cub3D";
    x = 0;
    y = 0;
    map = create_map(0, map); // création de la carte
	display_map(map);
    refs.mlx_ptr = mlx_init(); // fonction de la librairie minilibx préalable à l'ouverture d'une fenêtre
    refs.mlx_win = mlx_new_window(refs.mlx_ptr, screen.x, screen.y, title); // fonction qui 
    //permet d'ouvrir une nouvelle fenêtre avec la largeur "realwidth" et la hauteur "realheight" 
    //définies tout en haut
    refs.img_ptr = mlx_new_image(refs.mlx_ptr, screen.x, screen.y); 
    refs.img_data = (int *)mlx_get_data_addr(refs.img_ptr, &refs.img_bpp, 
    &refs.img_size_line, &refs.img_endian); // fonctions permettant l'affichage d'images sur la fenêtre
    mlx_put_image_to_window(refs.mlx_ptr, refs.mlx_win, refs.img_ptr, 0, 0); //fonction qui affiche des choses dans la fenêtre
	display_view(map, player, screen, &refs);
	mlx_key_hook(refs.mlx_win, key_press, (void *)refs.ev);
	mlx_hook(refs.mlx_win, X_EVENT_KEY_PRESS, 1, key_press, (void *)refs.ev);
    mlx_loop(refs.mlx_ptr); // foncton finale qui coordonne toues les autres (affichage de fenêtre etc)
}