/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:29:56 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/20 14:41:28 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3DPROTO_H
# define CUB3DPROTO_H

int				get_next_line(int fd, char **line);
char			*ft_strjoin(char *s1, char *s2);
char			*join_a_free(char *s1, char *s2);
size_t			ft_strlen(char *str);
int				find_n(char *buf, size_t size);
void			*ft_memmove(void *dst, const void *src, size_t len);
int				open_window(int count, int j, t_player *player,
				char const *title);
char			**create_map(int i, char **map, int lenght, t_player *player);
float			raycast(t_player *player, char **map, float angle);
void			display_view(float teta, float dist, double wall_h,
				t_player *player);
unsigned int	rgb3(unsigned int r, unsigned int g, unsigned int b);
unsigned int	set_texture_south(t_player *player, int y, int i);
unsigned int	set_texture_north(t_player *player, int y, int i);
unsigned int	set_texture_east(t_player *player, int y, int i);
unsigned int	set_texture_west(t_player *player, int y, int i);
void			camera_right(t_player *player);
void			camera_left(t_player *player);
void			walk_up(t_player *player);
void			walk_down(t_player *player);
void			walk_right(t_player *player);
void			walk_left(t_player *player);
int				key_press(int keycode, t_player *player);
void			walk_up_teta_pos(t_player *player);
void			walk_up_teta_neg(t_player *player);
void			walk_down_teta_pos(t_player *player);
void			walk_down_teta_neg(t_player *player);
void			walk_right_teta_pos(t_player *player);
void			walk_right_teta_neg(t_player *player);
void			walk_left_teta_pos(t_player *player);
void			walk_left_teta_neg(t_player *player);
void			change_color(t_player *player, int y, int i,
				unsigned int color);
void			pivot_colors_c(t_player *player);
void			pivot_colors_f(t_player *player);
void			pivot_textures_ns(t_player *player, float dist);
void			pivot_textures_ew(t_player *player, float dist);
void			define_heightawidth(t_player *player, float d, float angle);
void			check_side_south(t_player *player);
void			check_side_north(t_player *player);
void			check_side_east(t_player *player);
void			check_side_west(t_player *player);
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
void			*ft_free2(float **sprite);
void			*ft_free3(char **sprite);
void			pivot_textures_sprite(int i, int j, t_player *player);
char			*ft_strdup(const char *s1);
char			*ft_strchr(const char *s, int c);
size_t			len_wd(char const *str, int c);
size_t			count_malloc(char const *s, char c);
void			*ft_free(char **res, int j);
int				ft_atoi(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				pivot_file_checking(t_player *player, char *line, int y);
int				set_map_len(int y, t_player *player, char *line);
int				check_file(char *line, int fd, int i, t_player *player);
void			check_map(char *line, char **map, int count, t_player *player);
int				transform_map(char **map, int count, char *line,
				t_player *player);
int				set_resolution(int count, t_player *player, char *line);
int				set_path_to_texture_ns(int count, t_player *player, char *line);
int				set_path_to_texture_ew(int count, t_player *player, char *line);
int				set_path_to_texture_sp(int count, t_player *player, char *line);
int				set_floor_color(int count, t_player *player, char *line);
int				set_ceiling_color(int count, t_player *player, char *line);
int				fill_last_line(char **map, int count, t_player *player);
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
void			delete_sprites(t_player *player);
void			register_dist_minmax(t_player *player, float d, float angle,
				int i);
void			walk_up_teta_pos_diag(t_player *player);
void			walk_up_teta_neg_diag(t_player *player);
void			walk_down_teta_pos_diag(t_player *player);
void			walk_down_teta_neg_diag(t_player *player);
void			walk_right_teta_pos_diag(t_player *player);
void			walk_right_teta_neg_diag(t_player *player);
void			walk_left_teta_pos_diag(t_player *player);
void			walk_left_teta_neg_diag(t_player *player);
int				is_not_wall(t_player *player, float angle, float d);
void			check_wall_sides(t_player *player, float d, float angle);
void			xpm_images(t_player *player);
void			xpm_image_sprite(t_player *player);

#endif
