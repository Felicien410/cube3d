/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:08:50 by feliciencat       #+#    #+#             */
/*   Updated: 2023/10/21 23:41:02 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

void	init_fandc(t_all *all)
{
	all->floor.raydir_x0 = all->c.dir_x - all->c.plane_x;
	all->floor.raydir_y0 = all->c.dir_y - all->c.plane_y;
	all->floor.raydir_x1 = all->c.dir_x + all->c.plane_x;
	all->floor.raydir_y1 = all->c.dir_y + all->c.plane_y;
	all->floor.p = all->floor.y - HEIGHT / 2;
	all->floor.pos_z = 0.5 * HEIGHT;
	all->floor.row_distance = all->floor.pos_z / all->floor.p;
	all->floor.floorstep_x = all->floor.row_distance
		* (all->floor.raydir_x1 - all->floor.raydir_x0) / WIDTH;
	all->floor.floorstep_y = all->floor.row_distance
		* (all->floor.raydir_y1 - all->floor.raydir_y0) / WIDTH;
	all->floor.floor_x = all->c.pos_x
		+ all->floor.row_distance * all->floor.raydir_x0;
	all->floor.floor_y = all->c.pos_y
		+ all->floor.row_distance * all->floor.raydir_y0;
	all->floor.x = 0;
}

void	render_floor_and_ceiling(t_all *all)
{
	int	colorvalue;

	all->floor.y = HEIGHT / 2 + 1;
	while (++all->floor.y < HEIGHT)
	{
		init_fandc(all);
		while (++all->floor.x < WIDTH)
		{
			all->floor.cell_x = (int)(all->floor.floor_x);
			all->floor.cell_y = (int)(all->floor.floor_y);
			all->floor.floor_x += all->floor.floorstep_x;
			all->floor.floor_y += all->floor.floorstep_y;
			colorvalue = (all->map.floor_red << 16)
				| (all->map.floor_green << 8) | all->map.floor_blue;
			all->mlxdatas.img_addr[all->floor.y
				* WIDTH + all->floor.x] = colorvalue;
			colorvalue = (all->map.ceiling_red << 16)
				| (all->map.ceiling_blue << 8) | all->map.ceiling_green;
			all->mlxdatas.img_addr[(HEIGHT - all->floor.y - 1)
				* WIDTH + all->floor.x] = colorvalue;
		}
	}
}
