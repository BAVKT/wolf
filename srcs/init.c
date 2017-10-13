/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 20:31:32 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/13 20:28:53 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** Init the base struct
*/

void	init_base(t_base *b)
{
	parse(b);
	if (!(b->z = (int*)malloc(sizeof(int) * (b->maxx * b->maxy))));
		error(8);
	b->mx.mlx = mlx_init();
	b->mx.win = mlx_new_window(b->mx.mlx, WINX, WINY, "Wolf3D");
	b->mx.img = mlx_new_image(b->mx.mlx, b->winx, b->winy);
	b->mx.data = (int*)mlx_get_data_addr(
		b->mx.img, &b->mx.bpp, &b->mx.sizeline, &b->mx.endian);
	mlx_string_put(b->mx.mlx, b->mx.win, (b->winx / 2) - 100,
		(b->winy / 2) - 20, W, "PLEASE WAIT...");
	mlx_put_image_to_window(b->mx.mlx, b->mx.win, b->mx.img, 0, 0);
}

/*
** Init the values for the loop
*/

void	init_xy(t_base *b)
{
				//calculate ray position and direction
	b->ray.cameraX = 2 * x / double(w) - 1; //x-coordinate in camera space
	b->ray.rayPosX = posX;
	b->ray.rayPosY = posY;
	b->ray.rayDirX = dirX + planeX * cameraX;
	b->ray.rayDirY = dirY + planeY * cameraX;
				//which box of the map we're in
	b->ray.mapX = int(rayPosX);
	b->ray.mapY = int(rayPosY);
				//length of ray from one x or y-side to next x or y-side
	b->ray.deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
	b->ray.deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
	b->ray.hit = 0;  //was there a wall hit?
}

/*
** Init a part of the ray struct
*/

void	init_ray(t_ray *ray)
{
	b->ray.posX = 22;
	b->ray.posY = 12;    	//x and y start position
	b->ray.dirX = -1;
	b->ray.dirY = 0;     	//initial direction vector
	b->ray.planeX = 0;
	b->ray.planeY = 0.66;	//the 2d raycaster version of camera plane
	b->ray.time = 0;     	//time of current frame
	b->ray.oldTime = 0;  	//time of previous frame
}

/*
** Init bresenham struct
*/

void	init_bresen(t_bresen *br)
{
	br->x = 0;
	br->y = 0;
	br->dx = 0;
	br->dy = 0;
	br->xi = 0;
	br->yi = 0;
	br->xj = 0;
	br->yj = 0;
	br->color = 0xffffff;
}