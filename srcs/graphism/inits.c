/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:18:15 by feliciencat       #+#    #+#             */
/*   Updated: 2023/10/21 23:41:02 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

void	mlx_begin(t_all *a)
{
	a->mlxdatas.mlx = mlx_init();
	a->mlxdatas.win = mlx_new_window(a->mlxdatas.mlx,
			WIDTH, HEIGHT, "Le jeu videal");
	a->mlxdatas.img = mlx_new_image(a->mlxdatas.mlx, WIDTH, HEIGHT);
	mlx_hook(a->mlxdatas.win, 2, 1L << 0, key_press, a);
	mlx_hook(a->mlxdatas.win, 17, 0, exit_close, a);
	mlx_loop_hook(a->mlxdatas.mlx, raycast_and_draw, a);
	mlx_put_image_to_window(a->mlxdatas.mlx,
		a->mlxdatas.win, a->mlxdatas.img, 0, 0);
	mlx_loop(a->mlxdatas.mlx);
}

void	init_coordonates(t_all *a)
{
	a->c.pos_x = a->map.player_y + 0.5;
	a->c.pos_y = a->map.player_x + 0.5;
	if (a->c.orientation == 'W')
		init_direction_w(a);
	else if (a->c.orientation == 'E')
		init_direction_e(a);
	else if (a->c.orientation == 'S')
		init_direction_s(a);
	else if (a->c.orientation == 'N')
		init_direction_n(a);
	else
	{
		printf("Erreur: orientation non reconnue!\n");
		exit(1);
	}
	a->c.perp_wall_dist = 0;
	a->c.move_speed = 0.30;
	a->c.rot_speed = 0.24;
	a->c.x = 0;
}

void	put_textures(t_all *a)
{
	a->texture.img_data[0] = (int *)mlx_get_data_addr(a->texture.img[0],
			&a->mlxdatas.bits_per_pixel,
			&a->mlxdatas.line_length, &a->mlxdatas.endian);
	a->texture.img_data[1] = (int *)mlx_get_data_addr(a->texture.img[1],
			&a->mlxdatas.bits_per_pixel,
			&a->mlxdatas.line_length, &a->mlxdatas.endian);
	a->texture.img_data[2] = (int *)mlx_get_data_addr(a->texture.img[2],
			&a->mlxdatas.bits_per_pixel,
			&a->mlxdatas.line_length, &a->mlxdatas.endian);
	a->texture.img_data[3] = (int *)mlx_get_data_addr(a->texture.img[3],
			&a->mlxdatas.bits_per_pixel,
			&a->mlxdatas.line_length, &a->mlxdatas.endian);
}

void	init_textures(t_all *a)
{
	int	tmpwidth;
	int	tmpheight;

	a->texture.img[0] = mlx_xpm_file_to_image(a->mlxdatas.mlx,
			a->map.path_no, &tmpwidth, &tmpheight);
	a->texture.img[1] = mlx_xpm_file_to_image(a->mlxdatas.mlx,
			a->map.path_so, &tmpwidth, &tmpheight);
	a->texture.img[2] = mlx_xpm_file_to_image(a->mlxdatas.mlx,
			a->map.path_ea, &tmpwidth, &tmpheight);
	a->texture.img[3] = mlx_xpm_file_to_image(a->mlxdatas.mlx,
			a->map.path_we, &tmpwidth, &tmpheight);
	if (a->texture.img[0] == 0 || a->texture.img[1] == 0
		|| a->texture.img[2] == 0 || a->texture.img[3] == 0)
	{
		printf("xpm empty\n");
		exit(1);
	}
	put_textures(a);
}
