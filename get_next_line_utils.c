/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srikuto <srikuto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:34:51 by srikuto           #+#    #+#             */
/*   Updated: 2025/05/02 14:42:59 by srikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

static char	*assign_string(char *str, char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free (s1);
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		if (s1)
			s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	return (assign_string(str, s1, s2));
}

// #include "get_next_line.h"

// size_t	ft_strlen(const char *c)
// {
// 	size_t	i;

// 	i = 0;
// 	while (c[i] != '\0')
// 		i++;
// 	return (i);
// }

// char	*ft_strchr(char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	if (!s)
// 		return (0);
// 	if (c == '\0')
// 		return ((char *)&s[ft_strlen(s)]);
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == (char) c)
// 			return ((char *)&s[i]);
// 		i++;
// 	}
// 	return (0);
// }
// // char	*ft_strchr(char *str, int c)
// // {
// // 	if (!str)
// // 		return (NULL);
// // 	while (1)
// // 	{
// // 		if (*str == (char)c)
// // 			return ((char *)str);
// // 		if (*str == '\0')
// // 			return (NULL);
// // 		str++;
// // 	}
// // }

// static int	all_len(char const *s1, char const *s2)
// {
// 	size_t	s1len;
// 	size_t	s2len;

// 	s1len = 0;
// 	while (s1[s1len] != '\0')
// 		s1len++;
// 	s2len = 0;
// 	while (s2[s2len] != '\0')
// 		s2len++;
// 	return (s1len + s2len);
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*str;

// 	if (!s1)
// 	{
// 		s1 = (char *)malloc(1 * sizeof(char));
// 		s1[0] = '\0';
// 	}
// 	if (!s1 && !s2)
// 		return (NULL);
// 	str = (char *)malloc(all_len(s1, s2) + 1);
// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	while (s1[i] != '\0')
// 	{
// 		str[i] = s1[i];
// 		i++;
// 	}
// 	j = 0;
// 	while (s2[j] != '\0')
// 	{
// 		str[i] = s2[j];
// 		i++;
// 		j++;
// 	}
// 	str[i] = '\0';
// 	return (str);
// }
