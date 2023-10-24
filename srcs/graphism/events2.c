/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:57:57 by feliciencat       #+#    #+#             */
/*   Updated: 2023/10/21 16:31:06 by feliciencatteau  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

void	go_right(t_all *a)
{
	a->c.olddir_x = a->c.dir_x;
	a->c.dir_x = a->c.dir_x * cos(-a->c.rot_speed)
		- a->c.dir_y * sin(-a->c.rot_speed);
	a->c.dir_y = a->c.olddir_x * sin(-a->c.rot_speed)
		+ a->c.dir_y * cos(-a->c.rot_speed);
	a->c.oldplane_x = a->c.plane_x;
	a->c.plane_x = a->c.plane_x * cos(-a->c.rot_speed)
		- a->c.plane_y * sin(-a->c.rot_speed);
	a->c.plane_y = a->c.oldplane_x * sin(-a->c.rot_speed)
		+ a->c.plane_y * cos(-a->c.rot_speed);
	remake(a);
}

void	go_left(t_all *a)
{
	a->c.olddir_x = a->c.dir_x;
	a->c.dir_x = a->c.dir_x * cos(a->c.rot_speed)
		- a->c.dir_y * sin(a->c.rot_speed);
	a->c.dir_y = a->c.olddir_x * sin(a->c.rot_speed)
		+ a->c.dir_y * cos(a->c.rot_speed);
	a->c.oldplane_x = a->c.plane_x;
	a->c.plane_x = a->c.plane_x * cos(a->c.rot_speed)
		- a->c.plane_y * sin(a->c.rot_speed);
	a->c.plane_y = a->c.oldplane_x * sin(a->c.rot_speed)
		+ a->c.plane_y * cos(a->c.rot_speed);
	remake(a);
}

void	move_backward(t_all *a)
{
	if (a->map.map[(int)(a->c.pos_x - a->c.dir_x
			* a->c.move_speed)][(int)(a->c.pos_y)] == '0')
		a->c.pos_x -= a->c.dir_x * a->c.move_speed;
	if (a->map.map[(int)(a->c.pos_x)][(int)(a->c.pos_y - a->c.dir_y
			* a->c.move_speed)] == '0')
		a->c.pos_y -= a->c.dir_y * a->c.move_speed;
	remake(a);
}

void	move_forward(t_all *a)
{
	if (a->map.map[(int)(a->c.pos_x + a->c.dir_x
			* a->c.move_speed)][(int)(a->c.pos_y)] == '0')
		a->c.pos_x += a->c.dir_x * a->c.move_speed;
	if (a->map.map[(int)(a->c.pos_x)][(int)(a->c.pos_y + a->c.dir_y
			* a->c.move_speed)] == '0')
		a->c.pos_y += a->c.dir_y * a->c.move_speed;
	remake(a);
}

void	move_left(t_all *a)
{
	if (a->map.map[(int)(a->c.pos_x - a->c.plane_x
			* a->c.move_speed)][(int)(a->c.pos_y)] == '0')
		a->c.pos_x -= a->c.plane_x / 2 * a->c.move_speed;
	if (a->map.map[(int)(a->c.pos_x)][(int)(a->c.pos_y - a->c.plane_y
			* a->c.move_speed)] == '0')
		a->c.pos_y -= a->c.plane_y / 2 * a->c.move_speed;
	remake(a);
}
