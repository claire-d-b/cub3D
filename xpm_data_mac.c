/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 14:40:06 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/20 14:43:44 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_mac.h"

void	xpm_image_sprite(t_player *player)
{
	player->ids.xpm_sprite = mlx_xpm_file_to_image(player->ids.mlx_ptr,
	player->xpm_path_sp, &player->ids.xpm_sprite_w, &player->ids.xpm_sprite_h);
	player->ids.xpm_data_sprite = mlx_get_data_addr(player->ids.xpm_sprite,
	&player->ids.img_bpp, &player->ids.img_size_line, &player->ids.img_endian);
}

void	xpm_images(t_player *player)
{
	player->ids.xpm_img = mlx_xpm_file_to_image(player->ids.mlx_ptr,
	player->xpm_path_no, &player->ids.xpm_img_w, &player->ids.xpm_img_h);
	player->ids.xpm_data = mlx_get_data_addr(player->ids.xpm_img,
	&player->ids.img_bpp, &player->ids.img_size_line,
	&player->ids.img_endian);
	player->ids.xpm_img2 = mlx_xpm_file_to_image(player->ids.mlx_ptr,
	player->xpm_path_so, &player->ids.xpm_img2_w, &player->ids.xpm_img2_h);
	player->ids.xpm_data2 = mlx_get_data_addr(player->ids.xpm_img2,
	&player->ids.img_bpp, &player->ids.img_size_line,
	&player->ids.img_endian);
	player->ids.xpm_img3 = mlx_xpm_file_to_image(player->ids.mlx_ptr,
	player->xpm_path_ea, &player->ids.xpm_img3_w, &player->ids.xpm_img3_h);
	player->ids.xpm_data3 = mlx_get_data_addr(player->ids.xpm_img3,
	&player->ids.img_bpp, &player->ids.img_size_line,
	&player->ids.img_endian);
	player->ids.xpm_img4 = mlx_xpm_file_to_image(player->ids.mlx_ptr,
	player->xpm_path_we, &player->ids.xpm_img4_w, &player->ids.xpm_img4_h);
	player->ids.xpm_data4 = mlx_get_data_addr(player->ids.xpm_img4,
	&player->ids.img_bpp, &player->ids.img_size_line,
	&player->ids.img_endian);
}
