#include "cub3D.h"

#define width 640
#define height 480
#define player->maxidth 24
#define player->table_lenghteight 32
#define KEY_LEFT 123
#define KEY_RIGHT 124
#define KEY_UP 126
#define KEY_DOWN 125
#define M_PI 3.14159265359
#define SIN_37 0.601815023152

void display_right_wall(double x, double i, t_ids *refs, double sky_h);
void display_left_wall(double x, double i, t_ids *refs, double sky_h);

void init_struct(t_ids *refs)
{
    refs->mlx_ptr = 0;
    refs->mlx_win = 0;
}

void  actualize_refs_count(int sky_h, t_ids *refs)
{
  int i;
  int j;
  int count;

count = 0;
   j = 0;
    i = width / 2 + sky_h / 2;
    while (i < width)
    {
      while (j < height)
      {
     // mlx_pixel_put(refs->mlx_ptr, refs->mlx_win, i, j, 0xFFFFFF);
     // mlx_pixel_put(refs->mlx_ptr, refs->mlx_win, width - i, j, 0xFFFFFF);
      j++;
      }
      i += sky_h;
      count++;
      j = 0;
    }
    refs->count2 = count;
    printf("refs count2 %d\n", refs->count2);
}

int    display_wall_horizontal(t_ids *refs, double x, double y, double counter, int sky_h)
{
  double tmp;
  double hypotenuse;
  double arrete;
  double coeff;
  double opposite;
  double adjacent;
  double p;
  double p2;
  double i;
  double j;
  double j2;
  double ajustement;
  double ajustement2;
  double count;
  double j3;

  i = x;
  j = y;
  count = 0;
  j3 = 0;
  tmp = 0;
  arrete = (double)sky_h * 0.7; //calcul de l'arrete du cube avec un coef de perspective de 0.7
  //selon l equation de la droite y = ax + b, où a represente l angle de 120° uqi fuit vers le personnage,
  opposite = (arrete / 3) * (arrete / 3);
  adjacent = opposite * 2;
  coeff = opposite / adjacent; // coeff directeur de la droite YA-YB / XA - XB 
  //y = m . x + p où 0 = m.adjacent + coeff cad p = (-m*x) - y
  p = opposite - (coeff * adjacent);
  tmp = x + (double)sky_h;
 printf("wall_height ! %d\n", sky_h);
 printf("int wall_height %d\n", sky_h);
      printf("YYYY %f\n", y);
      j = 0;
    i = width / 2 + sky_h / 2;
    while (i < width)
    {
      while (j < height)
      {
     // mlx_pixel_put(refs->mlx_ptr, refs->mlx_win, i, j, 0xFFFFFF);
     // mlx_pixel_put(refs->mlx_ptr, refs->mlx_win, width - i, j, 0xFFFFFF);
      j++;
      }
      i += sky_h;
      count++;
      j = 0;
    }
    refs->count2 = count;
   // printf("count = %f\n", count);
    i = x;
    j = y;
      j = (height - (double)sky_h) / 2;
   while (i < x + ((double)sky_h * counter))
    {
    while (j < (height + (double)sky_h) / 2)
    {
    //   printf("count = %f\n", counter);
    //  printf("height - wall_h %f\n", wall_h);
   if ((int)(i - (width / 2 + sky_h / 2)) % (int)(sky_h))
     mlx_pixel_put(refs->mlx_ptr, refs->mlx_win, i, j, 0xFFFFFF);
     if ((int)(width / 2 - (sky_h / 2) - i) % (int)(sky_h) && i != ((width / 2) - (sky_h / 2)))
     mlx_pixel_put(refs->mlx_ptr, refs->mlx_win, width - i, j, 0xFFFFFF);
      j++;
    //  printf("refs %p\n", refs->mlx_win);
    }
    i++;
    j = (height - ((double)sky_h)) / 2;
    }
  // display_left_wall(width - i, count2, refs, sky_h);
   /* j = (height - (double)sky_h) / 2;
    i = x;
   while (i > x - ((double)sky_h * counter))
    {
    while (j < (height + (double)sky_h) / 2)
    {
       printf("count = %f\n", counter);
    //  printf("height - wall_h %f\n", wall_h);
    if ((int)(i - (width / 2 + sky_h / 2)) % (int)(sky_h))
     mlx_pixel_put(refs->mlx_ptr, refs->mlx_win, i, j, 0xFFFFFF);
      j++;
    //  printf("refs %p\n", refs->mlx_win);
    }
    i--;
    j = (height - ((double)sky_h)) / 2;
    }*/
   // j = (height - (double)sky_h) / 2;
   // while (i < tmp)
   // {
      //  printf("a");
    //  printf("height - wall_h %f\n", wall_h);
    //  mlx_pixel_put(refs->mlx_ptr, refs->mlx_win, i, j, 0xFFFFFF);
     // mlx_pixel_put(refs->mlx_ptr, refs->mlx_win, i, j + (double)sky_h, 0xFFFFFF);
   //   i++;
    //  printf("refs %p\n", refs->mlx_win);
   // }
 /*   i = width / 2 + sky_h / 2;
    j = (double)((coeff * i) + p);
    j2 = (double)(((height - (height / 2 + sky_h))) + (-(coeff * i) + p));
    ajustement = height / 2 + sky_h / 2 - (coeff * i);
    ajustement2 = ((height - sky_h) / 2) + ((coeff * i) + p);
    printf("ajustement = %f\n", ajustement);
    printf("ajustement2 = %f\n", ajustement2);
    printf("p = %f\n", p);
    printf("j === %f\n", j);
    printf("coeff * i = %f\n", coeff * i);
     printf("coeff = %f\n", coeff);
     printf("height / 2 = %f\n", (double)(height / 2));
    while (i < width)
    {
      //  printf("a");
    //  printf("height - wall_h %f\n", wall_h);
     j = (double)((coeff * i) + p);
      j2 = (double)(((height - (height / 2 + sky_h))) + (-(coeff * i) + p));
    //  mlx_pixel_put(refs->mlx_ptr, refs->mlx_win, i, j + ajustement, 0xFFFFFF);
    //  mlx_pixel_put(refs->mlx_ptr, refs->mlx_win, i, j3 = (height / 2) + sky_h + j2 - ajustement, 0xFF0205);
    while (j + ajustement > (height / 2) + sky_h + j2 - ajustement && (double)((int)((width - (sky_h / 2)) - i) % (int)(((width + (sky_h / 2))) / (count2 * count2))))
    {
      mlx_pixel_put(refs->mlx_ptr, refs->mlx_win, i, j3 = j + ajustement, 0xFFFFFF);
      j2 = (double)(((height - (height / 2 + sky_h))) + (-(coeff * i) + p));
      j--;
   //   printf("jjjj ==== %f\n", j);
    }
   //  mlx_pixel_put(refs->mlx_ptr, refs->mlx_win, i, (height - sky_h) / 2, 0xFF0205);
         if ((double)((int)(width - (sky_h / 2) - i) % (int)(((width + (sky_h / 2))) / (count2 * count2)) == 0))
      { printf("!count = %f\n", count2);
        count2--;
      }
      j = (double)((coeff * i) + p);
      j2 = (double)(((height - (height / 2 + sky_h))) + (-(coeff * i) + p));
   //   printf("J1 = %f\n", j);
      i++;
    }*/
    return (i);
}

