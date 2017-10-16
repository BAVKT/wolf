/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:20:16 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/16 19:05:32 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** Event for moving up and down
*/

void		ev_updown(int k, t_base *b)
{
			ft_putendlcolor("ev_updown()", MAGENTA);
	//bouchetrou
	if (k == 126)
		b->r.x = b->r.x;

	// if (k == 126)
	// {
	// 	if (!b->z[b->r.mapy * b->winx + (b->r.mapx + b->r.dirx * b->r.mv)])
	// 		b->r.x += b->r.dirx * b->r.mv;
	// 	if (!b->z[(b->r.mapy + b->r.diry * b->r.mv) * b->winx + b->r.mapx])
	// 		b->r.y += b->r.diry * b->r.mv;
	// }
	// else if (k == 125)
	// {
	// 	if (!b->z[b->r.mapy * b->winx + (b->r.mapx - b->r.dirx * b->r.mv)])
	// 		b->r.x -= b->r.dirx * b->r.mv;
	// 	if (!b->z[(b->r.mapy - b->r.diry * b->r.mv) * b->winx + b->r.mapx])
	// 		b->r.y -= b->r.diry * b->r.mv;
	// }
	refresh(b);
}

/*
** Event for moving left and right
*/

void		ev_leftright(int k, t_base *b)
{
			ft_putendlcolor("ev_leftright()", MAGENTA);
	if (k == 124)
	{
		//both camera direction and camera plane must be rotated
		b->r.odirx = b->r.dirx;
		b->r.dirx = b->r.dirx * cos(-b->r.rot) - b->r.diry * sin(-b->r.rot);
		b->r.diry = b->r.odirx * sin(-b->r.rot) + b->r.diry * cos(-b->r.rot);
		b->r.oplanex = b->r.planex;
		b->r.planex = b->r.planex * cos(-b->r.rot) - b->r.planey * sin(-b->r.rot);
		b->r.planey = b->r.oplanex * sin(-b->r.rot) + b->r.planey * cos(-b->r.rot);
	}
	else if (k == 123)
	{
		//both camera direction and camera plane must be rotated
		b->r.odirx = b->r.dirx;
		b->r.dirx = b->r.dirx * cos(b->r.rot) - b->r.diry * sin(b->r.rot);
		b->r.diry = b->r.odirx * sin(b->r.rot) + b->r.diry * cos(b->r.rot);
		b->r.oplanex = b->r.planex;
		b->r.planex = b->r.planex * cos(b->r.rot) - b->r.planey * sin(b->r.rot);
		b->r.planey = b->r.oplanex * sin(b->r.rot) + b->r.planey * cos(b->r.rot);
	}
	refresh(b);
}

/*
** For other events 
*/

void		ev_else(int k, t_base *b)
{
			ft_putendlcolor("ev_else()", MAGENTA);
	if (k == 53)
		clean(b);
}

/*
** Redirect the events and show/hide menus
*/

int		event(int k, void *param)
{
			ft_putendlcolor("event()", MAGENTA);
			ft_putstr("k = ");
			ft_putnbrendl(k);
	t_base *b;

	b = (t_base *)param;
	if (k == 126 || k == 125)
		ev_updown(k, b);
	else if (k == 124 || k == 123)
		ev_leftright(k, b);
	else if (k == 53)
		ev_else(k, b);
	refresh(b);
	return (0);
}
