/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:17:42 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/13 20:28:48 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** Write the pixel in the image
*/

void	px_img(t_base *b, int x, int y)
{
	if (x > b->winx || x < 0 || y > b->winy || y < 0)
		return ;
	b->mx.data[y * b->winx + x] = color;
}

/*
** Check while we dont hit a wall
*/

void	hit(t_base *b)
{
						//perform DDA Digital differential analyzer
	while (b->ray.hit == 0)
	{
			//jump to next map square, OR in x-direction, OR in y-direction
		if (b->ray.sideDistX < b->ray.sideDistY)
		{
			b->ray.sideDistX += b->ray.deltaDistX;
			b->ray.mapX += b->ray.stepX;
			b->ray.side = 0;
		}
		else
		{
			b->ray.sideDistY += b->ray.deltaDistY;
			b->ray.mapY += b->ray.stepY;
			b->ray.side = 1;
		}
			//Check if ray has hit a wall
		if (worldMap[mapX][mapY] > 0)
			b->ray.hit = 1;
	}
}

/*
** Get the step and side distance
*/

void	step(t_base *b)
{
	if (b->ray.rayDirX < 0)
	{
		b->ray.stepX = -1;
		b->ray.sideDistX = (b->ray.rayPosX - b->ray.mapX) * b->ray.deltaDistX;
	}
	else
	{
		b->ray.stepX = 1;
		b->ray.sideDistX = (b->ray.mapX + 1.0 - b->ray.rayPosX) * b->ray.deltaDistX;
	}
	if (b->ray.rayDirY < 0)
	{
		b->ray.stepY = -1;
		b->ray.sideDistY = (b->ray.rayPosY - b->ray.mapY) * b->ray.deltaDistY;
	}
	else
	{
		b->ray.stepY = 1;
		b->ray.sideDistY = (b->ray.mapY + 1.0 - b->ray.rayPosY) * b->ray.deltaDistY;
	}
}

/*
** Raycasting : draw colored lines
*/

void	raycasting(t_base *b)
{
	int x;

	while(!done())
	{
		x = -1;
		while(++x < w)
		{
					//perform DDA Digital differential analyzer
			step(b);
			hit(b);
					//Calculate distance projected on camera direction (oblique distance will give fisheye effect!)
			if (side == 0)
				perpWallDist = (mapX - rayPosX + (1 - stepX) / 2) / rayDirX;
			else
				perpWallDist = (mapY - rayPosY + (1 - stepY) / 2) / rayDirY;
				//Calculate height of line to draw on screen
			ineHeight = (int)(h / perpWallDist);
				//calculate lowest and highest pixel to fill in current stripe
			drawStart = -lineHeight / 2 + h / 2;
			if(drawStart < 0)
				drawStart = 0;
			drawEnd = lineHeight / 2 + h / 2;
			if(drawEnd >= h)
				drawEnd = h - 1;
			get_color(map[x][y]);
				//give x and y sides different brightness
			if (side == 1)
				color = color / 2;
				//draw the pixels of the stripe as a vertical line
			draw_verti(b, x, drawStart, drawEnd);
		}
	}
}

void	draw_verti(t_base *b, int x, int drawStart, int drawEnd)
{
	int i;

	i = drawStart;
	while (i < drawEnd)
	{
		px_img(t_base *b, int x, int y);
		i++;
	}
}





