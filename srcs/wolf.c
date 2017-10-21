/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 16:41:34 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/21 18:49:26 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** Main loop
*/

void    loop(t_val *v)
{
      ft_putendlcolor("loop()", MAGENTA);
    refresh(v);
    mlx_hook(v->win, 2, 0, event, v);
    mlx_hook(v->win, 17, 0, clean, v);
    mlx_loop(v->mlx);
}

/*
** Clear the current image, draw the new one and display it
*/

void  refresh(t_val *v)
{
       ft_putendlcolor("refresh()", MAGENTA);
	int i;

	i = 0;
	while (i < WINX * WINY - 1)
		v->data[i++] = 0;
	raycasting(v);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
}

int		main(int ac, char **av)
{
	t_val v;

	if (ac != 2)
		error(1);
	if (!ft_strcmp(av[1], "usage"))
		error(0);
	v.av = ft_strdup(av[1]);
	check_file(av[1]);
	init_base(&v);
	parse(&v);
	loop(&v);
	return (0);
}

/*
#######################################################################

void    draw_px(SDL_Surface *dst, size_t clr, int x, int y)
{
    *((unsigned *)(dst->pixels + y * dst->pitch + x *
				   dst->format->BytesPerPixel)) = clr;
}

int main()
{
	SDL_Window *window;
	SDL_Surface *screen;
	SDL_Event event;
	int run = 1;
    int x;
    int y;
	int h;
	int w;

	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_RESIZABLE);
	while (run == 1)
	{
		if (SDL_PollEvent(&event))
		{
			if (event.window.event == SDL_WINDOWEVENT_CLOSE || (event.type ==
				SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
				run = 0;
		}
		screen = SDL_GetWindowSurface(window);
		SDL_GetWindowSize(window, &w, &h);
        y = -1;
		while (++y < h)
        {
            x = -1;
            while(++x < w)
				draw_px(screen, 0xFFFFFF, x, y);
        }
		SDL_UpdateWindowSurface(window);
		SDL_FreeSurface(screen);
	}
 	SDL_DestroyWindow(window);
	SDL_Quit();
	return (write(1,"yolo\n", 5));
}
*/
