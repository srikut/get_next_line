/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srikuto <srikuto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:34:33 by srikuto           #+#    #+#             */
/*   Updated: 2025/04/10 10:59:50 by srikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char	*get_next_line(int fd);

size_t	ft_strlen(const char *c);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif