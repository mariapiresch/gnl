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

char    *get_next_line(int fd)
{
    static t_info  *info;

    info = (t_info *)malloc(sizeof(t_info));
    if (!info || fd == NULL)
		return (NULL);
    info->end = 0;
    info->new = 0;
    while (info->end == 0)
    {
        ft_read(fd, info);
        ft_find(info);
    }    
}

void    ft_read(int fd, t_info *info)
{
    info->length = read(fd, info->content, 100);
    if (info->length < 100)
        info->end = 1;
}

void    ft_find(t_info *info)
{
    int i;

    i = 0;
    while (info->content[i] && info->content[i] != '\n')
        i++;
    if (info->content[i] && info->content[i] == '\n')
        info->new = 1;
    info->length += i;
}

/*
void    ft_copy_line(t_info *info, char *line)
{
    int i;

    if (!taken || !line)
        return;
    i = 0;
    while (taken[i]!='\n')
    {
        line[i] = taken[i];
        i++;
    }
}*/


//TENGO QUE METER LA VARIABLE ESTATICA!!!
//COMPROBAR LEAKS DE MEMORIA!
//ARCHIVOS BONUS CON _BONUS.C O _BONUS.H
//cuando acabe mover todas las funciones de ayuda a get_n_l_utils.c





