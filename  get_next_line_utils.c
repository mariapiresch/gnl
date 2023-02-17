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
}