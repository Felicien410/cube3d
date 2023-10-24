/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabperei <fabperei@student.42nice.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:23:09 by fabperei          #+#    #+#             */
/*   Updated: 2023/10/23 12:49:48 by fabperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

void	add_map(char *line, t_all *a)
{
	int	i;

	i = 0;
	if (ft_strchr_count(line, '1') < 2 && \
	ft_strchr_count(line, ',') && ft_line_empty(line))
		return ;
	if (a->map.map == NULL)
		create_map(a);
	while (line[i])
	{
		if (line[i] == '\n')
		{
			a->map.map[a->map.map_line2][i] = '\0';
			if (line[i] == '\n' && ft_strchr_count(line, '1') >= 2)
				a->map.map_line2++;
			return ;
		}
		create_map2(line[i], i, a);
		i++;
	}
}

void	create_map(t_all *a)
{
	int	i;

	i = 0;
	a->map.map = (char **)malloc(sizeof(char *) * (a->map.mapheight + 2));
	while (i < a->map.mapheight)
	{
		a->map.map[i] = (char *)malloc(a->map.long_map + 1);
		i++;
	}
	a->map.map[a->map.mapheight] = NULL;
}

void	create_map2(char line, int i, t_all *a)
{
	if (line == ' ' || line == '\t')
		a->map.map[a->map.map_line2][i] = '1';
	else if (line == '1')
		a->map.map[a->map.map_line2][i] = '1';
	else if (line == '0')
		a->map.map[a->map.map_line2][i] = '0';
	else if (line == 'N' || line == 'E' || line == 'W'\
	|| line == 'S')
	{
		a->c.orientation = line;
		a->map.player++;
		a->map.map[a->map.map_line2][i] = '0';
		a->map.player_x = i;
		a->map.player_y = a->map.map_line2;
		if (a->map.player > 1)
		{
			error_print("Only one player accepted", a);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		error_print("Wrong data in the map", a);
		exit(EXIT_FAILURE);
	}
}
