/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 18:41:36 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/23 16:21:13 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WOLF_H
# define __WOLF_H
# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <pthread.h>
# include <limits.h>
# define R 0xff0000
# define G 0x0000ff
# define B 0x00ff00
# define W 0xffffff
# define Y 0xffff00
# define WINX 800
# define WINY 800
# define NBTH 8

typedef struct			s_val
{
	int					murVertiOuHori;
	int					sizeline;
	int					win_size;
	int					endian;
	int					etapeX;
	int					etapeY;
	int					touche;
	int					sizev;
	int					mapX;
	int					mapY;
	int					winx;
	int					winy;
	int					maxx;
	int					maxy;
	int					size;
	int					bpp;
	int					x;
	int					**z;
	int					*data;
	char				*av;
	void				*mlx;
	void				*win;
	void				*img;
	double				rot;
	double				posX;
	double				posY;
	double				dirX;
	double				dirY;
	double 				angle;
	double				speed;
	double				planeX;
	double				planeY;
	double				oldDirX;
	double				cameraX;
	double				rayPosX;
	double				rayPosY;
	double				rayDirX;
	double				rayDirY;
	double				drawEnd;
	double				distMurX;
	double				distMurY;
	double				oldPlaneX;
	double				dist2MurX;
	double				dist2MurY;
	double				drawStart;
	double				hauteurMur;
	double				longueurMur;
	unsigned int		color;
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
}					    t_val;

/*
** Main & loop 					|	wolf.c
*/

void	loop(t_val *v);
void	refresh(t_val *v);

/*
** Init functions				|	init.c
*/

void	init_v(t_val *v);
void	init_base(t_val *v);

/*
** Raycasting functions			|	raycasting.c
*/

void	raycasting(t_val *v);
void	draw_verti(t_val *v);
void	step(t_val *v);
void	hit(t_val *v);
void	wall(t_val *v);

/*
** Parsing the map				|	parsing.c
*/

void	check_file(char *av);
void	parse(t_val *v);
void	get_xy(t_val *v, char *line);
int		get_z(t_val *v, char *line, int j);

/*
** All the events				|	event.c
*/

int		event(int k, void *param);
void	updown(int k, t_val *v);
void	leftright(int k, t_val *v);
void	ev_else(int k, t_val *v);
void	rotate(int k, t_val *v);

/*
** Utilitaries					|	utils.c
*/

void	error(int e);
int		clean(t_val *v);
void	get_color(t_val *v);

#endif