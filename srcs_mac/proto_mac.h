/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:29:56 by clde-ber          #+#    #+#             */
/*   Updated: 2020/09/19 12:07:33 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3DPROTO_MAC_H
# define CUB3DPROTO_MAC_H

int				get_next_line(int fd, char **line);
char			*ft_strjoin(char *s1, char *s2);
char			*join_a_free(char *s1, char *s2);
size_t			ft_strlen(char *str);
int				find_n(char *buf, size_t size);
void			*ft_memmove(void *dst, const void *src, size_t len);
int				open_window(t_player *player,
				char const *title);
char			**create_map(char **map, int lenght, t_player *player,
			char *arg);
float			raycast(t_player *player, char **map, float angle);
void			display_view(float teta, float dist, double wall_h,
				t_player *player);
unsigned int	rgb3(unsigned int r, unsigned int g, unsigned int b);
unsigned int	set_texture_east(t_player *player, int y, int i);
unsigned int	set_texture_west(t_player *player, int y, int i);
unsigned int	set_texture_south(t_player *player, int y, int i);
unsigned int	set_texture_north(t_player *player, int y, int i);
void			camera_right(t_player *player);
void			camera_left(t_player *player);
void			walk_up(t_player *player);
void			walk_down(t_player *player);
void			walk_right(t_player *player);
void			walk_left(t_player *player);
int				key_press(int keycode, t_player *player);
void			change_color(t_player *player, int y, int i,
				unsigned int color);
void			pivot_colors_c(t_player *player);
void			pivot_colors_f(t_player *player);
void			pivot_textures_ns(unsigned int col, int wall_h,
				t_player *player);
void			pivot_textures_ew(unsigned int col, int wall_h,
				t_player *player);
void			define_heightawidth(t_player *player, float d, float angle);
void			check_side_east(t_player *player);
void			check_side_west(t_player *player);
void			check_side_south(t_player *player);
void			check_side_north(t_player *player);
void			register_coordinates(t_player *player, double x, double y);
void			init_var_raycast(char *p, float *d, t_player *player, int *i);
void			init_pixels(t_player *player);
int				get_decimals(float height);
char			**create_sprite(int i, char **sprite);
void			display_sprite(t_player *player, float dist, int y, int i);
unsigned int	set_texture_sprite(t_player *player, int y, int i);
int				exit_game(t_player *player);
unsigned int	set_texture_sprite_rev(t_player *player, int y, int i);
int				create_bmp(t_player *player);
void			parse_map(char **map, t_player *player);
int				ft_atoi(const char *str);
char			**ft_split(char const *s, char c);
int				ft_isdigit(int c);
void			*ft_calloc(size_t count, size_t size);
void			*ft_free_sprite(float **sprite);
void			*ft_free_tab(char **sprite);
void			pivot_textures_sprite(int i, int j, t_player *player);
char			*ft_strdup(const char *s1);
char			*ft_strchr(const char *s, int c);
size_t			len_wd(char const *str, int c);
size_t			count_malloc(char const *s, char c);
void			*ft_free(char **res, int j);
int				ft_atoi(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				pivot_file_checking(int len, t_player *player, char *line,
				int y);
int				set_map_len(int y, t_player *player, char *line);
int				check_file(char *line, int fd, t_player *player, char *arg);
void			check_map(char **map, int count, t_player *player);
int				transform_map(char **map, int count, char *line,
				t_player *player);
int				set_resolution(int count, t_player *player, char *line);
int				set_path_to_texture_ns(int count, t_player *player, char *line);
int				set_path_to_texture_ew(int count, t_player *player, char *line);
int				set_path_to_texture_sp(int count, t_player *player, char *line);
int				set_floor_color(int count, t_player *player, char *line);
int				set_ceiling_color(int count, t_player *player, char *line);
void			init_struct_side(t_player *player);
void			init_sprite(t_player *player);
void			draw_sprite_from_end(t_player *player, int i, int j,
				int count);
void			draw_sprite_from_start(t_player *player, int i, int j,
				int count);
void			display_all(t_player *player);
void			display_view_x(t_player *player, float *teta, float *dist,
				double *wall_h);
void			register_sprite_start(int i, t_player *player, float angle,
				float d);
void			register_sprite_end(int i, t_player *player, float angle,
				float d);
int				is_sprite(float *sprite);
int				place_player(int i, int j, int count, t_player *player);
int				player_placement_error(int i, int j, t_player *player);
void			init_struct_bitmap(t_player *player);
void			bmp_write_header(int i, int fd, t_player *player);
void			bmp_write_colors(int i, int j, int fd, t_player *player);
void			register_dist_minmax(t_player *player, float d, float angle,
				int i);
int				is_not_wall(t_player *player, float angle, float d);
void			check_wall_sides(t_player *player, float d, float angle);
void			xpm_images(t_player *player);
void			xpm_image_sprite(t_player *player);
void			init_map_dim(t_player *player);
int				key_release(int keycode, t_player *player);
void			move_left(t_player *player);
void			sort_sprite(t_player *player);
void			ft_swap(float **a, float **b);
void			hooks(t_player *player);
void			screen_size(t_player *player);
void			player_placement(t_player *player, char *title);
int				is_player(char c);
void			set_game_elements(char *line, t_player *player);
void			init_struct_player(t_player *player);
void			init_struct_screen(t_player *player);
void			missing_elements(t_player *player, char *line);
void			init_elements(t_player *player);
void			map_error(t_player *player, char **map, int i, int j);
int				is_empty_line(char *line);
void			manage_lines(char *line, t_player *player);
void			init_struct_bitmap_exit(t_player *player);
void			init_struct_screen_exit(t_player *player);
void			init_elements_exit(t_player *player);
void			init_struct_player_exit(t_player *player);
void			init_struct_ids(t_player *player);
void			init_struct_side_s_e(t_player *player);
void			exit_program(t_player *player);
int				set_path_to_texture_no(char *to_record, t_player *player);
int				set_path_to_texture_so(char *to_record, t_player *player);
int				set_path_to_texture_we(char *to_record, t_player *player);
int				set_path_to_texture_ea(char *to_record, t_player *player);
int				is_space(char c);
void			arg_error(int nb_args, char **args, t_player *player);
void			two_args_plus_error(int nb_args, char **args, t_player *player);
void			doublons(char *line, t_player *player);
int				is_map(char *line);
int				create_sprite_tab(t_player *player);
void			draw_sprite_from_start(t_player *player, int i, int j,
				int count);
void			draw_sprite_from_end(t_player *player, int i, int j, int count);
int				is_not_sprite(t_player *player, float angle, float d);
int				is_not_wall(t_player *player, float angle, float d);
float			raycast_sprites(t_player *player, char **map, float angle,
				int count);
void			check_wall_dist_before_sprite(t_player *player, int count,
				float d);
int				is_new(t_player *player, float d, float angle, int i);

#endif
