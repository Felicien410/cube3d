/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabperei <fabperei@student.42nice.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:55:14 by fabperei          #+#    #+#             */
/*   Updated: 2023/10/23 13:39:24 by fabperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

int	verif_cub(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	i -= 4;
	if (ft_strncmp(&argv[i], ".cub", 4) == 0)
		return (0);
	else
	{
		printf("Error\nOnly .cub accepted\n");
		return (1);
	}
}

int	verif_xpm(char *file, t_all *a)
{
	int	i;

	i = 0;
	if (ft_strlen(file) < 4)
	{
		error_print("Empty path .xpm\n", a);
		return (1);
	}
	while (file[i])
		i++;
	i -= 4;
	if (ft_strncmp(&file[i], ".xpm", 4) == 0)
		return (0);
	else
	{
		error_print("Only .xpm accepted\n", a);
		return (1);
	}
}

int	verif_isnt_directory(char *argv)
{
	int	fd;

	fd = open(argv, O_DIRECTORY);
	if (fd > 0)
	{
		printf("Only file accepted.");
		return (1);
	}
	return (0);
}

int	is_file_empty(char *file)
{
	int		fd;
	char	buf[BUFFER_SIZE];
	ssize_t	bytes_read;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	bytes_read = read(fd, buf, sizeof(BUFFER_SIZE));
	close(fd);
	if (bytes_read == -1)
		return (0);
	if (bytes_read == 0)
	{
		printf("Error\nFile is empty\n");
		return (1);
	}
	return (0);
}

void	error_print(char *temp, t_all *a)
{
	printf("Error\n%s", temp);
	free_map(a);
	exit(EXIT_FAILURE);
}
