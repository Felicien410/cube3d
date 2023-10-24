/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 07:31:16 by feliciencat       #+#    #+#             */
/*   Updated: 2023/10/23 15:59:13 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

void	init_for_dda(t_all *a)
{
	a->c.camera_x = 2 * a->c.x / (double)WIDTH - 1;
	a->c.raydir_x = a->c.dir_x
		+ a->c.plane_x * a->c.camera_x;
	a->c.raydir_y = a->c.dir_y
		+ a->c.plane_y * a->c.camera_x;
	a->c.map_x = (int)a->c.pos_x;
	a->c.map_y = (int)a->c.pos_y;
	if (a->c.raydir_x == 0)
		a->c.deltadist_x = 1e30;
	else
		a->c.deltadist_x = sqrt(1 + (a->c.raydir_y
					* a->c.raydir_y) / (a->c.raydir_x * a->c.raydir_x));
	if (a->c.raydir_y == 0)
		a->c.deltadist_y = 1e30;
	else
	{
		a->c.deltadist_y = sqrt(1 + (a->c.raydir_x
					* a->c.raydir_x) / (a->c.raydir_y * a->c.raydir_y));
	}
	a->c.step_x = 0;
	a->c.step_y = 0;
	a->c.hit = 0;
	a->c.side = 0;
}

void	calcul_sidedist(t_all *a)
{
	if (a->c.raydir_x < 0)
	{
		a->c.step_x = -1;
		a->c.sidedist_x = (a->c.pos_x - a->c.map_x) * a->c.deltadist_x;
	}
	else
	{
		a->c.step_x = 1;
		a->c.sidedist_x = (a->c.map_x + 1.0 - a->c.pos_x) * a->c.deltadist_x;
	}
	if (a->c.raydir_y < 0)
	{
		a->c.step_y = -1;
		a->c.sidedist_y = (a->c.pos_y - a->c.map_y) * a->c.deltadist_y;
	}
	else
	{
		a->c.step_y = 1;
		a->c.sidedist_y = (a->c.map_y + 1.0 - a->c.pos_y) * a->c.deltadist_y;
	}
}

void	perfom_dda(t_all *a)
{
	while (a->c.hit == 0)
	{
		if (a->c.sidedist_x < a->c.sidedist_y)
		{
			a->c.sidedist_x += a->c.deltadist_x;
			a->c.map_x += a->c.step_x;
			a->c.side = 0;
		}
		else
		{
			a->c.sidedist_y += a->c.deltadist_y;
			a->c.map_y += a->c.step_y;
			a->c.side = 1;
		}
		if (a->map.map[(int)a->c.map_x][(int)a->c.map_y] == '1')
			a->c.hit = 1;
	}
}

void	choose_texture(t_all *a)
{
	if (a->c.side == 0 && a->c.raydir_x < 0)
	{
		a->c.color_text = a->texture.img_data[0][TEXHEIGHT
			* a->texture.tex_y + a->texture.tex_x];
	}
	if (a->c.side == 0 && a->c.raydir_x > 0)
	{
		a->c.color_text = a->texture.img_data[1][TEXHEIGHT
			* a->texture.tex_y + a->texture.tex_x];
	}
	if (a->c.side == 1 && a->c.raydir_y < 0)
	{
		a->c.color_text = a->texture.img_data[3][TEXHEIGHT
			* a->texture.tex_y + a->texture.tex_x];
	}
	if (a->c.side == 1 && a->c.raydir_y > 0)
	{
		a->c.color_text = a->texture.img_data[2][TEXHEIGHT
			* a->texture.tex_y + a->texture.tex_x];
	}
}

int	raycast_and_draw(t_all *a)
{
	init_mlx_and_textures(a);
	while (a->c.x < WIDTH)
	{
		init_for_dda(a);
		calcul_sidedist(a);
		perfom_dda(a);
		calculate_wall_dist(a);
		while (a->c.y < a->c.drawend)
		{
			a->texture.tex_y = (int)a->texture.tex_pos & (TEXHEIGHT - 1);
			a->texture.tex_pos += a->texture.step;
			choose_texture(a);
			if (a->c.side == 1)
				a->c.color_text = (a->c.color_text >> 1) & 8355711;
			a->mlxdatas.img_addr[a->c.y * WIDTH + a->c.x] = a->c.color_text;
			a->c.y++;
		}
		a->c.x++;
	}
	mlx_put_image_to_window(a->mlxdatas.mlx,
		a->mlxdatas.win, a->mlxdatas.img, 0, 0);
	return (0);
}
