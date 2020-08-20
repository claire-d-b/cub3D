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

#include "cub3d.h"

void	xpm_image_sprite(t_player *player)
{
	int c;

	c = (int)CELL_SIZE;
	player->ids.xpm_sprite = mlx_xpm_file_to_image(player->ids.mlx_ptr,
	player->xpm_path_sp, &c, &c);
	player->ids.xpm_data_sprite = mlx_get_data_addr(player->ids.xpm_sprite,
	&player->ids.img_bpp, &player->ids.img_size_line, &player->ids.img_endian);
}

void	xpm_images(t_player *player)
{
	int c;

	c = (int)CELL_SIZE;
	player->ids.xpm_img = mlx_xpm_file_to_image(player->ids.mlx_ptr,
	player->xpm_path_no, &c, &c);
	player->ids.xpm_data = mlx_get_data_addr(player->ids.xpm_img,
	&player->ids.img_bpp, &player->ids.img_size_line,
	&player->ids.img_endian);
	player->ids.xpm_img2 = mlx_xpm_file_to_image(player->ids.mlx_ptr,
	player->xpm_path_so, &c, &c);
	player->ids.xpm_data2 = mlx_get_data_addr(player->ids.xpm_img2,
	&player->ids.img_bpp, &player->ids.img_size_line,
	&player->ids.img_endian);
	player->ids.xpm_img3 = mlx_xpm_file_to_image(player->ids.mlx_ptr,
	player->xpm_path_ea, &c, &c);
	player->ids.xpm_data3 = mlx_get_data_addr(player->ids.xpm_img3,
	&player->ids.img_bpp, &player->ids.img_size_line,
	&player->ids.img_endian);
	player->ids.xpm_img4 = mlx_xpm_file_to_image(player->ids.mlx_ptr,
	player->xpm_path_we, &c, &c);
	player->ids.xpm_data4 = mlx_get_data_addr(player->ids.xpm_img4,
	&player->ids.img_bpp, &player->ids.img_size_line,
	&player->ids.img_endian);
}
