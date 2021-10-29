/******************************************************************************

ejemplo cola

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct
{
    char nombre[30];
    unsigned short edad;
    long legajo;
    
}datos_t;

struct cola_t
{
    cola_t data;
    struct cola_t *siguiente;
}cola_t;

int main()
{
    datos_t nuevo;
    struct cola_t *cola = NULL, *aux= NULL, *local = NULL;
    short opc= 0;
    printf("\nejemplo cola con memoria dinamica\n");
    do
    {
        aux = (struct cola_t*)malloc(sizeof(struct cola_t));
        if(aux==NULL)
        {
            printf("\n no hay memoria disponible\n");
            return 0;
            
        }
        printf("\n ingrese el registro a apilar\n");
        printf("\n ingrese el nombre\n");
        fflush(stdin);
        scanf("%s",&aux->data.nombre);
        printf("\n ingrese la edad\n");
        fflush(stdin);
        scanf("%d",&aux->data.edad);
        printf("\n ingrese el legajo\n");
        fflush(stdin);
        scanf("%ld",&aux->data.legajo);
        aux->siguiente = NULL ;
        if(cola==NULL)
        {
        cola = aux;
        local = aux;
        }
        else
        {
        local->siguiente = aux;
        local = aux;
        }
        printf("\ndesea seguir agregando datos?\n 1_S  2_N");
        fflush(stdin);
        scanf("%d",&opc);
        
        
            
    }while(opc == 1);
    printf("\n carga de cola completada" );
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
