#include "cub3D.h"

#define width 640
#define height 480
#define player->maxidth 24
#define player->table_lenghteight 32
#define KEY_LEFT 123
#define KEY_RIGHT 124
#define KEY_UP 126
#define KEY_DOWN 125
#define FOV_H 92

void init_struct(t_ids *refs)
{
    refs->mlx_ptr = 0;
    refs->mlx_win = 0;
}

void draw_line(int x, int drawStart, int drawEnd, t_ids *refs)
{
  while (drawStart < drawEnd)
  {
  refs->img_data[drawStart] = 0xFFFFFF;
  drawStart++;
  }
}

int key_press()
{
  return (1);
}

void  display_walls(char **map, t_ids *refs)
{
  int x;
  double rayDirX;
  double rayDirY;
  double cameraX;
  int color;

  x = 0;
  double posX = 22, posY = 12;  //x and y start position
  double dirX = -1, dirY = 0; //initial direction vector
  double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

  double time = 0; //time of current frame
  double oldTime = 0; //time of previous frame

    while (x < player->maxidth)
    {
      //calculate ray position and direction
      cameraX = 2 * x / (double)player->maxidth - 1; //x-coordinate in camera space
      rayDirX = dirX + planeX * cameraX;
      rayDirY = dirY + planeY * cameraX;

  //which box of the map we're in
      int mapX = (int)posX;
      int mapY = (int)posY;

      //length of ray from current position to next x or y-side
      double sideDistX;
      double sideDistY;

       //length of ray from one x or y-side to next x or y-side
      double deltaDistX = (rayDirY == 0) ? 0 : ((rayDirX == 0) ? 1 : abs(1 / rayDirX));
      double deltaDistY = (rayDirX == 0) ? 0 : ((rayDirY == 0) ? 1 : abs(1 / rayDirY));
      double perpWallDist;

      //what direction to step in x or y-direction (either +1 or -1)
      int stepX;
      int stepY;

      int hit = 0; //was there a wall hit?
      int side; //was a NS or a EW wall hit?
//calculate step and initial sideDist
      if (rayDirX < 0)
      {
        stepX = -1;
        sideDistX = (posX - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - posX) * deltaDistX;
      }
      if (rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (posY - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - posY) * deltaDistY;
      }
//perform DDA
      while (hit == 0)
      {
        //jump to next map square, OR in x-direction, OR in y-direction
        if (sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
        if (map[mapX][mapY] != '0') hit = 1;
      } 
       //Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
      if (side == 0) perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
      else           perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

       //Calculate height of line to draw on screen
      int lineHeight = (int)(player->table_lenghteight / perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + player->table_lenghteight / 2;
      if(drawStart < 0)drawStart = 0;
      int drawEnd = lineHeight / 2 + player->table_lenghteight / 2;
      if(drawEnd >= player->table_lenghteight)drawEnd = player->table_lenghteight - 1;
      //choose wall color
      //draw the pixels of the stripe as a vertical line
      switch(map[mapX][mapY])
      {
        case '0':  color = 0xFFFFFF;  break; //red
        case '1':  color = 0xFFFFFF;  break; //green
        case '2':  color = 0xFFFFFF;   break; //blue
        case '3':  color = 0xFFFFFF;  break; //white
        default: color = 0xFFFFFF; break; //yellow
      }

      //give x and y sides different brightness
      if (side == 1) {color = color / 2;}
      draw_line(x, drawStart, drawEnd, refs);
      x++;
    }
    //timing for input and FPS counter
    oldTime = time;
  //  time = getTicks();
  time = oldTime * 2;
    double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
   // print(1.0 / frameTime); //FPS counter
   // redraw();
   // cls();

    //speed modifiers
    double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
    double rotSpeed = frameTime * 3.0; //the constant value is in radians/second
   // readKeys();
    //move forward if no wall in front of you
    if(mlx_hook(refs->mlx_win, KEY_UP, 0, &key_press, 0))
    {
      if(map[(int)(posX + dirX * moveSpeed)][(int)posY] == '0') 
        posX += dirX * moveSpeed;
      if(map[(int)posX][(int)(posY + dirY * moveSpeed)] == '0')
        posY += dirY * moveSpeed;
    }
    //move backwards if no wall behind you
    if(mlx_hook(refs->mlx_win, KEY_DOWN, 0, &key_press, 0))
    {
      if(map[(int)(posX - dirX * moveSpeed)][(int)posY] == '0') posX -= dirX * moveSpeed;
      if(map[(int)posX][(int)(posY - dirY * moveSpeed)] == '0') posY -= dirY * moveSpeed;
    }
    //rotate to the right
    if(mlx_hook(refs->mlx_win, KEY_RIGHT, 0, &key_press, 0))
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = dirX;
      dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
      dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
      planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
    }
    //rotate to the left
    if(mlx_hook(refs->mlx_win, KEY_LEFT, 0, &key_press, 0))
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = dirX;
      dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
      dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
      planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
    }
  }

void  display_map(char **map, t_ids *refs)
{
   display_walls(map, refs);
}

int main()
{
    char const *title;
    t_ids refs;
    int fd;
    char *line;
    int i;
    int x;
    int y;
    int index;
    int count;
    char **map;
    
    if (!(map = malloc(sizeof(char *) * player->table_lenghteight)))
      return (0);
    count = 1;
    title = "cub3D";
    index = 0;
    i = 0;
    x = 0;
    y = 0;
    init_struct(&refs);
    fd = open("map2.txt", O_RDONLY);
    while (i = get_next_line(fd, &line))
    {
        if (!(map[y] = malloc(sizeof(char) * player->maxidth))))
          return (0);
        map[y] = line;
        printf("%s\n", map[y]);
        y++;
        free(line);
    }
    map[y] = line;
    printf("%s\n", map[y]);
    free(line);
    refs.mlx_ptr = mlx_init();
   refs.mlx_win = mlx_new_window(refs.mlx_ptr, width, height, title);
   refs.img_ptr = mlx_new_image(refs.mlx_ptr, width, height);
    refs.img_data = (int *)mlx_get_data_addr(refs.img_ptr, &refs.img_bpp, 
    &refs.img_size_line, &refs.img_endian);
  //  mlx_put_image_to_window(refs.mlx_ptr, refs.mlx_win, refs.img_ptr, 0, 0);
  //  refs.pixel_data = mlx_pixel_put(refs.mlx_ptr, refs.mlx_win, x, y, 0x8497E4);
  y = 0;
      while (x < width)
      {
        y = 0;
        while (y < height)
        {
          refs.img_data[y / 2 * width + x] = 0x8497E4;
          refs.img_data[y * width + x] = 0xDF0006;
          y++;
        }
        x++;
      }
    display_map(map, &refs);
    mlx_put_image_to_window(refs.mlx_ptr, refs.mlx_win, refs.img_ptr, 0, 0);
  //  mlx_pixel_put(refs.mlx_ptr, refs.mlx_win, i, j, 0xFFFFFF);
    mlx_loop(refs.mlx_ptr);
}