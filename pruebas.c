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
    	leido = read(fd, str, 2);
    	printf("%s        chars leidos: %i vuelta: %i\n", str, leido, i);
		i++;
	}
    close(fd);
    return (0);
}
*/

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
