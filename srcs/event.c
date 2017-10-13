/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:20:16 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/13 20:28:58 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** Event for moving up and down
*/

void		ev_updown(int k, t_base *b)
{
	if (k == 126)
	{
 		if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false)
		posX += dirX * moveSpeed;
 		if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false)
		posY += dirY * moveSpeed;
	}
	else if (k == 125)
	{
		if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false)
		posX -= dirX * moveSpeed;
		if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false)
		posY -= dirY * moveSpeed;
	}
	refresh(base);
}

/*
** Event for moving left and right
*/
void		ev_leftright(int k, t_base *b)
{
	if (k == 124)
	{
		//both camera direction and camera plane must be rotated
		oldDirX = dirX;
		dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
		dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
		oldPlaneX = planeX;
		planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
		planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
	}
	else if (k == 123)
	{
		//both camera direction and camera plane must be rotated
		oldDirX = dirX;
		dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
		dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
		oldPlaneX = planeX;
		planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
		planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
	}
	refresh(base);
}

/*
** Redirect the events and show/hide menus
*/

int		event(int k, void *param)
{
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


//###########################################################
// /*
// ** Catch the mouse movments
// */

// int		evmv_mouse(int x, int y, t_base *base)
// {
// 	base->frfr.posx = x;
// 	base->frfr.posy = y;
// 	refresh(base);
// 	return (0);
// }

// /*
// ** Mouse events
// */

// int		ev_mouse(int k, int x, int y, void *param)
// {
// 	t_base *b;

// 	b = (t_base *)param;
// 	if (k == 1)
// 	{

// 	}
// 	else if (k == 4)
// 	{

// 	}
// 	else if (k == 5)
// 	{

// 	}
// 	refresh(b);
// 	return (0);
// }

// /*
// ** Move events
// */

// void	ev_move(int k, t_base *b)
// {
// 	else if (k == 126)
// 		base->frfr.my -= 0.33 / base->frfr.zoom;
// 	else if (k == 125)
// 		base->frfr.my += 0.33 / base->frfr.zoom;
// 	else if (k == 124)
// 		base->frfr.mx += 0.33 / base->frfr.zoom;
// 	else if (k == 123)
// 		base->frfr.mx -= 0.33 / base->frfr.zoom;
// 	refresh(base);
// }

// /*
// ** Other events : Quit, choose fractal, change color, reinit
// */

// void	ev_else(int k, t_base *b)
// {
// 	if (k == 53)
// 		clean(b);
// 	refresh(b);
// }
