/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:31:43 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/28 10:39:49 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	set_texture_sprite(t_player *player, int y, int i)
{
	unsigned int color;

	if (((((y * player->ids.xpm_sprite_w * 4) + (i * 4) + 3))) <=
	(player->ids.xpm_sprite_w * player->ids.xpm_sprite_h * 4) &&
	(((y * player->ids.xpm_sprite_w * 4) + (i * 4))) >= 0)
	{
		player->struct_side.pixel[0] =
		player->ids.xpm_data_sprite[((((y * (player->ids.xpm_sprite_w) * 4))
		+ (i * 4)))];
		player->struct_side.pixel[1] =
		player->ids.xpm_data_sprite[((((y * (player->ids.xpm_sprite_w) * 4))
		+ (i * 4))) + 1];
		player->struct_side.pixel[2] =
		player->ids.xpm_data_sprite[((((y * (player->ids.xpm_sprite_w) * 4))
		+ (i * 4))) + 2];
		player->struct_side.pixel[3] =
		player->ids.xpm_data_sprite[((((y * (player->ids.xpm_sprite_w) * 4))
		+ (i * 4))) + 3];
	}
	color = rgb3(player->struct_side.pixel[2], player->struct_side.pixel[1],
	player->struct_side.pixel[0]);
	return (color);
}

unsigned int	set_texture_east(t_player *player, int wall_h)
{
	unsigned int	color;
	char			*data;
	int				w;
	int				h;

	data = 0;
	w = 0;
	h = 0;
	if (ft_strncmp((const char *)player->xpm_path_ea, "./text1.xpm",
	ft_strlen(player->xpm_path_ea)) == 0)
	{
		data = player->ids.xpm_data;
		w = player->ids.xpm_img_w;
		h = player->ids.xpm_img_h;
		player->rx = (int)((get_decimals(player->struct_side.wi) *
		w) / 100);
		player->ry = (int)(((player->struct_screen.j -
		player->struct_screen.y / 2 + wall_h / 2) * h) / wall_h);
	}
	if (ft_strncmp((const char *)player->xpm_path_ea, "./text2.xpm",
	ft_strlen(player->xpm_path_ea)) == 0)
	{
		data = player->ids.xpm_data2;
		w = player->ids.xpm_img2_w;
		h = player->ids.xpm_img2_h;
		player->rx = (int)((get_decimals(player->struct_side.wi) *
		w) / 100);
		player->ry = (int)(((player->struct_screen.j -
		player->struct_screen.y / 2 + wall_h / 2) * h) / wall_h);
	}
	if (ft_strncmp((const char *)player->xpm_path_ea, "./text3.xpm",
	ft_strlen(player->xpm_path_ea)) == 0)
	{
		data = player->ids.xpm_data3;
		w = player->ids.xpm_img3_w;
		h = player->ids.xpm_img3_h;
		player->rx = (int)((get_decimals(player->struct_side.wi) *
		w) / 100);
		player->ry = (int)(((player->struct_screen.j -
		player->struct_screen.y / 2 + wall_h / 2) * h) / wall_h);
	}
	if (ft_strncmp((const char *)player->xpm_path_ea, "./text4.xpm",
	ft_strlen(player->xpm_path_ea)) == 0)
	{
		data = player->ids.xpm_data4;
		w = player->ids.xpm_img4_w;
		h = player->ids.xpm_img4_h;
		player->rx = (int)((get_decimals(player->struct_side.wi) *
		w) / 100);
		player->ry = (int)(((player->struct_screen.j -
		player->struct_screen.y / 2 + wall_h / 2) * h) / wall_h);
	}
	if (((((player->ry * w * 4) + (player->rx * 4) + 3))) <=
	(w * h * 4) && (((player->ry * w * 4) + (player->rx * 4))) >= 0)
	{
		player->struct_side.pixel[0] = data[((((player->ry * w * 4)) +
		(player->rx * 4)))];
		player->struct_side.pixel[1] = data[((((player->ry * w * 4)) +
		(player->rx * 4))) + 1];
		player->struct_side.pixel[2] = data[((((player->ry * w * 4)) +
		(player->rx * 4))) + 2];
		player->struct_side.pixel[3] = data[((((player->ry * w * 4)) +
		(player->rx * 4))) + 3];
	}
	color = rgb3(player->struct_side.pixel[2], player->struct_side.pixel[1],
	player->struct_side.pixel[0]);
	return (color);
}

