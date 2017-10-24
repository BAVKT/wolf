/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 18:41:10 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/24 20:43:55 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** Check if file is okay
*/

void	check_file(char *av)
{
	int		i;
	int		fd;
	char	*s;

			// ft_putendlcolor("check_file()", MAGENTA);
	if ((fd = open(av, O_RDONLY)) < 0)
		error(3);
	fd = open(av, O_RDONLY);
	s = NULL;
	while (get_next_line(fd, &s) > 0)
	{
		i = 0;
		while (s[i])
		{
			if ((!ft_isdigit(s[i]) && s[i] != ' '))
				error(4);
			i++;
		}
		free(s);
	}
	close(fd);
}

/*
** Parse the file
*/

void	parse(t_val *v)
{
	char	*str;
	int		fd;
	int		j;
	int		ok;

			// ft_putendlcolor("parse()", MAGENTA);
	str = NULL;
	fd = open(v->av, O_RDONLY);
	while ((ok = get_next_line(fd, &str)) > 0)
	{
		get_xy(v, str);
		free(str);
	}
	if (ok == -1)
		error(5);
	close(fd);
	if (!(v->z = (int **)malloc(sizeof(int *) * v->maxy)))
		error(8);
	j = 0;
	fd = open(v->av, O_RDONLY);
	while (get_next_line(fd, &str) > 0)
	{
		j = get_z(v, str, j);
		free(str);
	}
	(j <= 0) ? error(6) : close(fd);
}

/*
** Get the max x & max y values
*/

void	get_xy(t_val *v, char *line)
{
	int i;
	int j;

			// ft_putendlcolor("get_xy()", MAGENTA);
	i = 0;
	j = 0;
	while (line[i])
	{
		while (line[i] && !ft_isdigit(line[i]))
			i++;
		while (line[i] && line[i] != ' ')
			i++;
		if (ft_isdigit(line[i - 1]))
			j++;
	}
	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i++]))
		{
			v->maxy++;
			break ;
		}
	}
	v->maxx = (j > v->maxx) ? j : v->maxx;
}

/*
** Fill the z tab
*/

int		get_z(t_val *v, char *line, int j)
{
	int		i;
	int		k;
	int		l;
	char	**c;

			// ft_putendlcolor("get_z()", MAGENTA);
	i = 0;
	k = 0;
	l = 0;
	v->z[j] = (int *)malloc(sizeof(int) * v->maxx);
	c = ft_strsplit(line, ' ');
	while (c[i])
		v->z[j][l++] = ft_atoi(c[i++]);
	j++;
	free_tab((void **)c);
	if (v->maxx < 2 || v->maxy < 2 || v->maxx != v->maxy)
		error(6);
	return (j);
}

/*
** Check if the start position exist and is well placed
*/

void	check_start(t_val *v)
{
	int i;
	int j;
	int	nb;

	nb = 0;
	i = -1;
	j = 0;
	while (++i < v->maxy)
	{
		j = -1;
		while (++j < v->maxx)
		{
			if (v->z[i][j] == 9)
			{
				nb++;
				v->posX = i > 0 && i < v->maxy ? i + 0.5 : v->posX;
				v->posY = j > 0 && j < v->maxx ? j + 0.5 : v->posY;
			}
			if (v->z[i][j] < 0 || v->z[i][j] > 4)
				v->z[i][j] = 0;
		}
	}
	if (nb != 1)
		error(10);
}
