/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:18:44 by lissam            #+#    #+#             */
/*   Updated: 2024/07/02 06:53:19 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*all_buffer(int fd, char *str)
{
	char	*buffer;
	int		rd;

	rd = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (rd != 0 && !ft_strchr(str, '\n'))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[rd] = '\0';
		str = ft_strjoin(str, buffer);
		if (!str)
			return (NULL);
	}
	free(buffer);
	return (str);
}

char	*show_line(char *str)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str[0])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i])
		i++;
	s = malloc(i + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		s[j++] = str[i++];
	if (str[i] == '\n')
	{
		s[j] = '\n';
		j++;
	}
	s[j] = '\0';
	return (s);
}

char	*rest(char *str)
{
	char	*s;
	int		j;
	size_t	i;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	s = malloc(ft_strlen(str) - i + 1);
	if (!s)
		return (NULL);
	if (str[i] == '\n')
		i++;
	while (str[i] != '\0')
		s[j++] = str[i++];
	s[j] = '\0';
	free(str);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*s;

	if (fd == -500)
	{
		free(str);
		return (NULL);
	}
	if (BUFFER_SIZE <= 0 || fd < 0 || BUFFER_SIZE >= 2147483647)
		return (NULL);
	str = all_buffer(fd, str);
	if (!str)
		return (NULL);
	s = show_line(str);
	str = rest(str);
	return (s);
}
