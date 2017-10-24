/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:17:42 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/24 22:19:38 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** Get the step
*/

void	step(t_val *v)
{
	if (v->dirRayx < 0)
	{
		v->etapeX = -1;
		v->wdistx = (v->rayx - v->xi) * v->wdistxx;
	}
	else
	{
		v->etapeX = 1;
		v->wdistx = (v->xi + 1.0 - v->rayx) * v->wdistxx;
	}
	if (v->dirRayy < 0)
	{
		v->etapeY = -1;
		v->wdisty = (v->rayy - v->yi) * v->wdistyy;
	}
	else
	{
		v->etapeY = 1;
		v->wdisty = (v->yi + 1.0 - v->rayy) * v->wdistyy;
	}
}

/*
** Loop until it hit a wall
*/

void	hit(t_val *v)
{
	while (v->hit == 0)
	{
		if (v->wdistx < v->wdisty)
		{
			v->wdistx += v->wdistxx;
			v->xi += v->etapeX;
			v->wall = 0;
			v->angle = (v->etapeX == 1) ? 1 : 2;
		}
		else
		{
			v->wdisty += v->wdistyy;
			v->yi += v->etapeY;
			v->wall = 1;
			v->angle = (v->etapeY == 1) ? 3 : 4;
		}
		if (v->xi < 0 || v->yi < 0)
			error(9);
		if (v->z[v->xi][v->yi] > 0)
			v->hit = 1;
	}
}

/*
** Get wall size for drawing it
*/

void	wall(t_val *v)
{
	if (v->wall == 0)
		v->Wall_w = fabs((v->xi - v->rayx +
			(1 - v->etapeX) / 2) / v->dirRayx);
	else
		v->Wall_w = fabs((v->yi - v->rayy +
			(1 - v->etapeY) / 2) / v->dirRayy);
	v->Wall_h = fabs(WINY / v->Wall_w);
	v->start = -v->Wall_h / 2 + WINY / 2;
	if (v->start < 0)
		v->start = 0;
	v->end = v->Wall_h / 2 + WINY / 2;
	if (v->end >= WINY)
		v->end = WINY - 1;
}

/*
** Main drawing loop
*/

void	raycasting(t_val *v)
{
	v->x = -1;
	while (++v->x < WINX)
	{
		init_v(v);
		step(v);
		hit(v);
		wall(v);
		get_color(v);
		draw_verti(v);
	}
}

/*
** Draw into the image
*/

void	draw_verti(t_val *v)
{
	int j;

	j = v->start;
	while (j < v->end)
	{
		if (v->x > WINX || v->x < 0 || j > WINY || j < 0)
			;
		else
			v->data[(int)(j++ * WINX + v->x)] = v->color;
	}
	while (j < WINY)
	{
		if (v->x > WINX || v->x < 0 || j > WINY || j < 0)
			;
		else
			v->data[(int)(j++ * WINX + v->x)] = 0xefefef;
	}
	j = 0;
	while (j < v->start)
	{
		if (666 * rand() % 9999 == 0)
			v->data[(int)(j++ * WINX + v->x)] = 0xffffff;
		else
			v->data[(int)(j++ * WINX + v->x)] = 0x000cbb;
	}
}
