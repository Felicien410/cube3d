/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:07:13 by feliciencat       #+#    #+#             */
/*   Updated: 2023/10/23 15:37:55 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

void	remake(t_all *a)
{
	mlx_destroy_image(a->mlxdatas.mlx, a->mlxdatas.img);
	a->mlxdatas.img = mlx_new_image(a->mlxdatas.mlx, WIDTH, HEIGHT);
	mlx_clear_window(a->mlxdatas.mlx, a->mlxdatas.win);
	raycast_and_draw(a);
	mlx_put_image_to_window(a->mlxdatas.mlx, a->mlxdatas.win,
		a->mlxdatas.img, 0, 0);
}

void	move_right(t_all *a)
{
	if (a->map.map[(int)(a->c.pos_x + a->c.plane_x * a->c.move_speed)]
		[(int)(a->c.pos_y)] == '0')
		a->c.pos_x += a->c.plane_x / 2 * a->c.move_speed;
	if (a->map.map[(int)(a->c.pos_x)][(int)(a->c.pos_y + a->c.plane_y
		* a->c.move_speed)]
		== '0')
		a->c.pos_y += a->c.plane_y / 2 * a->c.move_speed;
	remake(a);
}

void	close_program(t_all *a)
{
	mlx_destroy_window(a->mlxdatas.mlx, a->mlxdatas.win);
	exit(0);
}

int	key_press(int keycode, t_all *a)
{
	if (keycode == 123)
		go_left(a);
	if (keycode == 124)
		go_right(a);
	if (keycode == 1)
		move_backward(a);
	if (keycode == 13)
		move_forward(a);
	if (keycode == 0)
		move_left(a);
	if (keycode == 2)
		move_right(a);
	if (keycode == ESC)
		close_program(a);
	return (0);
}
