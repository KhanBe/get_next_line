/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewoo <jaewoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:23:12 by jaewoo            #+#    #+#             */
/*   Updated: 2022/01/11 00:14:31 by jaewoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.c"

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
		return (extract)
	return (res_line);
}
