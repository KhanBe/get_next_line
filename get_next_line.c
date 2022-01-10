/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewoo <jaewoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:23:12 by jaewoo            #+#    #+#             */
/*   Updated: 2022/01/04 18:57:35 by jaewoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.c"

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*buf_line;
	char		*res_line;
	int			index;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_strdup("");
	buf_line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf_line)
		return (NULL);
	return (res_line);
}
