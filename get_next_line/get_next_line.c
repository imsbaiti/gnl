/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsbaiti <imsbaiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:40:08 by imsbaiti          #+#    #+#             */
/*   Updated: 2024/12/28 15:12:22 by imsbaiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*last_line(char *str)
{
	char	*rest;
	int			i;
	int			j;

	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	while (str[i] !=  '\n')
		i++;
	while (str[i] == '\0')
		return (free(str), NULL);
	rest = malloc(ft_strlen(str) - i + 1);
	if (!rest)
		return (free(str),NULL);
	j = 0;
	while (str[i])
		rest[j++] = str[i++];
	rest[j] = '\0';
	free(str);
	return (rest);
}
char	*first_line(char *str)
{
	char	*res;
	int		i;
	int 	j;

	i = 0;
	j = 0;
	if (!str || !(*str))
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	res = malloc(i + 1);
	if (!res)
		return (NULL);
	while (j < i)
	{
		res[j] = str[j];
		j++;
	}
	res[j] = '\0';
	return (res);
}
char	*ft_reading(char *str, int fd)
{
	char	*buffer;
	int		bytes;
	
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(str);
		return (NULL);
	}
	bytes = 1;
	while (bytes > 0 && ft_strchr(str, '\n') == -1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buffer),free(str),NULL);
		if (bytes == 0)
			break;
		buffer[bytes] == '\0';
		str = ft_strjoin(str, buffer);
		if (!str)
			free(buffer);
			return (NULL);
	}
		free(buffer);
		return (str);	
}
char *get_next_line(int fd)
{
	static char	*str;
	char *res;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_reading(str, fd);
	if (!str)
		return (NULL);
	res = first_line(str);
	if (!str)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	str = last_line(str);
	return (res);
}