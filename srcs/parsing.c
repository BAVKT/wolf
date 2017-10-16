/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 18:41:10 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/16 19:56:05 by vmercadi         ###   ########.fr       */
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

void	parse(t_base *b)
{
			ft_putendlcolor("parse()", MAGENTA);
	char	*str;
	int		fd;
	int		j;
	int		ok;

	str = NULL;
	fd = open(b->av, O_RDONLY);
	while ((ok = get_next_line(fd, &str)) > 0)
	{
		get_xy(b, str);
		free(str);
	}
	if (ok == -1)
		error(5);
	close(fd);
	if (!(b->z = (int *)malloc(sizeof(int) * b->maxx * b->maxy)))
		error(6);
	j = 0;
	fd = open(b->av, O_RDONLY);
	while (get_next_line(fd, &str) > 0)
	{
		j = get_z(b, str, j);
		free(str);
	}
	close(fd);
}

/*
** Get the max x & max y values
*/

void	get_xy(t_base *b, char *line)
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
			b->maxy++;
			break ;
		}
	}
	b->maxx = (j > b->maxx) ? j : b->maxx;
	// (j != b->maxx && b->maxx > 0 && j != 0) ? i = 0 : error(6);
}

/*
** Fill the z tab
*/

int		get_z(t_base *b, char *line, int j)
{
			// ft_putendlcolor("get_z()", MAGENTA);
	int		i;
	int		k;
	char	**c;

	i = 0;
	k = 0;
	c = ft_strsplit(line, ' ');
	while (c[i])
	{
		b->z[j] = ft_atoi(c[i++]);
		b->z[j] = (b->z[j] > b->sizev) ? 0 : b->z[j];
		j++;
	}
	free_tab((void **)c);
	b->size = j;
	return (j);
}




