/******************************************************************************

ejemplo lista

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

struct listaDoble_t
{
    datos_t data;
    struct listadoble_t *siguiente, *anterior;
}pila_t;

int main()
{
    datos_t nuevo;
    struct listaDoble_t *lista = NULL, *aux= NULL,*local= NULL;
    short opc= 0;
    printf("\nejemplo lista doble con memoria dinamica\n");
    do
    {
        aux = (struct listaDoble_t*)malloc(sizeof(struct listaDoble_t));
        if(aux==NULL)
        {
            printf("\n no hay memoria disponible\n");
            return 0;
            
        }
        printf("\n ingrese el registro de la lista\n");
        printf("\n ingrese el nombre\n");
        fflush(stdin);
        scanf("%s",&aux->data.nombre);
        printf("\n ingrese la edad\n");
        fflush(stdin);
        scanf("%d",&aux->data.edad);
        printf("\n ingrese el legajo\n");
        fflush(stdin);
        scanf("%ld",&aux->data.legajo);
        if(lista == NULL)
        {
          lista = aux;
          lista->siguiente = NULL;
          lista->anterior = NULL;
         }
         else
         {
          local = lista;  
          while((local->data.edad <= aux->data.edad) && (local->siguiente != NULL))
          {
            local = local->siguiente;
          }
          //reemplazo a local
          if(local->data.edad > aux->data.edad)//registro intermedio
          {
            if(aux->anterior != NULL) aux->anterior->siguiente = aux;
            else lista = aux;
            aux->anterior = local->anterior;
            local->anterior = aux;
            aux->siguiente = local;
           }
           else{
           //registro al final
           local->siguiente = aux;
           aux->anterior = local;
           aux->siguiente = NULL;
           
           
   
        printf("\ndesea seguir agregando datos?\n 1_S  2_N");
        fflush(stdin);
        scanf("%d",&opc);
        
        
            
    }while(opc == 1);
    printf("\n carga de pila completada" );
    do
    {
        printf("\n como desea imprimirlo? 1- mayor a menor   2- menor a mayor  3- liberar salir  ");
         fflush(stdin);
        scanf("%d",&opc);
        if(opc == 2)
        {
          local = lista; 
          do{
           printf("\n----------------------------------------------------------------");
           printf("\n el registro contiene :\n Nombre:%s  \nEdad: %d \nLegajo: %ld", pila->data.nombre,pila->data.edad,->data.legajo);
           local= local->siguiente;
        }while(local->siguiente != NULL);
         printf("\n----------------------------------------------------------------");
         printf("\n el registro contiene :\n Nombre:%s  \nEdad: %d \nLegajo: %ld", pila->data.nombre,pila->data.edad,->data.legajo);
         printf("\n----------------------------------------------------------------");
        }
        if(opc == 1)
        {
          local = lista; 
          while(local->siguiente != NULL)
            local = local->siguiente;
          do{
              printf("\n----------------------------------------------------------------");
              printf("\n el registro contiene :\n Nombre:%s  \nEdad: %d \nLegajo: %ld", pila->data.nombre,pila->data.edad,->data.legajo);
              local= local->anterior;
             }while(local->anterior != NULL);
             printf("\n----------------------------------------------------------------");
             printf("\n el registro contiene :\n Nombre:%s  \nEdad: %d \nLegajo: %ld", pila->data.nombre,pila->data.edad,->data.legajo);
             printf("\n----------------------------------------------------------------");
             }
             }while(opc != 3);
             printf("\n liberando...");
             do {
              aux = lista;
              lista = lista->siguiente;
              free(aux);
              }while(lista->siguiente != NULL);
              free(lista);
              printf("\nfin");
        
    return 0;
}
