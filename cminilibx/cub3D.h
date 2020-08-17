#ifndef CUB3D_H
#define CUB3D_H

#include <math.h> 
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 
#include <unistd.h>  
#include <fcntl.h> 
#include <mlx.h> 

typedef struct s_side
{
    unsigned char pixel[4];
}				t_side;

typedef struct s_screen
{
	int x;
	int y;
}				t_screen;

typedef struct s_ids 
{
    void *mlx_ptr;
    void *mlx_win;
    void *img_ptr;
    char *img_data;
    int img_bpp;
    int img_size_line;
    int img_endian;
    char **map;
    void *xpm_img;
    unsigned char *xpm_data;
}              t_ids; 

typedef struct s_player
{
    int x;
	int y;
	float teta;
    t_ids ids;
    t_screen struct_screen;
    t_side struct_side;
    char **map;
}				t_player;

int			get_next_line(int fd, char **line);
char		*join_a_free(char *s1, char *s2);
size_t		ft_strlen(char *str);
int			find_n(char *buf, size_t size);
void		*ft_memmove(void *dst, const void *src, size_t len);
char		*ft_create_a_clear_left(char *left, size_t size);

#endif
