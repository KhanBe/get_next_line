/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewoo <jaewoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:23:12 by jaewoo            #+#    #+#             */
/*   Updated: 2022/01/11 01:35:37 by jaewoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*strdup_ch(char *buf_line, int ch)
{
	char	*temp;
	size_t	len;

	len = ft_strchr(buf_line, &ch) - buf_line;
	temp = ft_substr(buf_line, 0, len);
	return (temp);
}

char	*extract_line(char **buf_line)
{
	char	*temp;
	char	*save;

	temp = strdup_ch(*buf_line, '\n');
	save = strdup_ch(ft_strchr(*buf_line) + 1, '\0');
	free(*buf_line);
	*buf_line = save;
	return (temp);
}

char	*ft_free(char *buf_line)
{
	free(buf_line);
	return (0);
}

char	*get_next_line(int fd)
{
	char		*buffer[OPEN_MAX];
	static char	*buf_line;
	char		*res_line;
	int			index;

	res_line = 0;
	index = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	while (!ft_strchr(buf_line, '\n') && index != 0)
	{
		index = read(fd, buffer, BUFFER_SIZE);
		if (index < 0)
			return (0);
		buffer[index] = '\0';
		buf_line = ft_strjoin(buf_line, buffer);
		if (!buf_line)
			return (0);
	}
	if (ft_strchr(buf_line, '\n'))
		return (extract_line(&buf_line));
	if (buf_line && buf_line[0])
		res_line = strdup_ch(buf_line, '\0');
	buf_line = ft_free(buf_line);
	return (res_line);
}
