/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:37:26 by jaewoo            #+#    #+#             */
/*   Updated: 2022/01/12 15:42:14 by jaewoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int ch)
{
	int		i;
	char	temp;
	char	*stemp;

	if (!str)
		return (0);
	i = 0;
	temp = (char)ch;
	stemp = (char *)str;
	while (stemp[i] != temp)
	{
		if (stemp[i] == '\0')
			return (NULL);
		i++;
	}
	return (&stemp[i]);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*temp;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	temp = (char *)malloc(sizeof(char) * size);
	if (!temp)
		return (NULL);
	i = -1;
	while (s1[++i])
		temp[i] = s1[i];
	j = -1;
	while (s2[++j])
		temp[i + j] = s2[j];
	temp[i + j] = '\0';
	return (temp);
}

char	*ft_strdup(const char *src)
{
	char	*array;
	size_t	len;
	size_t	i;

	if (!src)
		return (NULL);
	len = ft_strlen(src);
	array = (char *)malloc(sizeof(char) * (len + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		array[i] = src[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	char	*temp;

	if (s == 0)
		return (NULL);
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (NULL);
	len_s = ft_strlen(s);
	i = 0;
	while (i < len && start + i < len_s)
	{
		temp[i] = s[start + i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
