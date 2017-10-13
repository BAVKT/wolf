/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 17:00:31 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/13 18:17:20 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.c"

/*
** Write the pixel in the image
*/

void	px_img(t_base *b, int x, int y, int color)
{
	if (x > b->winx || x < 0 || y > b->winy || y < 0)
		return ;
	b->mx.data[y * b->winx + x] = color;
}

/*
** Init the lines values and start the line() needed
*/

void	draw_line(t_b *b)
{
	int	xx;
	int	yy;

	b->x = b->xi;
	b->y = b->yi;
	b->dx = b->xj - b->xi;
	b->dy = b->yj - b->yi;
	xx = (b->dx > 0) ? 1 : -1;
	yy = (b->dy > 0) ? 1 : -1;
	b->dx = abs(b->dx);
	b->dy = abs(b->dy);
	px_img(b, b->x, b->y, b->color);
	// if (b->xi >= b->win_x || b->yi >= b->win_y ||
	// 	b->xj >= b->win_x || b->yj >= b->win_y ||
	// 	b->xi < 0 || b->yi < 0 || b->xj < 0 || b->yj < 0)
	// 	return ;
	if (b->dx > b->dy)
		line1(b, xx, yy);
	else
		line2(b, xx, yy);
}

/*
** Draw the line
*/

void	line1(t_b *b, int xx, int yy)
{
	int	i;
	int cumul;

	i = 1;
	cumul = b->dx / 2;
	while (i <= b->dx)
	{
		b->x += xx;
		cumul += b->dy;
		if (cumul >= b->dx)
		{
			cumul -= b->dx;
			b->y += yy;
		}
		px_img(b, b->x, b->y, b->color);
		i++;
	}
}

void	line2(t_b *b, int xx, int yy)
{
	int	i;
	int cumul;

	i = 1;
	cumul = b->dy / 2;
	while (i <= b->dy)
	{
		b->y += yy;
		cumul += b->dx;
		if (cumul >= b->dy)
		{
			cumul -= b->dy;
			b->x += xx;
		}
		px_img(b, b->x, b->y, b->color);
		i++;
	}
}
