#include <stdio.h>      //printf
#include <fcntl.h>      //open
#include <unistd.h>     //read and close
 
int main(void)
{
    int fd = open("pruebas.txt", O_RDONLY);
    char    str[100];
    int	i = 0;
    while (i < 5)
	{
    	read(fd, str, 2);
    	printf("%s\n", str);
		i++;
	}
    close(fd);
    return (0);
}

/*
valor devuelto: - la línea leída
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
