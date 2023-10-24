/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 07:31:16 by feliciencat       #+#    #+#             */
/*   Updated: 2023/10/23 15:59:19 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

void	init_mlx_and_textures(t_all *a)
{
	a->c.x = 0;
	a->mlxdatas.img_addr = (unsigned int *)mlx_get_data_addr(a->mlxdatas.img,
			&a->mlxdatas.bits_per_pixel,
			&a->mlxdatas.line_length, &a->mlxdatas.endian);
	init_textures(a);
	render_floor_and_ceiling(a);
}

void	calcul_tex_x(t_all *a)
{
	if (a->c.side == 0 && a->c.raydir_x > 0)
		a->texture.tex_x = TEXWIDTH - a->texture.tex_x - 1;
	if (a->c.side == 1 && a->c.raydir_y < 0)
		a->texture.tex_x = TEXWIDTH - a->texture.tex_x - 1;
	a->texture.wall_x -= floor(a->texture.wall_x);
}

void	calculate_wall_dist(t_all *a)
{
	if (a->c.side == 0)
		a->c.perp_wall_dist = (a->c.map_x - a->c.pos_x
				+ (1 - a->c.step_x) / 2) / a->c.raydir_x;
	else
	{
		a->c.perp_wall_dist = (a->c.map_y - a->c.pos_y
				+ (1 - a->c.step_y) / 2) / a->c.raydir_y;
	}
	a->c.line_height = (int)(HEIGHT / a->c.perp_wall_dist);
	a->c.drawstart = -(a->c.line_height) / 2 + HEIGHT / 2;
	if (a->c.drawstart < 0)
		a->c.drawstart = 0;
	a->c.drawend = a->c.line_height / 2 + HEIGHT / 2;
	if (a->c.drawend >= HEIGHT)
		a->c.drawend = HEIGHT - 1;
	if (a->c.side == 0)
		a->texture.wall_x = a->c.pos_y + a->c.perp_wall_dist * a->c.raydir_y;
	else
		a->texture.wall_x = a->c.pos_x + a->c.perp_wall_dist * a->c.raydir_x;
	calcul_tex_x(a);
	a->texture.tex_x = (int)(a->texture.wall_x * (double)TEXWIDTH);
	a->texture.step = 1.0 * TEXHEIGHT / a->c.line_height;
	a->texture.tex_pos = (a->c.drawstart - HEIGHT
			/ 2 + a->c.line_height / 2) * a->texture.step;
	a->c.y = a->c.drawstart;
}
