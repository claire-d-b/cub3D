/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codes.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:24:50 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/19 17:29:17 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3DCODES_H
# define CUB3DCODES_H

# ifndef M_PI
#  define M_PI 3.14159265358979323846f
# endif
# define VIEW_ANGLE M_PI/2
# define FOV M_PI/3
# define CELL_SIZE 64
# define EPSILON 0.02f
# define ROTATION M_PI/8
# define MOVE_RIGHT 100
# define MOVE_LEFT 115
# define MOVE_UP 97
# define MOVE_DOWN 119
# define ESCAPE 65307 
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define KEY_PRESS_EV 2
# define EXIT_EV 17

#endif
