/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    get_next_line_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapires- <mapires-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:34:05 by mapires-          #+#    #+#             */
/*   Updated: 2023/01/13 16:34:08 by mapires-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free_all(char **buffer, int i)
{
	while (i >= 0)
	{
		free(buffer[i]);
		i--;
	}
	free(buffer);
}

int	ft_strlen(char *str) //si veo que no la uso para nada más la quito y lo meto en ft_buffer_not_empty
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
