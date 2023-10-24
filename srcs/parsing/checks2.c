/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:43:46 by fabperei          #+#    #+#             */
/*   Updated: 2023/10/23 16:36:58 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

int	check2(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error\nOnly 2 arguments accepted\n");
		return (1);
	}
	if (verif_cub(argv[1]) || verif_isnt_directory(argv[1]) \
	|| is_file_empty(argv[1]))
		return (1);
	return (0);
}

int	check3(t_all *a)
{
	if (a->map.path_nb != 4)
	{
		error_print("Executable need 4 .xpm file\n", a);
		return (1);
	}
	if ((a->map.floor_red < 0 || a->map.floor_green < 0 \
	|| a->map.floor_blue < 0) || (a->map.floor_red > 255 \
	|| a->map.floor_green > 255 || a->map.floor_blue > 255) || \
	(a->map.ceiling_red < 0 || a->map.ceiling_green < 0 || \
	a->map.ceiling_blue < 0) || (a->map.ceiling_red > 255 || \
	a->map.ceiling_green > 255 || a->map.ceiling_blue > 255))
	{
		error_print("Invalid RGB color\n", a);
		return (1);
	}
	if (verif_xpm(a->map.path_ea, a) || verif_xpm(a->map.path_no, a) \
	|| verif_xpm(a->map.path_so, a) || verif_xpm(a->map.path_we, a))
		return (1);
	if (a->map.player != 1)
	{
		error_print("Need 1 player on the map\n", a);
		return (1);
	}
	return (0);
}

t_index_vars	init_index_vars(char **argv)
{
	t_index_vars	vars;

	vars.fd3 = open(argv[1], O_RDONLY);
	vars.line = get_next_line(vars.fd3);
	vars.i = 0;
	vars.index = 0;
	return (vars);
}
