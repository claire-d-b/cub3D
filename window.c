/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:32:09 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/14 12:11:18 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void xpm_images(t_player *player)
{
    int c;
    
    c = (int)CELL_SIZE;
    player->ids.xpm_img = mlx_xpm_file_to_image(player->ids.mlx_ptr, player->xpm_path_no, &c, &c);
	player->ids.xpm_data = mlx_get_data_addr(player->ids.xpm_img,
    &player->ids.xpm_bpp, &player->ids.xpm_size_line,
    &player->ids.xpm_endian);
    player->ids.xpm_img2 = mlx_xpm_file_to_image(player->ids.mlx_ptr, player->xpm_path_so, &c, &c);
	player->ids.xpm_data2 = mlx_get_data_addr(player->ids.xpm_img2,
    &player->ids.xpm_bpp, &player->ids.xpm_size_line,
    &player->ids.xpm_endian);
    player->ids.xpm_img3 = mlx_xpm_file_to_image(player->ids.mlx_ptr, player->xpm_path_ea, &c, &c);
	player->ids.xpm_data3 = mlx_get_data_addr(player->ids.xpm_img3,
    &player->ids.xpm_bpp, &player->ids.xpm_size_line,
    &player->ids.xpm_endian);
    player->ids.xpm_img4 = mlx_xpm_file_to_image(player->ids.mlx_ptr, player->xpm_path_we, &c, &c);
	player->ids.xpm_data4 = mlx_get_data_addr(player->ids.xpm_img4,
    &player->ids.xpm_bpp, &player->ids.xpm_size_line,
    &player->ids.xpm_endian);
    player->ids.xpm_sprite = mlx_xpm_file_to_image(player->ids.mlx_ptr, player->xpm_path_sp, &c, &c);
	player->ids.xpm_data_sprite = mlx_get_data_addr(player->ids.xpm_sprite,
    &player->ids.xpm_bpp, &player->ids.xpm_size_line,
    &player->ids.xpm_endian);
}

void parse_map(char **map, t_player *player)
{
    int i = 0;
    int j = 0;

    while (map[i])
    {
        while (map[i][j])
        {
            if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != '2' && map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'E'
					&& map[i][j] != 'W')
                map[i][j] = '1';
            if (j == player->max - 1 || j == 0 || i == 0 || i == player->table_lenght - 1)
            {
                if (map[i][j] != '1')
                    map[i][j] = '1';
            }
            j++;
        }
        j = 0;
        i++;
    }
}

int player_placement_error(int i, int j, t_player *player)
{
     if (i == 0 || i == player->table_lenght - 1|| j == 0 || j == player->max - 1)
    {    
        write(1, "Wrong player placement.\n", 24);
        return (-1);
    }
    return (1);
}

int place_player(int i, int j, int count, t_player *player)
{
    while (i < player->table_lenght)
    {
        while (++j < player->max)
        {
            if (player->map[i][j] == 'N' || player->map[i][j] == 'S' || player->map[i][j] == 'E' 
            || player->map[i][j] == 'W')
             {
                 player_placement_error(i, j, player);
                 if (i != 0 && i != player->table_lenght - 1 && j != 0 && j != player->max - 1)
                 {
                 if (player->map[i][j] == 'N' || player->map[i][j] == 'S')
                     player->teta = (player->map[i][j] == 'N') ? VIEW_ANGLE : -VIEW_ANGLE;
                 if (player->map[i][j] == 'W' || player->map[i][j] == 'E')
                    player->teta = (player->map[i][j] == 'W') ? 0 : VIEW_ANGLE * 2;
                player->map[i][j] = '0';
                 count++;
                player->x = (i + 1) * CELL_SIZE + (CELL_SIZE / 2);
                player->y = (j + 1) * CELL_SIZE + (CELL_SIZE / 2);
                 }
             }
        }
        i++;
        j = -1;
    }
    if (count != 1)
        write(1, "Wrong number of players.\n", 25);
    return (count == 1) ? 1 : -1;
}

int open_window(int count, int j, t_player *player, char const *title)
{
    	if (!(player->sprite = malloc(sizeof(float *) * (player->max * player->table_lenght + 1))))
		return (0);
        while (count < player->max * player->table_lenght)
        {
            if (!(player->sprite[count] = malloc(sizeof(float) * 10)))
                return (0);
            while (j < 10)
            {
                player->sprite[count][j] = 0;
                j++;
            }
            count++;
        }
        player->sprite[count] = NULL;
        player->ids.mlx_win = mlx_new_window(player->ids.mlx_ptr,
        player->struct_screen.x, player->struct_screen.y, (char *)title);
        player->ids.img_ptr = mlx_new_image(player->ids.mlx_ptr,
        player->struct_screen.x, player->struct_screen.y);
        player->ids.img_data = mlx_get_data_addr(player->ids.img_ptr,
        &player->ids.img_bpp, &player->ids.img_size_line,
        &player->ids.img_endian);
        xpm_images(player);
        mlx_put_image_to_window(player->ids.mlx_ptr, player->ids.mlx_win,
        player->ids.img_ptr, 0, 0);
        return (1);
}
