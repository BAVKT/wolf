/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 18:41:10 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/23 15:34:07 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** Check if file is okay
*/

void	check_file(char *av)
{
			ft_putendlcolor("check_file()", MAGENTA);
	int		i;
	int		fd;
	char	*s;

	if ((fd = open(av, O_RDONLY)) < 0)
	 	error(3);
	fd = open(av, O_RDONLY);
	s = NULL;
	while (get_next_line(fd, &s) > 0)
	{
		i = 0;
		while (s[i])
		{
			if ((!ft_isdigit(s[i]) && s[i] != ' ' && s[i] != 9))
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
			ft_putendlcolor("parse()", MAGENTA);
	char	*str;
	int		fd;
	int		j;
	int		ok;

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
	close(fd);
}

/*
** Get the max x & max y values
*/

void	get_xy(t_val *v, char *line)
{
			// ft_putendlcolor("get_xy()", MAGENTA);
	int i;
	int j;

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
			// ft_putendlcolor("get_z()", MAGENTA);
	int		i;
	int		k;
	int		l;
	char	**c;

	i = 0;
	k = 0;
	l = 0;
	v->z[j] = (int *)malloc(sizeof(int) * v->maxx);
	c = ft_strsplit(line, ' ');
	while (c[i])
	{
		v->z[j][l++] = ft_atoi(c[i++]);
			ft_putnbr(v->z[j][l - 1]);
			ft_putchar(' ');
	}
			ft_putchar('\n');
	j++;
	free_tab((void **)c);
	return (j);
}
