#include "cub3D.h"

#define width 24
#define height 32
#define player->maxidth 24
#define player->table_lenghteight 32
#define M_PI 3.14159265359

void init_struct(t_ids *refs)
{
    refs->mlx_ptr = 0;
    refs->mlx_win = 0;
    refs->img_ptr = 0;
    refs->img_data = 0;
    refs->img_bpp = 0;
    refs->img_size_line = 0;
    refs->img_endian = 0;
    refs->pixel_data = 0;
    refs->count2 = 0;
}

void print_struct_ray(t_ray *ray)
{
    printf("xl %f\n", ray->xl);
    printf("yl %f\n", ray->yl);
    printf("il %d\n", ray->il);
    printf("jl %d\n", ray->jl);
    printf("al %f\n", ray->al);
    printf("aly %f\n", ray->aly);
}

void init_struct_ray(t_ray *ray)
{
    ray->xl = 0;
    ray->yl = 0;
    ray->il = 0;
    ray->jl = 0;
    ray->al = 0;
    ray->aly = 0;
}

int go_to_3(int i, int j, int it, int icam, double xcam, double ycam, double x, double y, t_ray *ray)
{   
    double data;

    data = (x - xcam) * (x - xcam) + (y - ycam) * (y - ycam);
    printf("xxxx = %f\n", x);
    ray->xl = x;
    ray->yl = y;
    ray->al = sqrt(data);
    ray->il = i;
    ray->jl = j;
}

int go_to_5(int i, int j, double xcam, double ycam, double x, double y, int it, t_ray *ray)
{
    if (ray->aly < ray->al)
    {
        ray->xl = x;
        ray->yl = y;
        ray->al = ray->aly;
        ray->il = i;
        ray->jl = j;
    }
}

void print_coord(double i, double j, double ireal, double jreal, int south)
{
    printf("print coord i %d\n", (int)(i + ireal + 1));
    printf("print coord j %d\n", (int)(j + jreal));
    printf("print coord south %d\n", south);
}

void set_rays(char **map, int w, int h, t_ray *ray)
{
    int imax = height;
    int jmax = width;
    double xy = 1.0;
    int icam = imax / 2;
    double xcam = (xy * imax) / 2;
    int jcam = 0;
    double ycam = xy / 2;
    double tm = -60;
    int it2 = 79;
    int itm = (int)(1 + (it2 / 2));
    double dt = 120 / it2;
    int it = -1;
    double t = tm - dt;
    int ii = 0;
    double tgt = 0;
    double den = 0;
    double x = 0;
    double y = 0;
    double ax = 0;
    double ay = 0;
    double dum = 0;
    int k = 0;
    int i = icam + 1;
    int j = jcam + 1;

    while (it < it2)
    {
        write(1, "a", 1);
        it = it + 1;
        if (it < itm)
            ii = -1;
        else
            ii = 0;
        t = t + dt;
        tgt = (x - xcam) / (jcam + 1) * xy - ycam;
        den = (jcam + 1) * xy - ycam;
        x = xcam + tgt * den;
        i = (int)(x / xy);
        j = jcam + 1;
        y = j * xy;
        ax = tgt * xy;
        printf("i = %d\n", i);
        printf("j = %d\n", j);
        while (i < imax && j < jmax)
        {
            write(1, "a", 1);
           if (map[i][j] == '1')
            {
                write(1, "c", 1);
                go_to_3(i, j, it, icam, xcam, ycam, x, y, ray);
                print_struct_ray(ray);
                while (k < imax && k >= 0)
                {
                    tgt = ((icam + 1) * (xy - ycam)) / (y - ycam);
                    dum = (icam + 1) * xy - ycam;
                    y = ycam + dum / tgt;
                    j = (int)(x / xy);
                    i = icam + 1;
                    x = i * xy;
                    ay = xy / tgt;
                    k = i + ii;
                    if (map[k][j] == '1')
                    {
                        ray->aly = sqrt((x - xcam) * (x - xcam) + (y - ycam) * (y - ycam));
                        go_to_5(i, j, xcam, ycam, x, y, it, ray);
                        print_struct_ray(ray);
                        break ;

                    }
                }
            }
             else{   y = y + xy;
                j = j + 1;
                x = x + ax;
             //   i = (int)(x / xy);
             }
        }
    }
}

char **create_map(int i, char **map)
{
    int fd;
    char *line;
    int x;
    int y;

    y = 0;
    x = 0;
    fd = open("map2.txt", O_RDONLY);
    if (!(map = malloc(sizeof(char *) * (player->table_lenghteight + 1))))
      return (0);
    while (i = get_next_line(fd, &line))
    {
        printf("strlen line %ld\n", ft_strlen(line));
        if (!(map[y] = malloc(sizeof(char) * (player->maxidth + 1))))
          return (0);
        while (x < ft_strlen(line))
        {
            map[y][x] = line[x];
            x++;
        }
        y++;
        x = 0;
        free(line);
    }
    map[y] = line;
  //  printf("y = %d\n", y);
    map[y + 1] = 0;
    //free(line);
    return (map);
}

int main()
{
    char const *title;
    t_ids refs;
    t_ray ray;
    int x;
    int y;
    char **map;
    int w;
    int h;
    
    w = width;
    h = height;
    title = "cub3D";
    x = 0;
    y = 0;
    printf("floor %f\n", floor);
    init_struct(&refs);
    init_struct(&ray);
    map = create_map(0, map);
    refs.mlx_ptr = mlx_init();
   refs.mlx_win = mlx_new_window(refs.mlx_ptr, width, height, title);
    printf("refs %p\n", refs.mlx_win);
   refs.img_ptr = mlx_new_image(refs.mlx_ptr, width, height);
    refs.img_data = (int *)mlx_get_data_addr(refs.img_ptr, &refs.img_bpp, 
    &refs.img_size_line, &refs.img_endian);
    set_rays(map, w, h, &ray);
    // calculate_dist(map, &refs);
    mlx_put_image_to_window(refs.mlx_ptr, refs.mlx_win, refs.img_ptr, 0, 0);
    // calculate_dist2(map, &refs);
   //   display_walls_diag_right(&refs, (double)(x = -y + 26), (double)(y = height));
     // display_wall_vertical(&refs, 0, height / 2);
      // display_wall_horizontal(&refs, width / 2, 0);
  //  mlx_pixel_put(refs.mlx_ptr, refs.mlx_win, i, j, 0xFFFFFF);
    mlx_loop(refs.mlx_ptr);
}