unsigned int	set_texture_west(t_player *player, int wall_h)
{
unsigned int	color;
	char			*data;
	int				w;
	int				h;

	data = 0;
	w = 0;
	h = 0;
	if (ft_strncmp((const char *)player->xpm_path_we, "./text1.xpm",
	ft_strlen(player->xpm_path_we)) == 0)
	{
		data = player->ids.xpm_data;
		w = player->ids.xpm_img_w;
		h = player->ids.xpm_img_h;
		player->rx = (int)((get_decimals(player->struct_side.wi) *
		w) / 100);
		player->ry = (int)(((player->struct_screen.j -
		player->struct_screen.y / 2 + wall_h / 2) * h) / wall_h);
	}
	if (ft_strncmp((const char *)player->xpm_path_we, "./text2.xpm",
	ft_strlen(player->xpm_path_we)) == 0)
	{
		data = player->ids.xpm_data2;
		w = player->ids.xpm_img2_w;
		h = player->ids.xpm_img2_h;
		player->rx = (int)((get_decimals(player->struct_side.wi) *
		w) / 100);
		player->ry = (int)(((player->struct_screen.j -
		player->struct_screen.y / 2 + wall_h / 2) * h) / wall_h);
	}
	if (ft_strncmp((const char *)player->xpm_path_we, "./text3.xpm",
	ft_strlen(player->xpm_path_we)) == 0)
	{
		data = player->ids.xpm_data3;
		w = player->ids.xpm_img3_w;
		h = player->ids.xpm_img3_h;
		player->rx = (int)((get_decimals(player->struct_side.wi) *
		w) / 100);
		player->ry = (int)(((player->struct_screen.j -
		player->struct_screen.y / 2 + wall_h / 2) * h) / wall_h);
	}
	if (ft_strncmp((const char *)player->xpm_path_we, "./text4.xpm",
	ft_strlen(player->xpm_path_we)) == 0)
	{
		data = player->ids.xpm_data4;
		w = player->ids.xpm_img4_w;
		h = player->ids.xpm_img4_h;
		player->rx = (int)((get_decimals(player->struct_side.wi) *
		w) / 100);
		player->ry = (int)(((player->struct_screen.j -
		player->struct_screen.y / 2 + wall_h / 2) * h) / wall_h);
	}
	if (((((player->ry * w * 4) + (player->rx * 4) + 3))) <=
	(w * h * 4) && (((player->ry * w * 4) + (player->rx * 4))) >= 0)
	{
		player->struct_side.pixel[0] = data[((((player->ry * w * 4)) +
		(player->rx * 4)))];
		player->struct_side.pixel[1] = data[((((player->ry * w * 4)) +
		(player->rx * 4))) + 1];
		player->struct_side.pixel[2] = data[((((player->ry * w * 4)) +
		(player->rx * 4))) + 2];
		player->struct_side.pixel[3] = data[((((player->ry * w * 4)) +
		(player->rx * 4))) + 3];
	}
	color = rgb3(player->struct_side.pixel[2], player->struct_side.pixel[1],
	player->struct_side.pixel[0]);
	return (color);
}

unsigned int	set_texture_south(t_player *player, int wall_h)
{
	unsigned int	color;
	char			*data;
	int				w;
	int				h;

	data = 0;
	w = 0;
	h = 0;
	if (ft_strncmp((const char *)player->xpm_path_so, "./text1.xpm",
	ft_strlen(player->xpm_path_so)) == 0)
	{
		data = player->ids.xpm_data;
		w = player->ids.xpm_img_w;
		h = player->ids.xpm_img_h;
		player->rx = (int)((get_decimals(player->struct_side.he) *
		w) / 100);
		player->ry = (int)(((player->struct_screen.j -
		player->struct_screen.y / 2 + wall_h / 2) * h) / wall_h);
	}
	if (ft_strncmp((const char *)player->xpm_path_so, "./text2.xpm",
	ft_strlen(player->xpm_path_so)) == 0)
	{
		data = player->ids.xpm_data2;
		w = player->ids.xpm_img2_w;
		h = player->ids.xpm_img2_h;
		player->rx = (int)((get_decimals(player->struct_side.he) *
		w) / 100);
		player->ry = (int)(((player->struct_screen.j -
		player->struct_screen.y / 2 + wall_h / 2) * h) / wall_h);
	}
	if (ft_strncmp((const char *)player->xpm_path_so, "./text3.xpm",
	ft_strlen(player->xpm_path_so)) == 0)
	{
		data = player->ids.xpm_data3;
		w = player->ids.xpm_img3_w;
		h = player->ids.xpm_img3_h;
		player->rx = (int)((get_decimals(player->struct_side.he) *
		w) / 100);
		player->ry = (int)(((player->struct_screen.j -
		player->struct_screen.y / 2 + wall_h / 2) * h) / wall_h);
	}
	if (ft_strncmp((const char *)player->xpm_path_so, "./text4.xpm",
	ft_strlen(player->xpm_path_so)) == 0)
	{
		data = player->ids.xpm_data4;
		w = player->ids.xpm_img4_w;
		h = player->ids.xpm_img4_h;
		player->rx = (int)((get_decimals(player->struct_side.he) *
		w) / 100);
		player->ry = (int)(((player->struct_screen.j -
		player->struct_screen.y / 2 + wall_h / 2) * h) / wall_h);
	}
	if (((((player->ry * w * 4) + (player->rx * 4) + 3))) <=
	(w * h * 4) && (((player->ry * w * 4) + (player->rx * 4))) >= 0)
	{
		player->struct_side.pixel[0] = data[((((player->ry * w * 4)) +
		(player->rx * 4)))];
		player->struct_side.pixel[1] = data[((((player->ry * w * 4)) +
		(player->rx * 4))) + 1];
		player->struct_side.pixel[2] = data[((((player->ry * w * 4)) +
		(player->rx * 4))) + 2];
		player->struct_side.pixel[3] = data[((((player->ry * w * 4)) +
		(player->rx * 4))) + 3];
	}
	color = rgb3(player->struct_side.pixel[2], player->struct_side.pixel[1],
	player->struct_side.pixel[0]);
	return (color);
}

