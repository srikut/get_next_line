/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srikuto <srikuto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:34:41 by srikuto           #+#    #+#             */
/*   Updated: 2025/05/02 14:55:06 by srikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getline(char *save)
{
	char	*line;
	int		i;

	i = 0;
	if (!save || !save[0])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_save(char *save)
{
	int		i;
	int		j;
	char	*new_save;

	i = 0;
	j = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	i++;
	new_save = (char *)malloc(sizeof(char) * (ft_strlen(save + i) + 1));
	if (!new_save)
		return (NULL);
	while (save[i])
		new_save[j++] = save[i++];
	new_save[j] = '\0';
	free(save);
	return (new_save);
}

static char	*init_save(void)
{
	char	*save;

	save = (char *)malloc(1);
	if (!save)
		return (NULL);
	save[0] = '\0';
	return (save);
}

char	*ft_read(int fd, char *save)
{
	char	*tmp;
	int		read_rtn;

	tmp = (char *)malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	if (!save)
		save = init_save();
	read_rtn = 1;
	while (!ft_strchr(save, '\n') && read_rtn != 0)
	{
		read_rtn = read(fd, tmp, BUFFER_SIZE);
		if (read_rtn == -1)
		{
			free(tmp);
			free(save);
			return (NULL);
		}
		tmp[read_rtn] = '\0';
		save = ft_strjoin(save, tmp);
	}
	free(tmp);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_read(fd, save);
	if (!save)
		return (NULL);
	if (!save[0])
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	line = ft_getline(save);
	save = ft_save(save);
	return (line);
}
