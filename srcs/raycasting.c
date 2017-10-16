/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:17:42 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/16 20:34:11 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** Write the pixel in the image
*/

void	px_img(t_base *b, int x, int y)
{
			// ft_putendlcolor("px_img()", MAGENTA);
	if (x > WINX || x < 0 || y > WINY || y < 0)
		return ;
	b->mx.data[y * b->winx + x] = b->r.color;
}

/*
** FPS counter (BONUS BECAUSE NEED TIME FUNCTION)
*/

void	fps(t_base *b)
{
			// ft_putendlcolor("fps()", MAGENTA);
	b->r.ti = 0;
	b->r.oti = b->r.ti;
	b->r.ti = time(NULL);
	b->r.frame = (b->r.ti - b->r.oti) / 1000.0; //frame is the ti this frame has taken, in seconds
	//speed modifiers
	b->r.mv = b->r.frame * 5.0; //the constant value is in squares/second
	b->r.rot = b->r.frame * 3.0; //the constant value is in radians/second
	//  manque la ligne pour afficher le compteur
}

/*
** Check while we dont hit a wall
*/

void	hit(t_base *b)
{
			//ft_putendlcolor("hit()", MAGENTA);
	while (b->r.hit == 0) //perform DDA Digital differential analyzer
	{
			//jump to next map square, OR in x-direction, OR in y-direction
		if (b->r.sidex < b->r.sidey)
		{
			b->r.sidex += b->r.deltax;
			b->r.mapx += b->r.stepx;
			b->r.side = 0;
		}
		else
		{
			b->r.sidey += b->r.deltay;
			b->r.mapy += b->r.stepy;
			b->r.side = 1;
		}
		if (b->z[b->r.mapy * b->r.mapx + b->r.mapx] > 0) //Check if ray has hit a wall
			b->r.hit = 1;
	}
}

/*
** Get the step and side distance
*/

void	step(t_base *b)
{
			//ft_putendlcolor("step()", MAGENTA);
	if (b->r.dirayx < 0)
	{
		b->r.stepx = -1;
		b->r.sidex = (b->r.rayx - b->r.mapx) * b->r.deltax;
	}
	else
	{
		b->r.stepx = 1;
		b->r.sidex = (b->r.mapx + 1.0 - b->r.rayx) * b->r.deltax;
	}
	if (b->r.dirayy < 0)
	{
		b->r.stepy = -1;
		b->r.sidey = (b->r.rayy - b->r.mapy) * b->r.deltay;
	}
	else
	{
		b->r.stepy = 1;
		b->r.sidey = (b->r.mapy + 1.0 - b->r.rayy) * b->r.deltay;
	}
}

/*
** Raycasting : draw colored lines
*/

void	raycasting(t_base *b)
{
			 ft_putendlcolor("raycasting()", MAGENTA);
	b->r.x = -1;
	while(++b->r.x < WINX)
	{
		init_val(b);
		step(b);
		hit(b);
		//Calculate distance projected on camera direction (oblique distance will give fisheye effect!)
		if (b->r.side == 0)
			b->r.pwdist = (b->r.mapx - b->r.rayx + (1 - b->r.stepx) / 2) / b->r.dirayx;
		else
			b->r.pwdist = (b->r.mapy - b->r.rayy + (1 - b->r.stepy) / 2) / b->r.dirayy;
		b->r.liney = (int)(WINY / b->r.pwdist);//Calculate height of line to draw on screen
		b->r.color = get_color(b->z[b->r.mapy * b->r.mapx + b->r.mapx]);
		b->r.color = (b->r.side == 1) ? b->r.color / 2 : b->r.color;//give x and y sides different brightness
		draw_verti(b, b->r.x);//draw the pixels of the stripe as a vertical line
	}
	fps(b);
}

/*
** Draw a vertical line between start and end
*/

void	draw_verti(t_base *b, int x)
{
			// ft_putendlcolor("draw_verti()", MAGENTA);
	b->r.start = -b->r.liney / 2 + WINY / 2;//calculate lowest and highest pixel to fill in current stripe
	if(b->r.start < 0)
		b->r.start = 0;
	b->r.end = b->r.liney / 2 + WINY / 2;
	if(b->r.end >= WINY)
		b->r.end = WINY - 1;
	while (b->r.start < b->r.end)
		px_img(b, x, b->r.start++);
}





