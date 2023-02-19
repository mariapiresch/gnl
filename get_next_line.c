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
	static char	**buffer = NULL;
	char		*str;
	int			length;
	int			index;

	buffer = (char **)malloc(100 * sizeof(char *));
	if (!buffer || fd == NULL)
		return (NULL);
	index = -1;
	if (!buffer[0]) //si no hay nada en buffer -> leo
		length = ft_read(fd, buffer, 0, &index);
	else //si hay algo -> primero busco
		length = ft_buffer_not_empty(fd, buffer, &index);
	if (length == -42)
		return (NULL);
	str = (char *)malloc((length + 1) * (sizeof(char))); //+1 por el '\0'
	ft_copy_line(buffer, str);
	return (str);
}

int	ft_buffer_not_empty(int fd, char **buffer, int *index)
{
	int	length;
	int	new_length;

	length = ft_strlen(buffer[0]);
	*index = ft_find_char(buffer[0]);
	if (index == -42) //si hay algun error
		return (-42);
	else if (index == -1) //si no he encontrado '\n' leo
	{
		new_length = ft_read(fd, buffer, 1, &index);
		if (new_length == -42)
			return (-42);
		length += new_length;
	}
	return (length);
}

int	ft_read(int fd, char **buffer, int cnt, int *index)
{
	int		length;
	int		new_length;

	length = 0;
	while (*index == -1) //para si encuentra '\n' || si hay algun error || si no hay más que leer
	{
		buffer[cnt] = (char *)malloc(101 * sizeof(char));
		if (!buffer[cnt])
		{
			ft_free_all(buffer, cnt - 1);
			return (-42);
		}
		new_length = read(fd, buffer[cnt], 100);
		if (new_length == -1)  //ha habido un error
			return (-42);
		buffer[cnt][new_length] = '\0';
		if (new_length < 100)
			return (length + new_length);
		length += new_length;
		*index = ft_find_char(buffer[cnt]);
		if (*index == -42)
			return (-42);
		cnt++;
	}
	return (length);
} // -42 == error, 0 == no hay mas que leer , >0 == gnl crea una línea

int	ft_find_char(char *str) //índice donde está '\n' || -1 == no lo encuentra || -42 == error
{
	int	i;

	i = 0;
	if (!str)
		return (-42);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] && str[i] == '\n')
		return (i);
	return (-1);
}
