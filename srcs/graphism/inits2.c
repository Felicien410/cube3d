/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:07:24 by feliciencat       #+#    #+#             */
/*   Updated: 2023/10/21 23:26:58 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

void	init_direction_w(t_all *a)
{
	a->c.dir_x = 0;
	a->c.dir_y = -1;
	a->c.plane_x = -0.66;
	a->c.plane_y = 0;
}

void	init_direction_e(t_all *a)
{
	a->c.dir_x = 0;
	a->c.dir_y = 1;
	a->c.plane_x = 0.66;
	a->c.plane_y = 0;
}

void	init_direction_s(t_all *a)
{
	a->c.dir_x = 1;
	a->c.dir_y = 0;
	a->c.plane_x = 0;
	a->c.plane_y = -0.66;
}

void	init_direction_n(t_all *a)
{
	a->c.dir_x = -1;
	a->c.dir_y = 0;
	a->c.plane_x = 0;
	a->c.plane_y = 0.66;
}
