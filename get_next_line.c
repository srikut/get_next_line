/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srikuto <srikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:34:41 by srikuto           #+#    #+#             */
/*   Updated: 2025/03/02 19:11:45 by srikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getline(char *save)
{
	char	*rtn;
	int		i;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	rtn = (char *)malloc(sizeof(char) * (i + 2));
	if (!rtn)
		return (NULL);
	i = 0;
	if (save[i] && save[i] != '\n')
	{
		rtn[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		rtn[i] = '\n';
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

char	*ft_save(char *save)
{
	char	*rtn;
	int		i;
	int		j;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	rtn = (char *)malloc(sizeof(char) * (ft_strlen(save) - i) + 1);
	if (!rtn)
		return (NULL);
	j = 0;
	while (save[i] != '\0')
	{
		rtn[j] = save[i];
		i++;
		j++;
	}
	rtn[j] = '\0';
	return (rtn);
}

char	*ft_read(int fd, char *save)
{
	char	*tmp;
	int		read_rtn;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	read_rtn = 1;
	while (!ft_strchr(save, '\n') && read_rtn != 0)
	{
		read_rtn = read(fd, tmp, BUFFER_SIZE);
		if (read_rtn == 0)
			break ;
		if (read_rtn == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[read_rtn] = '\0';
		save = ft_strjoin(save, tmp);
	}
	free (tmp);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = ft_read(fd, save);
	if (!save)
		return (NULL);
	line = ft_getline(save);
	save = ft_save(save);
	return (line);
}
