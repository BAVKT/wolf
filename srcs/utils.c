/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 16:41:50 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/21 18:49:29 by vmercadi         ###   ########.fr       */
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

int		clean(t_val *v)
{
			ft_putendlcolor("clean()", MAGENTA);
	mlx_destroy_window(v->mlx, v->win);
	mlx_destroy_image(v->mlx, v->img);
	free(v->z);
	ft_strdel(&v->av);
	exit(0);
	return (0);
}

/*
** Return the color dependind on the int of the block
*/

void	get_color(t_val *v)
{
			//ft_putendlcolor("get_color()", MAGENTA);

		if(worldMap[v->mapX][v->mapY] == 0)
			v->color = 0;
		else if(worldMap[v->mapX][v->mapY] == 1)
			v->color = 0xff0000;
		else if(worldMap[v->mapX][v->mapY] == 2)
			v->color = 0x00ff00;
		else if(worldMap[v->mapX][v->mapY] == 3)
			v->color = 0x0000ff;
		else if(worldMap[v->mapX][v->mapY] == 4)
			v->color = 0x000fff;
		else if(worldMap[v->mapX][v->mapY] == 5)
			v->color = 0x0ffff0;
	// if (murVertiOuHori == 1)
	// {
	//     v->colorR /= 2;
	//     v->colorB /= 2;
	//     v->colorG /= 2;
	// }
	// v->color = 0;
	// v->color = (v->color >> 24 | v->colorR);
	// v->color = (v->color >> 16 | v->colorG);
	// v->color = (v->color >> 8 | v->colorB);
	// verLine(x, v->drawStart, v->drawEnd, v->color);
}
