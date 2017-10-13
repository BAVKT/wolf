/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:17:42 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/13 19:02:10 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** Write the pixel in the image
*/

void	px_img(t_base *b, int x, int y, int color)
{
	if (x > b->winx || x < 0 || y > b->winy || y < 0)
		return ;
	b->mx.data[y * b->winx + x] = color;
}

void	hit(t_base *b)
{
						//perform DDA Digital differential analyzer
	while (hit == 0)
	{
			//jump to next map square, OR in x-direction, OR in y-direction
	if (sideDistX < sideDistY)
		{
			sideDistX += deltaDistX;
			mapX += stepX;
			side = 0;
		}
		else
		{
			sideDistY += deltaDistY;
			mapY += stepY;
			side = 1;
		}
			//Check if ray has hit a wall
		if (worldMap[mapX][mapY] > 0)
			hit = 1;
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
				//calculate step and initial sideDist
			if (rayDirX < 0)
			{
				stepX = -1;
				sideDistX = (rayPosX - mapX) * deltaDistX;
			}
			else
			{
				stepX = 1;
				sideDistX = (mapX + 1.0 - rayPosX) * deltaDistX;
			}
			if (rayDirY < 0)
			{
				stepY = -1;
				sideDistY = (rayPosY - mapY) * deltaDistY;
			}
			else
			{
				stepY = 1;
				sideDistY = (mapY + 1.0 - rayPosY) * deltaDistY;
			}
			hit();
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
		ft_pu
		i++;
	}

}





