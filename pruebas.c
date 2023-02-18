#include <stdio.h>      //printf
#include <fcntl.h>      //open
#include <unistd.h>     //read and close
#include <stdlib.h> 	//malloc

int main(void)
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
}


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
valor devuelto: - si todo va bien: la línea leída
                - NULL si algo va mal / si la lectura termina 


funciones autorizadas: read, malloc, free


mi función funciona correctamente cuando lee de stdin (= cuando lee lo que escribo en el teclado)?


la línea devuelta debe terminar con el caracter \n, 
excepto si se ha llegado al final del archivo y éste no termina con un caracter \n

--------------------------------------------------------------------------------------
size_t read (int fd, void* buf, size_t cnt);

--> Parámetros:

fd: descriptor de archivo
buf: búfer para leer datos
cnt: longitud del búfer

--> Devoluciones: cuántos bytes se leyeron realmente

return Número de bytes leídos en caso de éxito
devuelve 0 al llegar al final del archivo
devolver -1 en caso de error
devuelve -1 en interrupción de señal

--> Puntos importantes:

- buf necesita apuntar a una ubicación de memoria válida con una 
longitud no menor que el tamaño especificado debido al desbordamiento.
- fd debe ser un descriptor de archivo válido devuelto por open() para 
realizar la operación de lectura porque si fd es NULL, la lectura debería generar un error.
- cnt es el número solicitado de bytes leídos, mientras que el valor devuelto es el número
real de bytes leídos. Además, algunas veces la llamada al sistema de lectura debería leer 
menos bytes que cnt.
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

//COMPROBAR LEAKS DE MEMORIA!
//ARCHIVOS BONUS CON _BONUS.C O _BONUS.H
//cuando acabe mover todas las funciones de ayuda a get_n_l_utils.c