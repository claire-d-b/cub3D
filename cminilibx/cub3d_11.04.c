#include "cub3D.h"

#define realwidth 800
#define realheight 600
#define width 24
#define height 32
#define player->maxidth 24
#define player->table_lenghteight 32
#define M_PI 3.14159265359

void init_struct(t_ids *refs) //initialisation de la structure nous servant à créer, identifier une fenêtre etc
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

void init_ray(t_ray *ray) //initialise les coordonnées des points dont les intersections seront enregistrées plus tard
{
    ray->imh = 0;
    ray->jmh = 0;
    ray->xmh = 0;
    ray->ymh = 0;
    ray->dimh = 0;
    ray->imv = 0;
    ray->jmv = 0;
    ray->xmv = 0;
    ray->ymv = 0;
    ray->dimv = 0;
}

void impact1(int i, int j, int jd, double x, double y, double xcam, double ycam, t_ray *ray) 
//enregistrement des coordonnées d'impact avec les horizontales
{
    ray->imh = i;
    ray->jmh = j - jd;
    ray->xmh = x;
    ray->ymh = y;
    ray->dimh = (x - xcam) * (x - xcam) + (y - ycam) * (y - ycam);
}

void impact2(int i, int j, int id, double x, double y, double xcam, double ycam, t_ray *ray)
//enregistrement des coordonnées d'impact avec les verticales
{
    ray->imv = i - id;
    ray->jmv = j;
    ray->xmv = x;
    ray->ymv = y;
    ray->dimv = (x -xcam) * (x -xcam) + (y - ycam) * (y - ycam);
}

void replace_ray(t_ray *ray) // remplacement des coordonnées du point par celles du point le plus proche
{
    ray->imv = ray->imh;
    ray->jmv = ray->jmh;
    ray->xmv = ray->xmh;
    ray->ymv = ray->xmh;
    ray->dimv = ray->dimh;
}

void print_coord(t_ray *ray) //impression des coordonnées des points des intersections pour vérification
{
    printf("ray->imh = %d\n", ray->imh);
    printf("ray->jmh = %d\n", ray->jmh);
  //  printf("ray->xmh = %f\n", ray->xmh);
  //  printf("ray->ymh = %f\n", ray->ymh);
 //   printf("ray->dimh = %f\n", ray->dimh);
    printf("ray->imv = %d\n", ray->imv);
    printf("ray->jmv = %d\n", ray->jmv);
//    printf("ray->xmv = %f\n", ray->xmv);
 //   printf("ray->ymv = %f\n", ray->ymv);
 //   printf("ray->dimv = %f\n", ray->dimv);
}

void set_rays(char **map, int w, int h, t_ray *ray, t_ids *refs) 
//fonction à modifier qui donne les points d'intersection avec les rayons
{
    int imax;
    int jmax;
    int icam;
    int jcam;
    int tm;
    int it2;
    int it;
    int i;
    int j;
    double xcam;
    double ycam;
    double xy;
    double dt;
    double t;
    double tgt;
    double x;
    double y;
    int id;
    int jd;
    
    xy = 1;
    imax = w;
    jmax = h;
    xcam = (xy * imax) / 2;
    ycam = 1.5 * xy;
    icam = (int)xcam;
    jcam = (int)ycam;
    t = 60; // j'ai choisi ce t arbitrairement
    i = xcam;
    j = ycam;
    x = xcam;
    y = ycam;

    while (t < 120)
    {
        if (t < -180)
            t = t + 360;
        else if (180 < t)
            t = t - 360;
        tgt = tan(t * (M_PI / 180));
        id = 1;
        if (t < 90 && -90 < t)
            id = 0;
        jd = 0;
        if (t < 0)
            jd = 1;
        i = icam + 1 - jd;
        j = jcam + 1 - id;
        init_ray(ray);
        while (i - id < imax - 1 && i - id >= 0 && j - jd < jmax - 1 && j - jd >= 0 && map[i - id])
        {
         //   init_ray(ray);
            if (i - id < imax - 1 && i - id >= 0 && j - jd < jmax - 1 && j - jd >= 0 && map[i - id][j] == '1')
            {
                x = (double)i;
                y = ycam + ((x - xcam) * tgt);
                j = (int)y;
                impact1(i, j, jd, x, y, xcam, ycam, ray);
                print_coord(ray);
                while (i - id < imax - 1 && i - id >= 0 && j - jd < jmax - 1 && j - jd >= 0 && map[i][j - jd])
                {
                    if (map[i - id][j] == '1')
                    {
                        y = (double)j;
                        x = xcam + (y - ycam) / tgt;
                        i = (int)x;
                        impact2(i, j, jd, x, y, xcam, ycam, ray);
                        print_coord(ray);
                        if (ray->dimv < ray->dimh)
                            replace_ray(ray);
                    }
                    j = j + 1 - (jd * 2);
                    y = (double)j;
                    x = xcam + (y - ycam) / tgt;
                    i = (int)x;
                    }
                }
                i = i + 1 - (2 * id);
                x = (double)i;
                y = ycam + ((x - xcam) * tgt);
                j = (int)y;
            }
        t++;
    }
}

