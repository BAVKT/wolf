/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:20:16 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/21 18:49:43 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** Event for moving up and down
*/

void	updown(int k, t_val *v)
{
		ft_putendlcolor("updown()", MAGENTA);
	if (k == 126)
	{
		if(!worldMap[(int)(v->posX + v->dirX * v->speed)][(int)(v->posY)])
			v->posX += v->dirX * v->speed;
		if(!worldMap[(int)(v->posX)][(int)(v->posY + v->dirY * v->speed)])
			v->posY += v->dirY * v->speed;
	}
	else if (k == 125)
	{
		if(!worldMap[(int)(v->posX - v->dirX * v->speed)][(int)(v->posY)])
			v->posX -= v->dirX * v->speed;
		if(!worldMap[(int)(v->posX)][(int)(v->posY - v->dirY * v->speed)])
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

// /*
// ** For other events 
// */

// void	ev_else(int k, t_base *b)
// {
// 			ft_putendlcolor("ev_else()", MAGENTA);
// 	if (k == 53)
// 		clean(b);
// }

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
	if (k == 126 || k == 125)
		updown(k, v);
	else if (k == 124 || k == 123)
		leftright(k, v);
	else if (k == 53)
		clean(v);
	return (0);
}

