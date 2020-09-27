#include "cub3d.h"

void			set_image_data12_ew(t_player *player, int wall_h, char *path)
{
	if (ft_strncmp((const char *)path, "./text1.xpm",
	ft_strlen(path)) == 0)
	{
		player->data = player->ids.xpm_data;
		player->w = player->ids.xpm_img_w;
		player->h = player->ids.xpm_img_h;
		player->rx = (int)((get_decimals(player->struct_side.wi) *
		player->w) / 100);
		player->ry = (int)(((player->struct_screen.j -
		player->struct_screen.y / 2 + wall_h / 2) * player->h) / wall_h);
	}
	if (ft_strncmp((const char *)path, "./text2.xpm",
	ft_strlen(path)) == 0)
	{
		player->data = player->ids.xpm_data2;
		player->w = player->ids.xpm_img2_w;
		player->h = player->ids.xpm_img2_h;
		player->rx = (int)((get_decimals(player->struct_side.wi) *
		player->w) / 100);
		player->ry = (int)(((player->struct_screen.j -
		player->struct_screen.y / 2 + wall_h / 2) * player->h) / wall_h);
	}
}

void			set_image_data34_ew(t_player *player, int wall_h, char *path)
{
	if (ft_strncmp((const char *)path, "./text3.xpm",
	ft_strlen(path)) == 0)
	{
		player->data = player->ids.xpm_data3;
		player->w = player->ids.xpm_img3_w;
		player->h = player->ids.xpm_img3_h;
		player->rx = (int)((get_decimals(player->struct_side.wi) *
		player->w) / 100);
		player->ry = (int)(((player->struct_screen.j -
		player->struct_screen.y / 2 + wall_h / 2) * player->h) / wall_h);
	}
	if (ft_strncmp((const char *)path, "./text4.xpm",
	ft_strlen(path)) == 0)
	{
		player->data = player->ids.xpm_data4;
		player->w = player->ids.xpm_img4_w;
		player->h = player->ids.xpm_img4_h;
		player->rx = (int)((get_decimals(player->struct_side.wi) *
		player->w) / 100);
		player->ry = (int)(((player->struct_screen.j -
		player->struct_screen.y / 2 + wall_h / 2) * player->h) / wall_h);
	}
}

void			set_image_data12_ns(t_player *player, int wall_h, char * path)
{
	if (ft_strncmp((const char *)path, "./text1.xpm",
	ft_strlen(path)) == 0)
	{
		player->data = player->ids.xpm_data;
		player->w = player->ids.xpm_img_w;
		player->h = player->ids.xpm_img_h;
		player->rx = (int)((get_decimals(player->struct_side.he) *
		player->w) / 100);
		player->ry = (int)(((player->struct_screen.j -
		player->struct_screen.y / 2 + wall_h / 2) * player->h) / wall_h);
	}
	if (ft_strncmp((const char *)path, "./text2.xpm",
	ft_strlen(path)) == 0)
	{
		player->data = player->ids.xpm_data2;
		player->w = player->ids.xpm_img2_w;
		player->h = player->ids.xpm_img2_h;
		player->rx = (int)((get_decimals(player->struct_side.he) *
		player->w) / 100);
		player->ry = (int)(((player->struct_screen.j -
		player->struct_screen.y / 2 + wall_h / 2) * player->h) / wall_h);
	}
}

void			set_image_data34_ns(t_player *player, int wall_h, char *path)
{
	if (ft_strncmp((const char *)path, "./text3.xpm",
	ft_strlen(path)) == 0)
	{
		player->data = player->ids.xpm_data3;
		player->w = player->ids.xpm_img3_w;
		player->h = player->ids.xpm_img3_h;
		player->rx = (int)((get_decimals(player->struct_side.he) *
		player->w) / 100);
		player->ry = (int)(((player->struct_screen.j -
		player->struct_screen.y / 2 + wall_h / 2) * player->h) / wall_h);
	}
	if (ft_strncmp((const char *)path, "./text4.xpm",
	ft_strlen(path)) == 0)
	{
		player->data = player->ids.xpm_data4;
		player->w = player->ids.xpm_img4_w;
		player->h = player->ids.xpm_img4_h;
		player->rx = (int)((get_decimals(player->struct_side.he) *
		player->w) / 100);
		player->ry = (int)(((player->struct_screen.j -
		player->struct_screen.y / 2 + wall_h / 2) * player->h) / wall_h);
	}
}

void			pick_pixels_in_texture(int w, int h, t_player *player)
{
	if (((((player->ry * w * 4) + (player->rx * 4) + 3))) <=
	(w * h * 4) && (((player->ry * w * 4) + (player->rx * 4))) >= 0)
	{
		player->struct_side.pixel[0] = player->data[((((player->ry * w * 4)) +
		(player->rx * 4)))];
		player->struct_side.pixel[1] = player->data[((((player->ry * w * 4)) +
		(player->rx * 4))) + 1];
		player->struct_side.pixel[2] = player->data[((((player->ry * w * 4)) +
		(player->rx * 4))) + 2];
		player->struct_side.pixel[3] = player->data[((((player->ry * w * 4)) +
		(player->rx * 4))) + 3];
	}
}
