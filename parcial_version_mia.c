*/ existe un archivo binario "paciente.dat" secuencial con la siguiente estructura: 

int id;
char n[30];
unsigned int tipo;

que prentan los datos de un paciente que se efectuara un analisis donde la variable tipo
es un numero binario que en su bit numero 3 indica con 1 significa analisis de orina,
y el bit 4 en 1 significa analisis de sangre.
crear una funcion que arme una cola con aquellos registros del archivo que corresponde analisis de sangre.
mostrar los datos de la cola en el main y luego eliminarlos, 
sabiendo que no hay variables globales 
/*

//codigo

#include <stdio.h>
#include <stdlib.h>

tipedef struct 
{
  int id;
  char n[30];
  unsigned int tipo;
 }paciente_t;
 
 struct cola_t
{
    pila_t data;
    struct cola_t *siguiente;
}cola_t;

int main()
{
    datos_t nuevo;
    struct cola_t *cola = NULL, *aux= NULL, *local = NULL;
    short opc= 0;
   
    do
    {
        aux = (struct cola_t*)malloc(sizeof(struct cola_t));
        if(aux==NULL)
        {
            printf("\n no hay memoria disponible\n");
            return 0;
            
        }
       
    do
    {
        printf("\n el registro contiene :\n Nombre:%s  \nEdad: %d \nLegajo: %ld", cola->data.nombre,cola->data.edad,cola->data.legajo);
        aux = cola;
        cola = cola->siguiente;
        free(aux);
    }while(cola->siguiente != NULL);
    printf("\n----------------------------------------------------------------");
    printf("\n el registro contiene :\n Nombre:%s  \nEdad: %d \nLegajo: %ld", cola->data.nombre,cola->data.edad,cola->data.legajo);
    printf("\n----------------------------------------------------------------");
    printf("\nfin");
    free(cola);
        
    return 0;
}