void display_right_wall(double x, double i, t_ids *refs, double sky_h)
{
  double arrete;
  double opposite;
  double adjacent;
  double coeff;
  double ajustement;
  double p;
  double ajustement2;
  double j3;
  double j2;
  double j;

  j3 = 0;
   arrete = (double)sky_h * 0.7; //calcul de l'arrete du cube avec un coef de perspective de 0.7
  //selon l equation de la droite y = ax + b, où a represente l angle de 120° uqi fuit vers le personnage,
  opposite = (arrete / 3) * (arrete / 3);
  adjacent = opposite * 2;
  coeff = opposite / adjacent; // coeff directeur de la droite YA-YB / XA - XB 
  //y = m . x + p où 0 = m.adjacent + coeff cad p = (-m*x) - y
  p = opposite - (coeff * adjacent);

   i = width / 2 - sky_h / 2;
    j = (double)((coeff * x) + p);
    j2 = (double)(((height - (height / 2 + sky_h))) + (-(coeff * x) + p));
    ajustement = height / 2 + sky_h / 2 - (coeff * x);
    ajustement2 = ((height - sky_h) / 2) + ((coeff * x) + p);
    printf("ajustement = %f\n", ajustement);
    printf("ajustement2 = %f\n", ajustement2);
    printf("p = %f\n", p);
    printf("j === %f\n", j);
//   printf("coeff * i = %f\n", coeff * i);
     printf("coeff = %f\n", coeff);
     printf("height / 2 = %f\n", (double)(height / 2));
     printf("xxxxx = %f\n", x);
    while (x < width)
    {
      //  printf("a");
    //  printf("height - wall_h %f\n", wall_h);
     j = (double)((coeff * x) + p);
      j2 = (double)(((height - (height / 2 + sky_h))) + (-(coeff * x) + p));
    //  mlx_pixel_put(refs->mlx_ptr, refs->mlx_win, i, j + ajustement, 0xFFFFFF);
    //  mlx_pixel_put(refs->mlx_ptr, refs->mlx_win, i, j3 = (height / 2) + sky_h + j2 - ajustement, 0xFF0205);
    while (j + ajustement > (height / 2) + sky_h + j2 - ajustement && (double)((int)(width - x - (sky_h / 2)) % (int)(((sky_h) / (refs->count2)))))
    {
      mlx_pixel_put(refs->mlx_ptr, refs->mlx_win, x, j3 = j + ajustement, 0xFFFFFF);
      j2 = (double)(((height - (height / 2 + sky_h))) + (-(coeff * x) + p));
      j--;
   //   printf("jjjj ==== %f\n", j);
    }
   //  mlx_pixel_put(refs->mlx_ptr, refs->mlx_win, i, (height - sky_h) / 2, 0xFF0205);
         if (((int)(width - x - (sky_h / 2)) % (int)((sky_h) / (refs->count2)) == 0))
      { printf("!count = %d\n", refs->count2);
        refs->count2--;
      }
      j = (double)((coeff * x) + p);
      j2 = (double)(((height - (height / 2 + sky_h))) + (-(coeff * x) + p));
   //   printf("J1 = %f\n", j);
      x++;
    }
}

