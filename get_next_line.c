/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapires- <mapires-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:33:42 by mapires-          #+#    #+#             */
/*   Updated: 2023/01/13 16:33:50 by mapires-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	**buffer;
	char		*str;
	bool		error;
	int			length;

	error = false;
	buffer = (char **)malloc(100 * sizeof(char *));
	if (!buffer || fd == NULL)
		return (NULL);
	buffer[0] = (char *)malloc(100 * sizeof(char));
	if (!buffer[0])
	{
		free(buffer);
		return (NULL);
	}
	length = ft_read(fd, buffer);
	if (length == 0)
		return (NULL);
	str = (char *)malloc(length * (sizeof(char)));
	ft_copy_line(buffer, str);
	return (str);
}

int	ft_read(int fd, char **buffer)
{
	int		length;
	int		cnt;
	int		located;

	length = 0;
	cnt = 0;
	located = 0;
	while(located == 0)
	{
		buffer[cnt] = (char *)malloc(101 * sizeof(char));
		if (!buffer[cnt])
		{
			ft_free_all(buffer, cnt - 1);
			return (0);
		}
		length = read(fd, buffer[cnt], 100);
		buffer[cnt][100] = '\0';
		if (length < 100)
			return (length);
		located = ft_find_nl(buffer[cnt]);
		if (located == -1)
			return (0);
		cnt++;
	}
	return (length);
}

void	ft_free_all(char **buffer, int cnt)
{
	while (cnt >= 0)
	{
		free(buffer[cnt]);
		cnt--;
	}
	free(buffer);
}

int	ft_find_nl(char *str) // 0 == false , >0 == true , -1 == error
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] && str[i] == '\n')
		return (i);
	return (0);
}