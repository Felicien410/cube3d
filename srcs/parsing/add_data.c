/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:43:32 by fabperei          #+#    #+#             */
/*   Updated: 2023/10/24 12:02:13 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

void	init_map_data(t_all *a)
{
	a->map.line_nb = 0;
	a->map.map_line2 = 0;
	a->map.index_end = 0;
	a->map.long_map = 0;
	a->map.color_line = 0;
	a->map.index_end = 0;
	a->map.index_start = 0;
	a->map.floor_red = -1;
	a->map.floor_green = -1;
	a->map.floor_blue = -1;
	a->map.ceiling_red = -1;
	a->map.ceiling_green = -1;
	a->map.ceiling_blue = -1;
	a->map.player_x = -1;
	a->map.player_y = -1;
	a->map.player = 0;
	a->map.path_nb = 0;
	a->map.mapheight = 0;
	a->map.mapwith = 0;
	a->map.map = NULL;
	a->map.path_no = NULL;
	a->map.path_so = NULL;
	a->map.path_we = NULL;
	a->map.path_ea = NULL;
}

void	add_color(char *line, t_all *a)
{
	int	i;

	i = 0;
	while (line[i] == ' ' && line[i])
		i++;
	while (line[i])
	{
		if (line[i] == 'F' && ft_strchr_count(&line[i], ',') == 2)
			add_color_floor(line, a);
		else if (line[i] == 'C' && ft_strchr_count(&line[i], ',') == 2)
			add_color_ceilling(line, a);
		i++;
	}
}

void	add_color_floor(char *line, t_all *a)
{
	int	i;

	i = 0;
	while (line[i] != 'F')
		i++;
	while (!ft_isdigit(line[i]))
		i++;
	a->map.floor_red = ft_atoi(&line[i]);
	while (line[i] != ',')
		i++;
	i++;
	a->map.floor_green = ft_atoi(&line[i]);
	while (line[i] != ',')
		i++;
	i++;
	a->map.floor_blue = ft_atoi(&line[i]);
	a->map.color_line = a->map.line_nb;
}

void	add_color_ceilling(char *line, t_all *a)
{
	int	i;

	i = 0;
	while (line[i] != 'C')
		i++;
	while (!ft_isdigit(line[i]))
		i++;
	a->map.ceiling_red = ft_atoi(&line[i]);
	while (line[i] != ',')
		i++;
	i++;
	a->map.ceiling_green = ft_atoi(&line[i]);
	while (line[i] != ',')
		i++;
	i++;
	a->map.ceiling_blue = ft_atoi(&line[i]);
}

int	map_height(char **argv, t_all *a)
{
	int		fd1;
	char	*line;
	int		map_height;

	fd1 = open(argv[1], O_RDONLY);
	map_height = 0;
	line = get_next_line(fd1);
	while (line)
	{
		line = get_next_line(fd1);
		if (line && !ft_strchr_count(line, ',') && !ft_strchr_count(line, '.'))
		{
			check_line(line, map_height);
			if (line && !ft_strchr_count(line, ',') && \
			!ft_strchr_count(line, '.') && ft_strchr_count(line, '1'))
				map_height++;
			if (a->map.long_map < (int)ft_strlen(line))
				a->map.long_map = ft_strlen(line);
		}
	}
	a->map.index_end = map_height;
	if (map_height == 0)
		error_print("Map incorrect\n", a);
	free(line);
	return (map_height);
}