unsigned int	set_texture_north(t_player *player, int wall_h)
{
	unsigned int	color;
	char			*data;
	int				w;
	int				h;

	data = 0;
	w = 0;
	h = 0;
	if (ft_strncmp((const char *)player->xpm_path_no, "./text1.xpm",
	ft_strlen(player->xpm_path_no)) == 0)
	{
		data = player->ids.xpm_data;
		w = player->ids.xpm_img_w;
		h = player->ids.xpm_img_h;
		player->rx = (int)((get_decimals(player->struct_side.he) *
		w) / 100);
		player->ry = (int)(((player->struct_screen.j -
		player->struct_screen.y / 2 + wall_h / 2) * h) / wall_h);
	}
	if (ft_strncmp((const char *)player->xpm_path_no, "./text2.xpm",
	ft_strlen(player->xpm_path_no)) == 0)
	{
		data = player->ids.xpm_data2;
		w = player->ids.xpm_img2_w;
		h = player->ids.xpm_img2_h;
		player->rx = (int)((get_decimals(player->struct_side.he) *
		w) / 100);
		player->ry = (int)(((player->struct_screen.j -
		player->struct_screen.y / 2 + wall_h / 2) * h) / wall_h);
	}
	if (ft_strncmp((const char *)player->xpm_path_no, "./text3.xpm",
	ft_strlen(player->xpm_path_no)) == 0)
	{
		data = player->ids.xpm_data3;
		w = player->ids.xpm_img3_w;
		h = player->ids.xpm_img3_h;
		player->rx = (int)((get_decimals(player->struct_side.he) *
		w) / 100);
		player->ry = (int)(((player->struct_screen.j -
		player->struct_screen.y / 2 + wall_h / 2) * h) / wall_h);
	}
	if (ft_strncmp((const char *)player->xpm_path_no, "./text4.xpm",
	ft_strlen(player->xpm_path_no)) == 0)
	{
		data = player->ids.xpm_data4;
		w = player->ids.xpm_img4_w;
		h = player->ids.xpm_img4_h;
		player->rx = (int)((get_decimals(player->struct_side.he) *
		w) / 100);
		player->ry = (int)(((player->struct_screen.j -
		player->struct_screen.y / 2 + wall_h / 2) * h) / wall_h);
	}
	if (((((player->ry * w * 4) + (player->rx * 4) + 3))) <=
	(w * h * 4) && (((player->ry * w * 4) + (player->rx * 4))) >= 0)
	{
		player->struct_side.pixel[0] = data[((((player->ry * w * 4)) +
		(player->rx * 4)))];
		player->struct_side.pixel[1] = data[((((player->ry * w * 4)) +
		(player->rx * 4))) + 1];
		player->struct_side.pixel[2] = data[((((player->ry * w * 4)) +
		(player->rx * 4))) + 2];
		player->struct_side.pixel[3] = data[((((player->ry * w * 4)) +
		(player->rx * 4))) + 3];
	}
	color = rgb3(player->struct_side.pixel[2], player->struct_side.pixel[1],
	player->struct_side.pixel[0]);
	return (color);
}
