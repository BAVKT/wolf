/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:17:42 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/21 18:49:41 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** Get the step
*/

void	step(t_val *v)
{
		if (v->rayDirX < 0)
		{
			v->etapeX = -1;
			v->distMurX = (v->rayPosX - v->mapX) * v->dist2MurX;
		}
		else
		{
			v->etapeX = 1;
			v->distMurX = (v->mapX + 1.0 - v->rayPosX) * v->dist2MurX;
		}
		if (v->rayDirY < 0)
		{
			v->etapeY = -1;
			v->distMurY = (v->rayPosY - v->mapY) * v->dist2MurY;
		}
		else
		{
			v->etapeY = 1;
			v->distMurY = (v->mapY + 1.0 - v->rayPosY) * v->dist2MurY;
		}
}

/*
** Loop until it hit a wall
*/

void	hit(t_val *v)
{
	while (v->touche == 0)
	{
		if (v->distMurX < v->distMurY)
		{
			v->distMurX += v->dist2MurX;
			v->mapX += v->etapeX;
			v->murVertiOuHori = 0;
		}
		else
		{
			v->distMurY += v->dist2MurY;
			v->mapY += v->etapeY;
			v->murVertiOuHori = 1; 
		}
		if (worldMap[v->mapX][v->mapY] > 0)
			v->touche = 1;
	}
}

/*
** Get wall size for drawing it
*/

void	wall(t_val *v)
{
	if (v->murVertiOuHori == 0)
		v->longueurMur = fabs((v->mapX - v->rayPosX + (1 - v->etapeX) / 2) / v->rayDirX);
	else
		v->longueurMur = fabs((v->mapY - v->rayPosY + (1 - v->etapeY) / 2) / v->rayDirY);
	v->hauteurMur = fabs(WINY / v->longueurMur);
	v->drawStart = -v->hauteurMur / 2 + WINY / 2;
	if (v->drawStart < 0)
		v->drawStart = 0;
	v->drawEnd = v->hauteurMur / 2 + WINY / 2;
	if (v->drawEnd >= WINY)
		v->drawEnd = WINY - 1;
}

/*
** Main drawing loop
*/

void	raycasting(t_val *v)
{
      ft_putendlcolor("raycasting()", MAGENTA);

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

	j = v->drawStart;
	while (j < v->drawEnd)
	{
		if (v->x > WINX || v->x < 0 || j > WINY || j < 0)
			;
		else
			v->data[(int)(j++ * WINX + v->x)] = v->color;
	}
}
