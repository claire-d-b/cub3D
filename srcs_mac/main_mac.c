/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:25:54 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/28 09:36:15 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_mac.h"

void	exit_program(t_player *player)
{
	if (player->map)
		ft_free_tab(player->map);
	if (player->sprite)
		ft_free_sprite(player->sprite);
	if (player->xpm_path_no)
		free(player->xpm_path_no);
	if (player->xpm_path_so)
		free(player->xpm_path_so);
	if (player->xpm_path_we)
		free(player->xpm_path_we);
	if (player->xpm_path_ea)
		free(player->xpm_path_ea);
	if (player->xpm_path_sp)
		free(player->xpm_path_sp);
	init_struct_ids(player);
	init_struct_player_exit(player);
	init_struct_screen_exit(player);
	init_struct_side_s_e(player);
	init_struct_bitmap_exit(player);
	exit(0);
}

int		minimise(t_player *player)
{
	mlx_put_image_to_window(player->ids.mlx_ptr, player->ids.mlx_win,
	player->ids.img_ptr, 0, 0);
	return (0);
}

void	hooks(t_player *player)
{
	mlx_hook(player->ids.mlx_win, 25, 1L << 18, &key_press, player);
	mlx_hook(player->ids.mlx_win, 2, 1L << 0, &key_press, player);
	mlx_hook(player->ids.mlx_win, 15, 1L << 16, &minimise, player);
	mlx_hook(player->ids.mlx_win, 17, 1L << 17, &exit_game, player);
}

void	player_placement(t_player *player, char *title)
{
	if (place_player(-1, -1, 0, player) != -1)
		open_window(player, title);
	else
	{
		free(player->ids.mlx_ptr);
		player->ids.mlx_ptr = 0;
		exit_program(player);
	}
}

int		main(int argc, char **argv)
{
	char		*title;
	t_player	player;
	char		**map;

	title = "cub3D";
	map = NULL;
	init_map_dim(&player);
	init_struct_player(&player);
	init_struct_screen(&player);
	init_struct_ids(&player);
	init_struct_side_s_e(&player);
	arg_error(argc, argv, &player);
	player.waste = (argc == 2) ? check_file(NULL, 0, &player, argv[1])
	: check_file(NULL, 0, &player, argv[2]);
	map = (argc == 2) ? create_map(map, player.table_lenght, &player, argv[1])
	: create_map(map, player.table_lenght, &player, argv[2]);
	player.map = map;
	create_sprite_tab(&player);
	player.ids.mlx_ptr = mlx_init();
	player_placement(&player, title);
	hooks(&player);
	display_view(0, 0, 0, &player);
	mlx_loop(player.ids.mlx_ptr);
	init_struct_ids(&player);
	return (0);
}
