/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 16:27:29 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/29 16:27:33 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_mac.h"

void	init_img_size(t_player *player)
{
	player->ids.xpm_img_w = 0;
	player->ids.xpm_img_h = 0;
	player->ids.xpm_img2_w = 0;
	player->ids.xpm_img2_h = 0;
	player->ids.xpm_img3_w = 0;
	player->ids.xpm_img3_h = 0;
	player->ids.xpm_img4_w = 0;
	player->ids.xpm_img4_h = 0;
	player->ids.xpm_sprite_w = 0;
	player->ids.xpm_sprite_h = 0;
}

void	init_struct_ids(t_player *player)
{
	init_img_size(player);
	player->ids.mlx_ptr = 0;
	player->ids.mlx_win = 0;
	player->ids.img_ptr = 0;
	player->ids.img_data = 0;
	player->ids.img_bpp = 0;
	player->ids.img_size_line = 0;
	player->ids.img_endian = 0;
	player->ids.map = 0;
	player->ids.xpm_img = 0;
	player->ids.xpm_img2 = 0;
	player->ids.xpm_img3 = 0;
	player->ids.xpm_img4 = 0;
	player->ids.xpm_sprite = 0;
	player->ids.xpm_data = 0;
	player->ids.xpm_data2 = 0;
	player->ids.xpm_data3 = 0;
	player->ids.xpm_data4 = 0;
	player->ids.xpm_data_sprite = 0;
	player->ids.sprite_img_data = 0;
}

void	init_struct_bitmap_exit(t_player *player)
{
	player->bitmap.r = 0;
	player->bitmap.g = 0;
	player->bitmap.b = 0;
	player->bitmap.a = 0;
	player->bitmap.resfield = 0;
	player->bitmap.offset = 0;
	player->bitmap.size = 0;
	player->bitmap.plane = 0;
	player->bitmap.depth = 0;
	player->bitmap.compression = 0;
	player->bitmap.zero = 0;
	player->bitmap.len = 0;
	player->bitmap.filesize = 0;
}

void	init_struct_screen(t_player *player)
{
	player->struct_screen.x = -1;
	player->struct_screen.y = -1;
	player->struct_screen.i = 0;
	player->struct_screen.j = 0;
}

void	init_struct_screen_exit(t_player *player)
{
	player->struct_screen.x = 0;
	player->struct_screen.y = 0;
	player->struct_screen.i = 0;
	player->struct_screen.j = 0;
}
