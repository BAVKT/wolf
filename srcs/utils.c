/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 16:41:50 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/16 20:01:49 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** All the error messages
*/

void	error(int e)
{
			ft_putendlcolor("error()", MAGENTA);
	if (e == 0 || e == 1)
	{
		ft_putendl_fd("Usage : ./wolf map/map1", 2);
		exit(1);
	}
	else if (e == 2)
		ft_putendl_fd("Multithreading failed.", 2);
	else if (e == 3)
		ft_putendl_fd("File is empty or doesn't exist.", 2);
	else if (e == 4)
		ft_putendl_fd("Map contain some wrong char.", 2);
	else if (e == 5)
		ft_putendl_fd("Argument given is not a file.", 2);
	else if (e == 6)
		ft_putendl_fd("Map is not okay.", 2);
	else if (e == 7)
		ft_putendl_fd("Somes map values are too high or under 0.", 2);
	else if (e == 8)
		ft_putendl_fd("Malloc failed", 2);
	exit(1);
}

/*
** Free all the tabs needed
*/

int		clean(t_base *b)
{
			ft_putendlcolor("clean()", MAGENTA);
	mlx_destroy_window(b->mx.mlx, b->mx.win);
	mlx_destroy_image(b->mx.mlx, b->mx.img);
	free(b->z);
	ft_strdel(&b->av);
	exit(0);
	return (0);
}

/*
** Return the color dependind on the int of the block
*/

int		get_color(int z)
{
			//ft_putendlcolor("get_color()", MAGENTA);
	unsigned int color;

	color = 0xffffff;
	if (z == 0)
		color = 0xffffff;
	else if (z == 1)
		color = R;
	else if (z == 2)
		color = G;
	else if (z == 3)
		color = B;
	else if (z == 4)
		color = W;
	else if (z == 5)
		color = Y;
	return (color);
}
