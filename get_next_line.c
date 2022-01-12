/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewoo <jaewoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:23:12 by jaewoo            #+#    #+#             */
/*   Updated: 2022/01/12 15:44:26 by jaewoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer[MAX_FD];
	static char	*buf_line;
	char		*res_line;
	int			index;

	res_line = 0;
	index = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
}
