/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:37:36 by jaewoo            #+#    #+#             */
/*   Updated: 2022/01/04 17:49:09 by jaewoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef MAX_FD
#  define MAX_FD 256
# endif

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int ch);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *src);
char	*ft_substr(const char *s, unsigned int start, size_t len);
#endif