char **create_map(int i, char **map) // fonction qui crée la carte avec les 1 et 0
{
    int fd;
    char *line;
    int x;
    int y;

    y = 0;
    x = 0;
    fd = open("map2.txt", O_RDONLY); //on ouvre le fichier texte map2.txt et on le lit
    if (!(map = malloc(sizeof(char *) * (player->table_lenghteight + 1))))
      return (0); 
    // on alloue la mémoire pour un double tableau en disant qu'il contient player->table_lenghteight
    // (32 définit tout en haut) lignes (ou tableaux simples), et on rajoute 1 pour pouvoir affecter 
    // à la dernière ligne du double tableau la valeur 0. Ca permet de le parcourir par la suite
    // tant que map[i] différent de 0
    while (i = get_next_line(fd, &line)) // get_next line est une fonction qui lit une ligne du document map2.txt
    // et qui renvoie 1. Elle remplit "line" avec la ligne considérée
    {
        if (!(map[y] = malloc(sizeof(char) * (player->maxidth + 1))))
          return (0); //on alloue la mémoire pour chaque ligne du tableau dans une boucle (tant que get_next_line renvoie 1)
        while (x < ft_strlen(line)) //ft_strlen(line) correspond à la longueur de la ligne (qui est aussi un tableau simple ou une chaine de caractères)
        {
            map[y][x] = line[x]; //on remplit chaque ligne de notre carte avec ce que contient le fichier qu'on lit
            x++;
        }
        y++;
        x = 0;
        free(line); // on libère la mémoire de line dont on ne se sert plus
    }
    map[y] = line;
    map[y + 1] = 0; // on affecte la valeur 0 à la dernière ligne du tableau pour pouvoir le parcourir après
    return (map);
}

int main() //fonction principale et qui permet d'afficher la fenetre
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
    init_struct(&refs); 
    init_ray(&ray); // initialisation des structures
    map = create_map(0, map); // création de la carte
    refs.mlx_ptr = mlx_init(); // fonction de la librairie minilibx préalable à l'ouverture d'une fenêtre
    refs.mlx_win = mlx_new_window(refs.mlx_ptr, realwidth, realheight, title); // fonction qui 
    //permet d'ouvrir une nouvelle fenêtre avec la largeur "realwidth" et la hauteur "realheight" 
    //définies tout en haut
    refs.img_ptr = mlx_new_image(refs.mlx_ptr, realwidth, realheight); 
    refs.img_data = (int *)mlx_get_data_addr(refs.img_ptr, &refs.img_bpp, 
    &refs.img_size_line, &refs.img_endian); // fonctions permettant l'affichage d'images sur la fenêtre
    mlx_put_image_to_window(refs.mlx_ptr, refs.mlx_win, refs.img_ptr, 0, 0); //fonction qui affiche des choses dans la fenêtre
    set_rays(map, w, h, &ray, &refs); //notre fonction qui établit des rayons
    mlx_hook(refs.mlx_ptr, X_EVENT_KEY_PRESS, 1, key_press, void*(refs.ev));
    printf("REFS EV = %d\n", refs.ev);
    mlx_loop(refs.mlx_ptr); // foncton finale qui coordonne toues les autres (affichage de fenêtre etc)
}