void display_left_wall(double x, double i, t_ids *refs, double sky_h)
{
   double arrete;
  double opposite;
  double adjacent;
  double coeff;
  double ajustement;
  double p;
  double ajustement2;
  double j3;
  double j2;
  double j;
  double index;

  j3 = 0;
  index = x;
  printf(" X === %f\n", x);
   arrete = (double)sky_h * 0.7; //calcul de l'arrete du cube avec un coef de perspective de 0.7
  //selon l equation de la droite y = ax + b, où a represente l angle de 120° uqi fuit vers le personnage,
  opposite = (arrete / 3) * (arrete / 3);
  adjacent = opposite * 2;
  coeff = opposite / adjacent; // coeff directeur de la droite YA-YB / XA - XB 
  //y = m . x + p où 0 = m.adjacent + coeff cad p = (-m*x) - y
  p = opposite - (coeff * adjacent);

   i = width / 2 - sky_h / 2;
    j = (double)((coeff * x) + p);
    j2 = (double)(((height - (height / 2 + sky_h))) + (-(coeff * x) + p));
    ajustement = height / 2 + sky_h / 2 - (coeff * x);
    ajustement2 = ((height - sky_h) / 2) + ((coeff * x) + p);
    printf("ajustement = %f\n", ajustement);
    printf("ajustement2 = %f\n", ajustement2);
    printf("p = %f\n", p);
    printf("j === %f\n", j);
//   printf("coeff * i = %f\n", coeff * i);
     printf("coeff = %f\n", coeff);
     printf("height / 2 = %f\n", (double)(height / 2));
     printf("xxxxx = %f\n", x);
    while (x >= 0)
    {
      //  printf("a");
    //  printf("height - wall_h %f\n", wall_h);
     j = (double)((coeff * index) + p);
      j2 = (double)(((height - (height / 2 + sky_h))) + (-(coeff * index) + p));
    //  mlx_pixel_put(refs->mlx_ptr, refs->mlx_win, i, j + ajustement, 0xFFFFFF);
    //  mlx_pixel_put(refs->mlx_ptr, refs->mlx_win, i, j3 = (height / 2) + sky_h + j2 - ajustement, 0xFF0205);
    while (j + ajustement > (height / 2) + sky_h + j2 - ajustement && (double)((int)(x - (sky_h / 2)) % (int)(((sky_h) / (refs->count2)))) || x == 0)
    {
      mlx_pixel_put(refs->mlx_ptr, refs->mlx_win, x, j3 = j + ajustement, 0xFFFFFF);
      j2 = (double)(((height - (height / 2 + sky_h))) + (-(coeff * index) + p));
      j--;
   //   printf("jjjj ==== %f\n", j);
    }
   //  mlx_pixel_put(refs->mlx_ptr, refs->mlx_win, i, (height - sky_h) / 2, 0xFF0205);
         if (((int)(x - (sky_h / 2)) % (int)((sky_h) / (refs->count2)) == 0))
      { printf("!??count = %d\n", refs->count2);
        refs->count2--;
      }
      j = (double)((coeff * index) + p);
      j2 = (double)(((height - (height / 2 + sky_h))) + (-(coeff * index) + p));
   //   printf("J1 = %f\n", j);
      x--;
      index++;
    }
}


