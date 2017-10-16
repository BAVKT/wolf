/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 16:41:34 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/16 20:27:27 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** Main loop
*/

void	loop(t_base *b)
{
	refresh(b);
	mlx_hook(b->mx.win, 2, 0, event, b);
	// mlx_hook(b->mx.win, 6, 0, evmv_mouse, b);
	mlx_hook(b->mx.win, 17, 0, clean, b);
	// mlx_mouse_hook(b->mx.win, ev_mouse, b);
	mlx_loop(b->mx.mlx);
}

/*
** Clear the current image, draw the new one and display it
*/

void	refresh(t_base *b)
{
	ft_bzero(b->mx.data, b->win_size);
	raycasting(b);
	mlx_put_image_to_window(b->mx.mlx, b->mx.win, b->mx.img, 0, 0);
}

int		main(int ac, char **av)
{
	t_base b;

	if (ac != 2)
		error(1);
	if (!ft_strcmp(av[1], "usage"))
		error(0);
	b.av = ft_strdup(av[1]);
	check_file(av[1]);
	init_base(&b);
	parse(&b);
	loop(&b);
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
