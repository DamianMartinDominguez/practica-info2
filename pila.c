/******************************************************************************

ejemplo pila

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    char nombre[30];
    unsigned short edad;
    long legajo;
    
}datos_t;

struct pila_t
{
    pila_t data;
    struct pila_t *anterior;//*l puntero de lazo
}pila_t;

int main()
{
    datos_t nuevo;
    struct pila_t *pila = NULL, *aux= NULL;//apuntan todos a null
    short opc= 0;
    printf("\nejemplo pila con memoria dinamica\n");
    do
    {
        aux = (struct pila_t*)malloc(sizeof(struct pila_t));//se asigna memoria dinamica
        if(aux==NULL)
        {
            printf("\n no hay memoria disponible\n");
            return 0;
            
        }
        printf("\n ingrese el registro a apilar\n");
        printf("\n ingrese el nombre\n");
        fflush(stdin);
        scanf("%s",&aux->data.nombre);//se asignan los datos en el auxiliar
        printf("\n ingrese la edad\n");
        fflush(stdin);
        scanf("%d",&aux->data.edad);
        printf("\n ingrese el legajo\n");
        fflush(stdin);
        scanf("%ld",&aux->data.legajo);
        aux->anterior = pila;//aux->l= p
        pila = aux;//p=aux
        printf("\ndesea seguir agregando datos?\n 1_S  2_N");
        fflush(stdin);
        scanf("%d",&opc);
        
        
            
    }while(opc == 1);
    printf("\n carga de pila completada" );
    do
    {
        printf("\n el registro contiene :\n Nombre:%s  \nEdad: %d \nLegajo: %ld", pila->data.nombre,pila->data.edad,pila->data.legajo);
        aux = pila;
        pila = pila->anterior;
        free(aux);
    }while(pila->anterior != NULL);
    printf("\n----------------------------------------------------------------");
    printf("\n el registro contiene :\n Nombre:%s  \nEdad: %d \nLegajo: %ld", pila->data.nombre,pila->data.edad,pila->data.legajo);
    printf("\n----------------------------------------------------------------");
    printf("\nfin");
    free(pila);
        
    return 0;
}
/*resumen y observaciones

p o en este caso pila siempre queda apuntando al primer elemento y aux es usado para crear elementos.
si se pierde el primer elemento la pila no se podra acceder nunca y la memoria asignada no se podra acceder y ocupara lugar.
siempre se debe tener un puntero al primer elemento

para crear una pila los pasos a seguir son:

1_ reservar el lugar dinamicamente (en aux).
2_ asignarle los datos a la parte informativa de la estructura pila.
3_ el lazo de la estructura apunte primero (para que funcione con todos los elementos antes de empezar el proceso iterativo p = NULL.
4_ el primero se apuntara al elemento creado en (1)

*/
