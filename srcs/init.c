/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 20:31:32 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/16 20:23:49 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** Init the base struct
*/

void	init_base(t_base *b)
{
			ft_putendlcolor("init_base()", MAGENTA);
	b->maxx = 0;
	b->maxy = 0;
	if (!(b->z = (int*)malloc(sizeof(int) * (b->maxx * b->maxy))))
		error(8);
	init_ray(&b->r);
	b->size = b->maxx * b->maxy;
	b->sizev = 5;
	b->winx = WINX;
	b->winy = WINY;
	b->win_size = b->winx * b->winy;
	b->mx.mlx = mlx_init();
	b->mx.win = mlx_new_window(b->mx.mlx, WINX, WINY, "Wolf3D");
	b->mx.img = mlx_new_image(b->mx.mlx, b->winx, b->winy);
	b->mx.data = (int*)mlx_get_data_addr(
		b->mx.img, &b->mx.bpp, &b->mx.sizeline, &b->mx.endian);
	mlx_string_put(b->mx.mlx, b->mx.win, (b->winx / 2) - 75,
		(b->winy / 2) - 20, W, "PLEASE WAIT...");
	mlx_put_image_to_window(b->mx.mlx, b->mx.win, b->mx.img, 0, 0);
}

/*
** Init the values for the loop
*/

void	init_val(t_base *b)
{
			// ft_putendlcolor("init_xy()", MAGENTA);
				//calculate ray position and direction
	b->r.camx = 2 * b->r.x / WINX - 1;
	b->r.rayx = b->r.x;
	b->r.rayy = b->r.y;
	b->r.dirayx = b->r.dirx + b->r.planex * b->r.camx;
	b->r.dirayy = b->r.diry + b->r.planey * b->r.camx;
	b->r.mapx = (int)b->r.rayx;
	b->r.mapy = (int)b->r.rayy;
	b->r.deltax = ft_sqrt(1 + (b->r.dirayy * b->r.dirayy) / (b->r.dirayx * b->r.dirayx));
	b->r.deltay = ft_sqrt(1 + (b->r.dirayx * b->r.dirayx) / (b->r.dirayy * b->r.dirayy));
	b->r.hit = 0;
}

/*
** Init a part of the ray struct
*/

void	init_ray(t_ray *r)
{
			ft_putendlcolor("init_ray()", MAGENTA);
	r->oplanex = 0;
	r->pwdist = 0;
	r->odirx = 0;
	r->frame = 0;
	r->rot = 0;	
	r->mv = 0;
	r->x = 0;
	r->y = 0;		//x and y start position
	r->dirx = -1;
	r->diry = 0;		//initial direction vector
	r->planex = 0;
	r->planey = 0.66;	//the 2d raycaster version of camera plane
	r->ti = 0;		//ti of current frame
	r->oti = 0;		//ti of previous frame
	r->stepx = 0;
	r->stepy = 0;
	r->side = 0;
	r->liney = 0;
	r->start = 0;
	r->end = 0;
}

// /*
// ** Init bresenham struct
// */

// void	init_bresen(t_bresen *br)
// {
// 	br->x = 0;
// 	br->y = 0;
// 	br->dx = 0;
// 	br->dy = 0;
// 	br->xi = 0;
// 	br->yi = 0;
// 	br->xj = 0;
// 	br->yj = 0;
// 	br->color = 0xffffff;
// }