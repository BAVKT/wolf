/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 16:41:50 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/23 18:12:19 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
	#include <stdio.h>
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
	else if (e == 9)
		ft_putendl_fd("Need walls on the map borders.", 2);
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

void	get_color2(t_val *v)
{
			//ft_putendlcolor("get_color()", MAGENTA);
	if(v->z[v->mapX][v->mapY] == 3)
	{
		if(v->angle == 1)
			v->color = 0x33ccff;
		else if(v->angle == 2)
			v->color = 0x0099ff;
		else if(v->angle == 3)
			v->color = 0x0066ff;
		else if(v->angle == 4)
			v->color = 0x0000ff;
	}
	else
	{
		if(v->angle == 1)
			v->color = 0xffff99;
		else if(v->angle == 2)
			v->color = 0xffff66;
		else if(v->angle == 3)
			v->color = 0xffcc66;
		else if(v->angle == 4)
			v->color = 0xffcc00;
	}
}

/*
** Moar colors
*/

void	get_color(t_val *v)
{
			//ft_putendlcolor("get_color()", MAGENTA);
	if(v->z[v->mapX][v->mapY] == 1)
	{
		if(v->angle == 1)
			v->color = 0xccff99;
		else if(v->angle == 2)
			v->color = 0xccff66;
		else if(v->angle == 3)
			v->color = 0x99ff33;
		else if(v->angle == 4)
			v->color = 0x99ff66;
	}
	else if(v->z[v->mapX][v->mapY] == 2)
	{
		if(v->angle == 1)
			v->color = 0xff99ff;
		else if(v->angle == 2)
			v->color = 0xff66ff;
		else if(v->angle == 3)
			v->color = 0xff66cc;
		else if(v->angle == 4)
			v->color = 0xff99cc;
	}
	else
		get_color2(v);
}
