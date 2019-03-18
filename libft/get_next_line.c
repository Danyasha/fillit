/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 03:36:50 by btorp             #+#    #+#             */
/*   Updated: 2019/02/17 19:10:26 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char		*gnlgetn(char **g)
{
	char	*temp;
	char	*temp2;
	size_t	i;
	char	*s;

	s = *g;
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\0')
	{
		free(*g);
		*g = NULL;
		return (NULL);
	}
	temp = ft_strnew(i);
	temp = ft_strncpy(temp, s, i);
	temp2 = ft_strnew(ft_strlen(&(s[i + 1])));
	temp2 = ft_strncpy(temp2, &s[i + 1], ft_strlen(&s[i]));
	free(*g);
	*g = temp2;
	return (temp);
}

int					get_next_line(const int fd, char **line)
{
	static	char	*anime;
	char			buff[BUFF_SIZE + 1];
	int				check;

	if ((read(fd, buff, 0) < 0) || line == NULL)
		return (-1);
	while (ft_findch(anime, '\n') == 0)
	{
		check = read(fd, buff, BUFF_SIZE);
		buff[check] = '\0';
		if (check <= 0)
			break ;
		anime = ft_strjoinfree(anime, buff);
	}
	if (ft_strlen(anime) || check > 0)
	{
		*line = gnlgetn(&anime);
		if (line == NULL)
			return (0);
		return (1);
	}
	if (anime)
		ft_memdel((void*)&anime);
	return (0);
}
