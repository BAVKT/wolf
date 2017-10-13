/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 18:41:10 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/13 20:28:46 by vmercadi         ###   ########.fr       */
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

	if ((fd = open(av, O_RDONLY)) < 0)
		error(3);
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
** Init the t_d with all the x/y basic values
*/

void	parse(t_base *b)
{
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
	if (!(b->d.z = (int *)malloc(sizeof(int) * b->maxx * b->maxy)))
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
	(j != b->maxx && b->maxx > 0 && j != 0) ? i = 0 : error(6);
}

/*
** Fill the z tab
*/

int		get_z(t_base *b, char *line, int j)
{
	int		i;
	int		k;
	char	**c;

	i = 0;
	k = 0;
	c = ft_strsplit(line, ' ');
	while (c[i])
	{
		b->z[j] = ft_atoi(c[i++]);
		if (b->z[j] > ZMAX || b->z[j] < 0)
			error(7);
	}
	free_tab((void **)c);
	return (j);
}




