#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
    {
        char nombre[30];
        int numero;
    }alumno_t;

int main()
{
    alumno_t alumnoNuevo;
    printf("\n escriba nombre\n");
    fflush(stdin);
    gets(alumnoNuevo.nombre);
    printf("\n escriba matricula\n");
    fflush(stdin);
    scanf("%d",&alumnoNuevo.numero);
    printf("\n nel nombre ingresado fue: \t %s",alumnoNuevo.nombre);
    printf("\n nel numero ingresado fue: \t %d",alumnoNuevo.numero);

    FILE *p;
    if((p=fopen("botoncito.dat","ab"))==NULL)
    {
        printf("no se puede crear el archivo...");
        return 0;
    }
    printf("...");
    fwrite(&alumnoNuevo,sizeof(alumno_t),1,p);
    fclose(p);


    if((p=fopen("botoncito.dat","rb"))==NULL)
    {
        printf("no se puede crear el archivo...");
        return 0;
    }
    fread(&alumnoNuevo,sizeof(alumno_t),1,p);
    while(!feof(p))
    {


    printf("\n...");
    fread(&alumnoNuevo,sizeof(alumno_t),1,p);
    printf("Alumno: %s, matricula: %d", alumnoNuevo.nombre, alumnoNuevo.numero);
    }

    fclose(p);




    return 0;
}
