/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabperei <fabperei@student.42nice.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:43:41 by fabperei          #+#    #+#             */
/*   Updated: 2023/10/23 13:27:31 by fabperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

void	check_1_start_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] != '1' && line[i] != '\n')
	{
		printf("Error\nmap incorrect\n");
		exit(EXIT_FAILURE);
	}
	i++;
}

void	check_1_end_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	i--;
	while (line[i] == '\t' || line[i] == ' ' || line[i] == '\n')
		i--;
	if (line[i] != '1')
	{
		printf("Error\nmap incorrect\n");
		exit(EXIT_FAILURE);
	}
}

void	check_1_first_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (line[i] != '1' && line[i] != ' ' \
		&& line[i] != '\t' && line[i] != '\n')
		{
			printf("Error\nMap incorrect\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return ;
}

void	check_line(char *line, int map_line)
{
	if (ft_strchr_count(line, '1'))
	{
		if (map_line >= 1)
		{
			check_1_start_line(line);
			check_1_end_line(line);
		}
	}
}
