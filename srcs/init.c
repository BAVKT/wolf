/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 20:31:32 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/24 21:51:29 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** Init the base struct
*/

void	init_base(t_val *v)
{
	v->color = 0;
	v->posx = 2;
	v->posy = 2;
	v->dirx = -1;
	v->diry = 0;
	v->planex = 0;
	v->planey = 0.66;
	v->bpp = 0;
	v->endian = 0;
	v->sizeline = 0;
	v->rot = 0.12;
	v->speed = 0.1;
	v->Wall_w = 0;
	v->wall = 0;
	v->etapeX = 0;
	v->etapeY = 0;
	v->wdistx = 0;
	v->wdisty = 0;
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, WINX, WINY, "Wolf3D");
	v->img = mlx_new_image(v->mlx, WINX, WINY);
	v->data = (int*)mlx_get_data_addr(
		v->img, &v->bpp, &v->sizeline, &v->endian);
}

/*
** Init the values for the loop
*/

void	init_v(t_val *v)
{
	v->camx = 2 * v->x / (double)WINX - 1;
	v->rayx = v->posx;
	v->rayy = v->posy;
	v->dirRayx = v->dirx + v->planex * v->camx;
	v->dirRayy = v->diry + v->planey * v->camx;
	v->xi = (int)v->rayx;
	v->yi = (int)v->rayy;
	v->wdistxx = sqrt(1 + (v->dirRayy * v->dirRayy) /
		(v->dirRayx * v->dirRayx));
	v->wdistyy = sqrt(1 + (v->dirRayx * v->dirRayx) /
		(v->dirRayy * v->dirRayy));
	v->hit = 0;
}
