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
# include <stdbool.h>

char	*get_next_line(int fd);
void	ft_free_all(char **buffer, int cnt);

#endif

/*

typedef struct s_info
{
	char			*content;
	struct s_info	*next;
	int				error; // =-1 si ha habido algún error, =0 si no
	int				length;
}			t_info;

void	ft_get_info(t_info *info);
void	ft_copy_line(t_info *info, char *str);

*/