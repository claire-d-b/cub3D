/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsefile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 11:40:30 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/18 15:41:15 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int set_path_to_texture_ns(t_player *player, char *line)
{
    char *to_record;
    int count;

    count = 0;
    to_record = ft_strchr(line, '.');
    if (line[count] == 'N' && line[count + 1] == 'O' && count == 0)
            {
                if (!(ft_strncmp((const char *)to_record, "./text1.xpm", ft_strlen(to_record)) == 0))
                {
                    write(1, "Error\nWrong path to north texture.", 34);
                    return (-1);
                }
                else
                player->xpm_path_no = ft_strdup(to_record);
            }
            if (line[count] == 'S' && line[count + 1] == 'O' && count == 0)
            {
                if (!(ft_strncmp((const char *)to_record, "./text2.xpm", ft_strlen(to_record)) == 0))
                {
                    write(1, "Error\nWrong path to south texture.", 34);
                    return (-1);
                }
                player->xpm_path_so = ft_strdup(to_record);
            }
        return (1);
}

int set_path_to_texture_ew(t_player *player, char *line)
{
    char *to_record;
    int count;

    count = 0;
    to_record = ft_strchr(line, '.');
 if (line[count] == 'W' && line[count + 1] == 'E' && count == 0)
            {
                if (!(ft_strncmp((const char *)to_record, "./text3.xpm", ft_strlen(to_record)) == 0))
                {
                    write(1, "Error\nWrong path to west texture.", 33);
                    return (-1);
                }
                player->xpm_path_we = ft_strdup(to_record);
            }
            if (line[count] == 'E' && line[count + 1] == 'A' && count == 0)
            {
                to_record = ft_strchr(line, '.');
                if (!(ft_strncmp((const char *)to_record, "./text4.xpm", ft_strlen(to_record)) == 0))
                {
                    write(1, "Error\nWrong path to east texture.", 33);
                    return (-1);
                }
                player->xpm_path_ea = ft_strdup(to_record);
            }
        return (1);
}

int set_path_to_texture_sp(t_player *player, char *line)
{
    char *to_record;
    int count;

    count = 0;
    to_record = ft_strchr(line, '.');
                if (line[count] == 'S' && line[count + 1] != 'O' && count == 0)
            {
                to_record = ft_strchr(line, '.');
                if (!(ft_strncmp((const char *)to_record, "./invdiamond.xpm", ft_strlen(to_record)) == 0))
                {write(1, "Error\nWrong path to sprite texture.", 35);
                return (-1);}
                player->xpm_path_sp = ft_strdup(to_record);
            }
        return (1);
}

int set_floor_color(t_player *player, char *line)
{
    int count;
    char **to_cast;
    int j;

    count = 0;
    j = 0;
    to_cast = NULL;
                while (line[count] && ft_isdigit(line[count]) == 0)
                    count++;
                to_cast = ft_split(&line[count], ',');
                while (to_cast[j] && ft_atoi(to_cast[j]) >= 0 && ft_atoi(to_cast[j]) <= 255)
                    j++;
                if (!(j == 3))
                {write(1, "Error\nWrong color ID [floor]", 28);
                return(-1);}
                player->floor_color[0] = ft_atoi(to_cast[0]);
                player->floor_color[1] = ft_atoi(to_cast[1]);
                player->floor_color[2] = ft_atoi(to_cast[2]);
                player->floor_color[3] = rgb3((unsigned int)player->floor_color[0], (unsigned int)player->floor_color[1], (unsigned int)player->floor_color[2]);
                ft_free3(to_cast);
            return (1);
}

int set_ceiling_color(t_player *player, char *line)
{
    int count;
    char **to_cast;
    int j;

    count = 0;
    j = 0;
    to_cast = NULL;
                while (ft_isdigit(line[count]) == 0)
                    count++;
                to_cast = ft_split(&line[count], ',');
                while (to_cast[j] && ft_atoi(to_cast[j]) >= 0 && ft_atoi(to_cast[j]) <= 255)
                    j++;
                if (!(j == 3))
                {write(1, "Error\nWrong color ID [ceiling]", 30);
                return (-1);}
                player->ceil_color[0] = ft_atoi(to_cast[0]);
                player->ceil_color[1] = ft_atoi(to_cast[1]);
                player->ceil_color[2] = ft_atoi(to_cast[2]);
                player->ceil_color[3] = rgb3((unsigned int)player->ceil_color[0], (unsigned int)player->ceil_color[1], (unsigned int)player->ceil_color[2]);
                ft_free3(to_cast);
            return (1);
}
