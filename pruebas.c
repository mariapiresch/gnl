#include <stdio.h>      //printf
#include <fcntl.h>      //open
#include <unistd.h>     //read and close
#include <stdlib.h> 	//malloc

/*int main(void)
{
    int fd = open("pruebas.txt", O_RDONLY);
    char    str[100];
    int leido;
    int	i = 0;
    while (i < 22)
	{
    	leido = read(fd, (str + 2 * i), 2);
    	printf("%s        chars leidos: %i vuelta: %i\n", str, leido, i);
		i++;
	}
    close(fd);
    return (0);
}*/

/*
char	*estatica(void)
{
	static char *est;

	est = (char *)malloc(5 * sizeof(char));
	if (!est)
		return(NULL);
	est[0] = 'a';
	return(est);
}

void	modifico(char *str)
{
	str[0] = 'Z';
}

int main() 
{
	char	*est;

	est = estatica();
	printf("%s\n", est);
	modifico(est);
	printf("%s\n", est);
	return (0);
}
*/


/* 
ESTO ES UNA LOCURA:

char	*get_next_line(int fd)
{
	static t_info	*info;
	char			*str;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info || fd == NULL)
		return (NULL);
	info->content = (char *)malloc(101 * sizeof(char));
	if (!info->content)
	{
		free(info);
		return (NULL);
	}
	info->next = NULL;
	if (ft_read(fd, info))
	{
		str = (char *)malloc((info->length + 1) * sizeof(char)); //+1 por el '\0'
		if (!str)
		{
			ft_free(info);
			return (NULL);
		}
		ft_copy_line(info, str);
	}
	if (info->error == -1)
		return (NULL);
	return (str);
}

bool	ft_read(int fd, t_info *info)
{
	bool	new_line;

	new_line = false;
	while (!new_line)
	{
		info->length = read(fd, info->content, 100);
		new_line = (ft_find(info) || (info->length < 100));
		if (info->error == -1)
			return (false);
		if (!new_line)
		{
			ft_new_next(info);
			new_line = ft_read(fd, info->next);
		}
	}
	return (new_line);
}

void	ft_new_next(t_info *info)
{
	t_info	*save;

	save = info;
	if (!info)
		return ;
	info->next = (t_info *)malloc(sizeof(t_info));
	if (!info->next)
	{
		info->error = -1;
		return ;
	}
	info = info->next;
	info->content = (char *)malloc(101 * sizeof(char));
	if (!info->content)
	{
		free(info);
		save->error = -1;
		return ;
	}
}

bool	ft_find(t_info *info)
{
	int	i;

	i = 0;
	if (!info->content)
	{
		info->error = -1;
		return (false);
	}
	while (info->content[i] && info->content[i] != '\n')
		i++;
	info->length += i;
	if (info->content[i] && info->content[i] == '\n')
		return (true);
	return (false);
}

void	ft_free(t_info *info)
{
	t_info	*save;
	t_info	*nodo;

	nodo = info;
	if (!info)
		return ;
	while (nodo)
	{
		if (nodo->content)
			free(nodo->content);
		save = nodo->next;
		free(nodo);
		nodo = save;
	}
}

void    ft_copy_line(t_info *info, char *str)
{
    int i;

    i = 0;
    while (info->content[i]!= '\n')
    {
        str[i] = info->content[i];
        i++;
    }
}

*/

/*

ESTO ES UNA LOCURA 2:


char	*get_next_line(int fd)
{
	static char	**buffer = NULL;
	char		*str;
	int			length;
	int			index;

	if (!buffer)
		buffer = (char **)malloc(100 * sizeof(char *));
	if (!buffer || fd == NULL)
		return (NULL);
	index = -1;
	if (!buffer[0]) //si no hay nada en buffer -> leo
		length = ft_find_new_line(fd, buffer, 0, &index);
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
	*index = ft_index(buffer[0]);
	if (index == -42) //si hay algun error
		return (-42);
	else if (index == -1) //si no he encontrado '\n' leo
	{
		new_length = ft_find_new_line(fd, buffer, 1, &index);
		if (new_length == -42)
			return (-42);
		length += new_length;
	}
	return (length);
}

int	ft_find_new_line(int fd, char **buffer, int cnt, int *index)
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
		*index = ft_index(buffer[cnt]);
		if (*index == -42)
			return (-42);
		cnt++;
	}
	return (length);
} // -42 == error, 0 == no hay mas que leer , >0 == gnl crea una línea

void	ft_copy_line(char **buffer, char *str, int lenght, int cnt, int index)
{
	int	i;
}

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

int	ft_index(char *str) //índice donde está '\n' || -1 == no lo encuentra || -42 == error
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

*/