void    display_wall_vertical(t_ids *refs, double x, double y, int sky_height)
{
    double view_up;
    double high;

    view_up = 0;
    high = height - sky_height;
    view_up = sky_height / (1.60 * (height / player->table_lenghteight));

    printf("height - sky_height %f\n", height);
    printf("int sky_height %d\n", sky_height);
    printf("YYYY %f\n", y);
    while (x < view_up)
    {
      //  printf("a");
        mlx_pixel_put(refs->mlx_ptr, refs->mlx_win, x, sky_height, 0x1B2426);
      x++;
    //  printf("refs %p\n", refs->mlx_win);
    }
}

int  draw_wall(int i, int j, t_ids *refs)
{
  int sky_height;
  int hypotenuse;
 // t_view view;
  int sides_sum;
  int real_size;
  int res;

  sky_height = 0;
  hypotenuse = 0;
  res = i;
  i = i * (height / player->table_lenghteight);
  sides_sum = (int)((i * i) + 
  ((height / 2) * (height / 2)));
  real_size = sides_sum;
  hypotenuse = (int)(sqrt(real_size));
  sky_height = (int)(SIN_37 * hypotenuse * 2);
  if (sky_height > height || sky_height < 0)
    return ((int)(height / res));
  return (((int)(sky_height / res)));
}

void  draw_wall2(int i, int j, t_ids *refs)
{
  int sky_height;
  int hypotenuse;
  int sides_sum;
  int real_size;
  int x;
  int y;
  int res;

  res = i;
  sky_height = 0;
  hypotenuse = 0;
  i = i * (height / player->table_lenghteight);
  sides_sum = (int)((i * i) + 
  ((height / 2) * (height / 2)));
  real_size = sides_sum;
  hypotenuse = (int)(sqrt(real_size));
  sky_height = (int)(SIN_37 * hypotenuse * 2);
  sky_height = (int)(sky_height / res);
  x = 0;
  y = 0;
  while (x < width)
      {
        y = 0;
        while (y < (int)(((height - ((height - sky_height) / 2)) + (height - sky_height) / 2) / 2))
        {
        //    refs->img_data[y * width + x] = 0x2F94EC;
            y++;
        }
        x++;
      }
      x = 0;
      y = 0;
   while (x < width)
      {
        y = 0;
        while (y < height)
        {
           // refs->img_data[(int)((height - (y / 2)) / 2) + (int)(y / 2) * width + x] = 0x2F94EC;
           // refs->img_data[(int)((height - (y / 2)) / 2) + (int)(y / 2) * width + x] = 0x2F94EC;
            y++;
        }
        x++;
      }
}

void    calculate_dist(char **map, t_ids *refs)
{
  int i;
  int j;
  int x;
  int y;
  int counter;
  int sky_height;
  int index;
  int count;
  int position;

    counter = 1;
    i = 0;
    j = 0;
    x = 0;
    y = 0;
    count = 1;
    position = 0;
    while (map[i])
  {
    while (map[i][j])
    { 
      if (map[i][j] == 'N')
        break; 
      j++;
    }
    if (map[i][j] == 'N')
      break ;
    j = 0;
    i++;
  }
  x = i;
  y = j;
  x++;
  printf("i %d\n", i);
  printf("j %d\n", j);
  while (map[x])
  {
     y = (position - count <= 0) ? 0 : position - count;
      printf("valuer y = %d\n", y);
    while (map[x][y] && y < position + count)
    {
      if (map[x][y] == '1')
       { 
         printf("aaaaaaa");
       printf("x - i %d\n y - j %d\n", x - i, y + j);
         draw_wall2(x - i, y + j, refs);
         counter++;
         printf("W_H %f\n", sky_height);
       //  break ;
       }
      y++;
    //  printf("y = %d\n", y);
    }
    if (map[x][y] == '1')
    {
      draw_wall2(x - i, y - j, refs);
      counter++;
      //  break ;
    }
   printf("x = %d\n", x);
    x++;
    count++;
  }
}

