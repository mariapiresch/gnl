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

void ft_get_info(t_info *info)
{
    int i;

    i = 0;
    while (info->taken[i]!='\n' && info->taken[i])
        i++;
    if (info->taken[i] == '\n')
        info->new = 1;
    else
        info->new = 0;
    info->length += i;
}

char    *get_next_line(int fd)
{
    char    *taken;
    char    *line;
    int     len_read;

    if (fd == NULL)
        return (NULL);
    taken = (char *)malloc(100 * sizeof(char));
    line = (char *)malloc(100 * sizeof(char));
    //if (!taken)
        //y si falla la reserva de memoria que hago????
    len_read = 100;
    while (len_read == 100) //si es =100 no he terminado de leer
    {
        len_read = read(fd, taken, 100);
    }

}
