/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:31:09 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/20 14:37:44 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3DSTRUCT_H
# define CUB3DSTRUCT_H

typedef struct	s_side
{
	double			he;
	double			wi;
	int				north;
	int				south;
	int				east;
	int				west;
	unsigned char	pixel[4];
}				t_side;

typedef struct	s_screen
{
	int	x;
	int	y;
	int	i;
	int	j;
}				t_screen;

typedef struct	s_bitmap
{
	int				r;
	int				g;
	int				b;
	int				a;
	int				resfield;
	int				offset;
	int				size;
	short int			plane;
	short int			depth;
	int				compression;
	int				zero;
	int				len;
	int				filesize;
}				t_bitmap;

typedef struct	s_ids
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img_ptr;
	char	*img_data;
	int		img_bpp;
	int		img_size_line;
	int		img_endian;
	char	**map;
	void	*xpm_img;
	void	*xpm_img2;
	void	*xpm_img3;
	void	*xpm_img4;
	void	*xpm_sprite;
	int		xpm_img_w;
	int		xpm_img_h;
	int		xpm_img2_w;
	int		xpm_img2_h;
	int		xpm_img3_w;
	int		xpm_img3_h;
	int		xpm_img4_w;
	int		xpm_img4_h;
	int		xpm_sprite_w;
	int		xpm_sprite_h;
	char	*xpm_data;
	char	*xpm_data2;
	char	*xpm_data3;
	char	*xpm_data4;
	char	*xpm_data_sprite;
	char	*sprite_img_data;
}				t_ids;

typedef struct	s_player
{
	int			key_r;
	int			waste;
	char		*xpm_path_no;
	char		*xpm_path_so;
	char		*xpm_path_we;
	char		*xpm_path_ea;
	char		*xpm_path_sp;
	int			ceil_color[4];
	int			floor_color[4];
	int			map_start;
	int			bool_start;
	int			save;
	int			nb_sprites;
	float		**sprite;
	int			table_lenght;
	int			max;
	int			start;
	char		p;
	float		distance;
	double		x;
	double		y;
	double		ray_x;
	double		ray_y;
	int			ry;
	int			rx;
	float		teta;
	t_ids		ids;
	t_screen	struct_screen;
	t_side		struct_side;
	t_bitmap	bitmap;
	char		**map;
}				t_player;

#endif
