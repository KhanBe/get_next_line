/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewoo <jaewoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:23:12 by jaewoo            #+#    #+#             */
/*   Updated: 2022/01/19 17:47:41 by jaewoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_join(int fd, char *buffer, char *buf_line)
{
	int		read_value;
	char	*temp;

	read_value = 1;
	while (read_value != '\0')
	{
		read_value = read(fd, buffer, BUFFER_SIZE);
		if (read_value == -1)
			return (0);
		else if (read_value == 0)
			break ;
		buffer[read_value] = '\0';
		if (!buf_line)
			buf_line = ft_strdup("");
		temp = buf_line;
		buf_line = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (buf_line);
}

char	*mod_next_line(char *res_line)
{
	size_t	index;
	char	*temp;

	index = 0;
	while (res_line[index] != '\n' && res_line[index] != '\0')
		index++;
	if (res_line[index] == '\0' || res_line[1] == '\0')
		return (0);
	temp = ft_substr(res_line, index + 1, ft_strlen(res_line) - index);
	if (temp[0] == '\0')
	{
		free(temp);
		temp = NULL;
	}
	res_line[index + 1] = '\0';
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*buf_line;
	char		*res_line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	res_line = read_join(fd, buffer, buf_line);
	free(buffer);
	buffer = NULL;
	if (!res_line)
		return (NULL);
	buf_line = mod_next_line(res_line);
	return (res_line);
}
