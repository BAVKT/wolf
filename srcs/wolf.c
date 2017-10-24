/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 16:41:34 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/24 20:33:39 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** Main loop
*/

void	loop(t_val *v)
{
	// ft_putendlcolor("loop()", MAGENTA);
	refresh(v);
	mlx_hook(v->win, 2, 0, event, v);
	mlx_hook(v->win, 17, 0, clean, v);
	mlx_loop(v->mlx);
}

/*
** Clear the current image, draw the new one and display it
*/

void	refresh(t_val *v)
{
	int i;
	// ft_putendlcolor("refresh()", MAGENTA);

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
	check_start(&v);
	loop(&v);
	return (0);
}
