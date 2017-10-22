/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 20:31:32 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/22 16:33:26 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** Init the base struct
*/

void	init_base(t_val *v)
{
			// ft_putendlcolor("init_base()", MAGENTA);
	v->color = 0;
	v->posX = 2;
	v->posY = 2;
	v->dirX = -1;
	v->dirY = 0;
	v->planeX = 0;
	v->planeY = 0.66;
	v->bpp = 0;
	v->endian = 0;
	v->sizeline = 0;
	v->rot = 0.12; 
	v->speed = 0.1;
	v->longueurMur = 0;
	v->murVertiOuHori = 0; 
	v->etapeX = 0; 
	v->etapeY = 0; 
	v->distMurX = 0; 
	v->distMurY = 0; 
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, WINX, WINY, "Wolf3D");
	v->img = mlx_new_image(v->mlx, WINX, WINY);
	v->data = (int*)mlx_get_data_addr(v->img, &v->bpp, &v->sizeline, &v->endian);
}

/*
** Init the values for the loop
*/

void	init_v(t_val *v)
{
        // ft_putendlcolor("init_v()", MAGENTA);
	v->cameraX = 2 * v->x / (double)WINX - 1;
	v->rayPosX = v->posX;
	v->rayPosY = v->posY;
	v->rayDirX = v->dirX + v->planeX * v->cameraX;
	v->rayDirY = v->dirY + v->planeY * v->cameraX;
	v->mapX = (int)v->rayPosX;
	v->mapY = (int)v->rayPosY;
	v->dist2MurX = sqrt(1 + (v->rayDirY * v->rayDirY) / (v->rayDirX * v->rayDirX));
	v->dist2MurY = sqrt(1 + (v->rayDirX * v->rayDirX) / (v->rayDirY * v->rayDirY));
	v->touche = 0; 
}
