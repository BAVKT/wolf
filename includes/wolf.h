/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 18:41:36 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/21 18:48:13 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WOLF_H
# define __WOLF_H
# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <pthread.h>
# include <limits.h>
# define mapWidth 24
# define mapHeight 24
# define R 0xff0000
# define G 0x0000ff
# define B 0x00ff00
# define W 0xffffff
# define Y 0xffff00
# define WINX 512
# define WINY 384
# define NBTH 8

// typedef struct			s_ray
// {
// 	double				oplanex;
// 	double				dirayx;
// 	double				dirayy;
// 	double				planex;
// 	double				planey;
// 	double				deltax;
// 	double				deltay;
// 	double				pwdist;		//perp wall dist
// 	double				sidex;		//length of ray from current position to next x or y-side
// 	double				sidey;
// 	double				odirx;
// 	double				frame;
// 	double				camy;
// 	double				camx;
// 	double				rayx;
// 	double				rayy;
// 	double				dirx;
// 	double				diry;
// 	double				oti;
// 	double				rot;
// 	double				ti;
// 	double				mv;
// 	double				x;
// 	double				y;
// 	int					hit;
// 	int					end;
// 	int					mapx;
// 	int					mapy;
// 	int					side;		//was a NS or a EW wall hit?
// 	int					stepx;		//what direction to step in x or 
// 	int					stepy;		//y-direction (either +1 or -1)
// 	int					liney;
// 	int					start;
// 	unsigned int		color;
// }						t_ray;

// typedef	struct			s_bresenham
// {
// 	double				x;
// 	double				y;
// 	double				dx;
// 	double				dy;
// 	double				xi;
// 	double				yi;
// 	double				xj;
// 	double				yj;
// }						t_bresen;

// typedef struct			s_mlx
// {
// 	void				*mlx;
// 	void				*win;
// 	void				*img;
// 	int					bpp;
// 	int					*data;
// 	int					endian;
// 	int					sizeline;
// }						t_mlx;

// typedef struct			s_base
// {
// 	struct s_ray		r;
// 	struct s_mlx		mx;
// 	char				*av;
// 	int					*z;			//Tab values
// 	int					winx;
// 	int					winy;
// 	int					maxx;
// 	int					maxy;
// 	int					size;		//size of the z tab
// 	int					sizev;		//max size of the values
// 	int					win_size;
// }						t_base;

typedef struct			s_val
{
	int					murVertiOuHori;
	int					sizeline;
	int					win_size;
	int					endian;
	int					etapeX;
	int					etapeY;
	int					touche;
	int					sizev;		//max size of the values
	int					mapX;
	int					mapY;
	int					winx;
	int					winy;
	int					maxx;
	int					maxy;
	int					size;		//size of the z tab
	int					bpp;
	int					x;
	int					*z;			//Tab values
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
	// double time = 0; 
	// double oldTime = 0; 
}					    t_val;

#define mapWidth 24
#define mapHeight 24

// static int worldMap[mapWidth][mapHeight]=
// {
// {3,1,1,1,1,3},
// {3,0,0,0,0,2},
// {3,0,0,0,0,2},
// {3,0,0,0,0,2},
// {3,1,1,1,1,3}
// };

static int worldMap[mapWidth][mapHeight]=
{
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void    loop(t_val *v);
void  refresh(t_val *v);
void    updown(int k, t_val *v);
void    leftright(int k, t_val *v);
void   raycasting(t_val *v);
int   event(int k, void *param);
void    init_v(t_val *v);
void	init_base(t_val *v);
void	draw_verti(t_val *v);
void	step(t_val *v);
void	hit(t_val *v);
void	wall(t_val *v);
void	error(int e);
int		clean(t_val *v);
void	get_color(t_val *v);
void	check_file(char *av);
void	parse(t_val *v);
void	get_xy(t_val *v, char *line);
int		get_z(t_val *v, char *line, int j);

// /*
// ** Main & loop 					|	wolf.c
// */

// void					loop(t_base *b);
// void					refresh(t_base *b);

// /*
// ** Init functions				|	init.c
// */

// void					init_base(t_base *b);
// void					init_val(t_base *b);
// void					init_ray(t_ray *r);

// /*
// ** Draw line functions			|	bresenham.c
// */

// void					draw_line(t_base *b);
// void					line1(t_base *b, int xx, int yy);
// void					line2(t_base *b, int xx, int yy);

// /*
// ** Raycasting functions			|	raycasting.c
// */

// void					raycasting(t_base *b);
// void					px_img(t_base *b, int x, int y, unsigned int color);
// void					step(t_base *b);
// void					hit(t_base *b);
// void					fps(t_base *b);
// void					draw_verti(t_base *b, int x);


// /*
// ** Parsing the map				|	parsing.c
// */

// void					check_file(char *av);
// void					parse(t_base *b);
// void					get_xy(t_base *b, char *line);
// int						get_z(t_base *b, char *line, int j);

// /*
// ** All the events				|	event.c
// */

// int						event(int k, void *param);
// void					ev_updown(int k, t_base *b);
// void					ev_leftright(int k, t_base *b);
// void					ev_else(int k, t_base *b);


// /*
// ** Utilitaries					|	utils.c
// */

// void					error(int e);
// int						get_color(int z);
// int						clean(t_base *b);

#endif