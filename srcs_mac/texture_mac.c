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

#include "cub3d_mac.h"

void			select_image_data(t_player *player, int w, int h, char *path)
{
	if ((ft_strncmp((const char *)path, "./text1.xpm",
	ft_strlen(path)) == 0))
	{
		w = player->ids.xpm_img_w;
		h = player->ids.xpm_img_h;
	}
	if ((ft_strncmp((const char *)path, "./text2.xpm",
	ft_strlen(path)) == 0))
	{
		w = player->ids.xpm_img2_w;
		h = player->ids.xpm_img3_h;
	}
	if ((ft_strncmp((const char *)path, "./text3.xpm",
	ft_strlen(path)) == 0))
	{
		w = player->ids.xpm_img3_w;
		h = player->ids.xpm_img3_h;
	}
	if ((ft_strncmp((const char *)path, "./text4.xpm",
	ft_strlen(path)) == 0))
	{
		w = player->ids.xpm_img4_w;
		h = player->ids.xpm_img4_h;
	}
	pick_pixels_in_texture(w, h, player);
}

unsigned int	set_texture_east(t_player *player, int wall_h)
{
	unsigned int	color;

	if (ft_strncmp((const char *)player->xpm_path_ea, "./text1.xpm",
	ft_strlen(player->xpm_path_ea)) == 0 ||
	ft_strncmp((const char *)player->xpm_path_ea, "./text2.xpm",
	ft_strlen(player->xpm_path_ea)) == 0)
		set_image_data12_ew(player, wall_h, player->xpm_path_ea);
	if (ft_strncmp((const char *)player->xpm_path_ea, "./text3.xpm",
	ft_strlen(player->xpm_path_ea)) == 0 ||
	ft_strncmp((const char *)player->xpm_path_ea, "./text4.xpm",
	ft_strlen(player->xpm_path_ea)) == 0)
		set_image_data34_ew(player, wall_h, player->xpm_path_ea);
	select_image_data(player, 0, 0, player->xpm_path_ea);
	color = rgb3(player->struct_side.pixel[2], player->struct_side.pixel[1],
	player->struct_side.pixel[0]);
	return (color);
}

unsigned int	set_texture_west(t_player *player, int wall_h)
{
	unsigned int	color;

	if (ft_strncmp((const char *)player->xpm_path_we, "./text1.xpm",
	ft_strlen(player->xpm_path_we)) == 0 ||
	ft_strncmp((const char *)player->xpm_path_we, "./text2.xpm",
	ft_strlen(player->xpm_path_we)) == 0)
		set_image_data12_ew(player, wall_h, player->xpm_path_we);
	if (ft_strncmp((const char *)player->xpm_path_we, "./text3.xpm",
	ft_strlen(player->xpm_path_we)) == 0 ||
	ft_strncmp((const char *)player->xpm_path_we, "./text4.xpm",
	ft_strlen(player->xpm_path_we)) == 0)
		set_image_data34_ew(player, wall_h, player->xpm_path_we);
	select_image_data(player, 0, 0, player->xpm_path_we);
	color = rgb3(player->struct_side.pixel[2], player->struct_side.pixel[1],
	player->struct_side.pixel[0]);
	return (color);
}

unsigned int	set_texture_south(t_player *player, int wall_h)
{
	unsigned int	color;

	if (ft_strncmp((const char *)player->xpm_path_so, "./text1.xpm",
	ft_strlen(player->xpm_path_so)) == 0 ||
	ft_strncmp((const char *)player->xpm_path_so, "./text2.xpm",
	ft_strlen(player->xpm_path_so)) == 0)
		set_image_data12_ns(player, wall_h, player->xpm_path_so);
	if (ft_strncmp((const char *)player->xpm_path_so, "./text3.xpm",
	ft_strlen(player->xpm_path_so)) == 0 ||
	ft_strncmp((const char *)player->xpm_path_so, "./text4.xpm",
	ft_strlen(player->xpm_path_so)) == 0)
		set_image_data34_ns(player, wall_h, player->xpm_path_so);
	select_image_data(player, 0, 0, player->xpm_path_so);
	color = rgb3(player->struct_side.pixel[2], player->struct_side.pixel[1],
	player->struct_side.pixel[0]);
	return (color);
}

unsigned int	set_texture_north(t_player *player, int wall_h)
{
	unsigned int	color;

	if (ft_strncmp((const char *)player->xpm_path_no, "./text1.xpm",
	ft_strlen(player->xpm_path_no)) == 0 ||
	ft_strncmp((const char *)player->xpm_path_no, "./text2.xpm",
	ft_strlen(player->xpm_path_no)) == 0)
		set_image_data12_ns(player, wall_h, player->xpm_path_no);
	if (ft_strncmp((const char *)player->xpm_path_no, "./text3.xpm",
	ft_strlen(player->xpm_path_no)) == 0 ||
	ft_strncmp((const char *)player->xpm_path_no, "./text4.xpm",
	ft_strlen(player->xpm_path_no)) == 0)
		set_image_data34_ns(player, wall_h, player->xpm_path_no);
	select_image_data(player, 0, 0, player->xpm_path_no);
	color = rgb3(player->struct_side.pixel[2], player->struct_side.pixel[1],
	player->struct_side.pixel[0]);
	return (color);
}
