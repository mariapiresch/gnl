/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapires- <mapires-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:36:03 by mapires-          #+#    #+#             */
/*   Updated: 2023/01/13 16:36:06 by mapires-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_info
{
	char			*content;
	struct s_info	*next;
	int				end; // =1 si he llegado al final del fd, =0 si no, =-1 en caso de error 
	int				new; // =1 si tengo una línea completa, =0 no está completa, =2 si es el final
	int				length;
}			t_info;

void	ft_get_info(t_info *info);
char	*get_next_line(int fd);
void	ft_copy_line(t_info *info, char *line);

#endif
