/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsbaiti <imsbaiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:40:17 by imsbaiti          #+#    #+#             */
/*   Updated: 2024/12/26 01:28:12 by imsbaiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include<stdlib.h>
#include<unistd.h>


#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif


char *get_next_line(int fd);
char	*ft_strjoin(char *s1, char const *s2);
int		ft_strchr(const char *str, char c);
size_t	ft_strlen(const char *str);
char	*strdup(const char *s1);

#endif
