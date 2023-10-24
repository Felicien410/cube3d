/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:49:03 by feliciencat       #+#    #+#             */
/*   Updated: 2023/10/21 23:05:39 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube.h"

int	main(int argc, char **argv)
{
	t_all	a;

	if (check(argc, argv, &a))
		return (1);
	init_coordonates(&a);
	mlx_begin(&a);
	return (0);
}
