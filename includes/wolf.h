/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 18:41:36 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/13 20:22:42 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WOLF_H
# define __WOLF_H
# include "libft.h"
# include "mlx.h"
# include <pthread.h>
# include <limits.h>
# define mapWidth 24
# define mapHeight 24
# define R 0xff0000
# define G 0x0000ff
# define B 0x00ff00
# define W 0xffffff
# define Y 0xffff00
# define WINX 800
# define WINY 800
# define NBTH 8

typedef struct			s_ray
{
	double				cameraY;
	double				cameraX;
	double				rayPosX;
	double				rayPosY;
	double				rayDirX;
	double				rayDirY;
	double				posX;
	double				posY;
	double				dirX;
	double				dirX;
	double				time;
	double				oldTime;
	double				sideDistX; 	//length of ray from current position to next x or y-side
	double				sideDistY;
	double				deltaDistX;
	double				deltaDistY;
	double				perpWallDist;
	double				oldDirX;
	double				oldPlaneX;
	int					mapX;
	int					mapY;
	int					stepX;     	//what direction to step in x or 
	int					stepY;		//y-direction (either +1 or -1)
	int					hit;       	//was there a wall hit?
	int					side;      	//was a NS or a EW wall hit?
	int					lineHeight;
	int					drawStart;
	int					drawEnd;
}						t_ray;

typedef	struct			s_bresenham
{
	double				x;
	double				y;
	double				dx;
	double				dy;
	double				xi;
	double				yi;
	double				xj;
	double				yj;
	unsigned int		color;
}						t_bresen;

typedef struct			s_mlx
{
	void				*mlx;
	void				*win;
	void				*img;
	int					bpp;
	int					*data;
	int					endian;
	int					sizeline;
}						t_mlx;

typedef struct			s_base
{
	struct s_mlx		mx;
	struct s_ray		ray;
	char				*av;
	int					*z;
	int					winx;
	int					winy;
	int					maxx;
	int					maxy;
	int					win_size;
}						t_base;

/*
** Main & loop 					|	wolf.c
*/

void					loop(t_base *b);
void					refresh(t_base *b);

/*
** Init functions				|	init.c
*/

void					init_base(t_base *b);

/*
** Draw line functions			|	bresenham.c
*/

void					draw_line(t_base *b);
void					line1(t_base *b, int xx, int yy);
void					line2(t_base *b, int xx, int yy);

/*
** Raycasting functions			|	raycasting.c
*/

void					raycasting(t_base *b);
void					hit(t_base *b);
void					px_img(t_base *b, int x, int y);
void					step(t_base *b);

/*
** Parsing the map				|	parsing.c
*/
void					check_file(char *av);
void					parse(t_base *b);
void					get_xy(t_base *b, char *line);
int						get_z(t_base *b, char *line, int j);


/*
** Utilitaries					|	utils.c
*/

void					error(int e);
void					get_color(t_ray *ray);


#endif