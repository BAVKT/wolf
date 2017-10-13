/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 16:41:50 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/13 20:28:48 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** All the error messages
*/

void	error(int e)
{
	if (e == 0 || e == 1)
	{
		ft_putendl_fd("Usage : ./wolf map/map1", 2);
		exit(1);
	}
	else if (e == 4)
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
** Return the color dependind on the int of the block
*/

void    get_color(t_ray *ray)
{
      if (worldMap[mapX][mapY] == 1)
          ray->color = R;
      else if (worldMap[mapX][mapY] == 2)
          ray->color = G;
      else if (worldMap[mapX][mapY] == 3)
          ray->color = B;
      else if (worldMap[mapX][mapY] == 4)
          ray->color = W;
      else if (worldMap[mapX][mapY] == 5)
          ray->color = Y;
}