int     calculate_dist2(char **map, t_ids *refs)
{
  int i;
  int j;
  int x;
  int y;
  int sky_height;
  double counter; 
  double index;
  int count;
  int position;

  position = 0;
  count = 1;
  i = 0;
  j = 0;
  x = 0;
  y = 0;
  index = 0;
  counter = 1;
  sky_height = 0;
  while (map[i] && map[i][j] != 'N')
  {
    while (map[i][j] && map[i][j] != 'N')
    { 
      if (map[i][j] == 'N')
      {
           position = j;
        break;
      }
  //   printf("j = %d\n", j);  
      j++;
    }
    if (map[i][j] == 'N')
    {
         position = j;
      break ;
    }
    j = 0;
    printf("%s\n", map[i]);
    i++;
  }
  x = i;
  y = j;
  printf("i %d\n", i);
  printf("j %d\n", j);
  x++;
  while (map[x])
  {
    y = (position - count <= 0) ? 0 : position - count;
    printf("valuer y = %d\n", y);
    while (map[x][y] && y < position + count)
    {
      if (map[x][y] == '1')
       { printf("aaaaaaa");
       printf("x - i %d\n", x + i);
         sky_height = draw_wall(x - i, y - j, refs);
         printf("W_H %f\n", sky_height);
       index = display_wall_horizontal(refs, (width / 2) - (sky_height / 2), height - sky_height, counter, sky_height);
        counter++;
    //   break ;
       }
      y++;
    //  printf("y = %d\n", y);
    }
    if (map[x][y] == '1')
    {
      sky_height = draw_wall(x - i, y - j, refs);
         printf("W_H %f\n", sky_height);
       index = display_wall_horizontal(refs, (width / 2) - (sky_height / 2), height - sky_height, counter, sky_height);
        counter++;
    //  break ;
    }
   printf("??x = %d\n", x);
    x++;
    count++;
  }
   display_right_wall(index, x, refs, sky_height);
   actualize_refs_count(sky_height, refs);
   display_left_wall(width - index, x, refs, sky_height);
}

void    display_walls_diag_right(t_ids *refs, double x, double y, double *sky_height)
{
    while (x < width)
    {
      //  printf("a");
      mlx_pixel_put(refs->mlx_ptr, refs->mlx_win, x, y, 0xFFFFFF);
      x++;
      y = -x + 26;
   //   printf("refs %p\n", refs->mlx_win);
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
    while (i = get_next_line(0, fd, &line))
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
    printf("y = %d\n", y);
    map[y + 1] = 0;
    //free(line);
    return (map);
}

int main()
{
    char const *title;
    t_ids refs;
    int x;
    int y;
    char **map;
    
    title = "cub3D";
    x = 0;
    y = 0;
    printf("floor %f\n", floor);
    init_struct(&refs);
    map = create_map(0, map);
    refs.mlx_ptr = mlx_init();
   refs.mlx_win = mlx_new_window(refs.mlx_ptr, width, height, title);
    printf("refs %p\n", refs.mlx_win);
   refs.img_ptr = mlx_new_image(refs.mlx_ptr, width, height);
    refs.img_data = (int *)mlx_get_data_addr(refs.img_ptr, &refs.img_bpp, 
    &refs.img_size_line, &refs.img_endian);
     calculate_dist(map, &refs);
    mlx_put_image_to_window(refs.mlx_ptr, refs.mlx_win, refs.img_ptr, 0, 0);
     calculate_dist2(map, &refs);
   //   display_walls_diag_right(&refs, (double)(x = -y + 26), (double)(y = height));
     // display_wall_vertical(&refs, 0, height / 2);
      // display_wall_horizontal(&refs, width / 2, 0);
  //  mlx_pixel_put(refs.mlx_ptr, refs.mlx_win, i, j, 0xFFFFFF);
    mlx_loop(refs.mlx_ptr);
}