/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:20:16 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/24 20:29:51 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** Event for moving up and down
*/

void	updown(int k, t_val *v)
{
		ft_putendlcolor("updown()", MAGENTA);
	ft_putnbrendl(v->posX);
	ft_putnbrendl(v->posY);
	if (k == 126 || k == 13)
	{
		if(!v->z[(int)(v->posX + v->dirX * v->speed)][(int)(v->posY)])
			v->posX += v->dirX * v->speed;
		if(!v->z[(int)(v->posX)][(int)(v->posY + v->dirY * v->speed)])
			v->posY += v->dirY * v->speed;
	}
	else if (k == 125 || k == 1)
	{
		if(!v->z[(int)(v->posX - v->dirX * v->speed)][(int)(v->posY)])
			v->posX -= v->dirX * v->speed;
		if(!v->z[(int)(v->posX)][(int)(v->posY - v->dirY * v->speed)])
			v->posY -= v->dirY * v->speed;
	}
	refresh(v);
}

/*
** Event for moving left and right
*/

void	leftright(int k, t_val *v)
{
		ft_putendlcolor("leftright()", MAGENTA);
	if (k == 2)
	{
		if(!v->z[(int)(v->posX + v->planeX * v->speed)][(int)(v->posY)])
			v->posX += v->planeX * v->speed;
		if(!v->z[(int)(v->posX)][(int)(v->posY + v->planeY * v->speed)])
			v->posY += v->planeY * v->speed;
	}
	else if (k == 0)
	{
		if(!v->z[(int)(v->posX - v->planeX * v->speed)][(int)(v->posY)])
			v->posX -= v->planeX * v->speed;
		if(!v->z[(int)(v->posX)][(int)(v->posY - v->planeY * v->speed)])
			v->posY -= v->planeY * v->speed;
	}
	refresh(v);
}

/*
** Event for rotating
*/

void	rotate(int k, t_val *v)
{
		ft_putendlcolor("rotate()", MAGENTA);
	if (k == 124)
	{
		v->oldDirX = v->dirX;
		v->dirX = v->dirX * cos(-v->rot) - v->dirY * sin(-v->rot);
		v->dirY = v->oldDirX * sin(-v->rot) + v->dirY * cos(-v->rot);
		v->oldPlaneX = v->planeX;
		v->planeX = v->planeX * cos(-v->rot) - v->planeY * sin(-v->rot);
		v->planeY = v->oldPlaneX * sin(-v->rot) + v->planeY * cos(-v->rot);
	}
	else if (k == 123)
	{
		v->oldDirX = v->dirX;
		v->dirX = v->dirX * cos(v->rot) - v->dirY * sin(v->rot);
		v->dirY = v->oldDirX * sin(v->rot) + v->dirY * cos(v->rot);
		v->oldPlaneX = v->planeX;
		v->planeX = v->planeX * cos(v->rot) - v->planeY * sin(v->rot);
		v->planeY = v->oldPlaneX * sin(v->rot) + v->planeY * cos(v->rot);
	}
	refresh(v);
}

/*
** For other events 
*/

void	ev_else(int k, t_val *v)
{
			ft_putendlcolor("ev_else()", MAGENTA);
	if (k == 53)
		clean(v);
	else if (k == 257)
		v->speed = (v->speed == 0.25) ? 0.15 : 0.25;
}

/*
** Redirect the events and show/hide menus
*/

int   event(int k, void *param)
{
		ft_putendlcolor("event()", MAGENTA);
		ft_putstr("k = ");
		ft_putnbrendl(k);
	t_val *v;
	
	v = (t_val *)param;
	if (k == 126 || k == 125 || k == 13 || k == 1)
		updown(k, v);
	else if (k == 124 || k == 123)
		rotate(k, v);
	else if (k == 0 || k == 2)
		leftright(k, v);
	else if (k == 53 || k == 257)
		ev_else(k, v);
	return (0);
}

