/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:31:09 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/14 11:42:57 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3DSTRUCT_H
#define CUB3DSTRUCT_H

typedef struct s_side
{
    double he;
    double he_tmp;
    double he_tmp2;
    double wi;
    double wi_tmp;
    double wi_tmp2;
    int north;
    int south;
    int east;
    int west;
    int north_s;
    int south_s;
    int east_s;
    int west_s;
    unsigned char pixel[4];
}				t_side;

typedef struct s_screen
{
	int x;
	int y;
    int i;
    int j;
	int *i_bis;
	int i_bis2;
}				t_screen;

typedef struct s_bitmap
{
    int r;
	int g;
	int b;
	int a;
	int resfield;
	int offset;
	int size;
	unsigned short plane;
	unsigned short depth;
	int compression;
	int zero;
	int len;
	int filesize;
}               t_bitmap;

typedef struct s_ids
{
    void *mlx_ptr;
    void *mlx_win;
    void *img_ptr;
	void *sprite_ptr;
    char *img_data;
    int img_bpp;
    int img_size_line;
    int img_endian;
    int xpm_bpp;
    int xpm_size_line;
    int xpm_endian;
    char **map;
    void *xpm_img;
    void *xpm_img2;
    void *xpm_img3;
    void *xpm_img4;
    void *xpm_sprite;
    char *xpm_data;
    char *xpm_data2;
    char *xpm_data3;
    char *xpm_data4;
    char *xpm_data_sprite;
	char *sprite_img_data;
}              t_ids;

typedef struct s_player
{
    int gnl;
    float dist_to_wall;
    char *xpm_path_no;
    char *xpm_path_so;
    char *xpm_path_we;
    char *xpm_path_ea;
    char *xpm_path_sp;
    int ceil_color[4];
    int floor_color[4];
    int map_start;
    int bool_start;
    int save;
	int len;
	int nb_sprites;
	int cat_sprite;
	float **sprite;
	float opp;
	int tmp_h;
	int tmp_w;
	int i_sprite;
	int j_sprite;
	int table_lenght;
	int max;
	int start;
	int start2;
    float angle;
	char p;
    char p2;
	int bool2;
	int bool4;
	int bool5;
	int bool6;
	int stock_i_bis;
	int bool_right;
	int bool_left;
	char p_bis;
	int draw;
	float lenght;
	int bool_sprite;
	float distance;
    int draw_sprite;
    int wall_h;
    int boolean;
    int color;
   // char **sprite;
    double x;
	double y;
    double ray_x;
    double ray_x2;
    double ray_y;
    double ray_y2;
    int ry;
    int rx;
    int ry2;
    int rx2;
    int ry_s;
    int rx_s;
	float teta;
    t_ids ids;
    t_screen struct_screen;
    t_side struct_side;
    t_bitmap bitmap;
    char **map;
}				t_player;

#endif
