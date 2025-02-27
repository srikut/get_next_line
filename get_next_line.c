/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srikuto@student.42.fr <srikuto@>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:31:38 by srikuto@stu       #+#    #+#             */
/*   Updated: 2025/02/26 19:23:24 by srikuto@stu      ###   ########.fr       */
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
		return(NULL);
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
	
	while(save[i] && save[i] != '\n')
		i++;
	rtn = (char *)malloc(sizeof(char) * (ft_strlen(save) - i) + 1);
	if (!rtn)
		return (NULL);
	while(save != '\0')
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
	read_rtn = 1;//1回以上whileを通るように
	while (!ft_strchr(save, '\n') && read_rtn != 0)
	{
		read_rtn = read(fd, tmp, BUFFER_SIZE);
		if (read_rtn == -1)
		{
			free(tmp);
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
	int			n;
	char		*line;
	static char	*save;
	
	save = ft_read(fd, save);
	if (!save)
		return (NULL);
	line = ft_getline(save);
	save = ft_save(save);
	return (line);
}