/* existe un archivo binario "paciente.dat" secuencial con la siguiente estructura: 

int id;
char n[30];
unsigned int tipo;

que prentan los datos de un paciente que se efectuara un analisis donde la variable tipo
es un numero binario que en su bit numero 3 indica con 1 significa analisis de orina,
y el bit 4 en 1 significa analisis de sangre.
crear una funcion que arme una cola con aquellos registros del archivo que corresponde analisis de sangre.
mostrar los datos de la cola en el main y luego eliminarlos, 
sabiendo que no hay variables globales 
*/

//codigo

#include <stdio.h>
#include <stdlib.h>

struct datos{
            int id;
            char n[30];
            unsigned int tipo;
            };

struct cola{
            struct datos d;
            struct cola*l;
            };

void genera archivo(void);
void setCola(struct cola **p,struct cola **u);

int main()
{
 struct cola *p=NULL, *u= NULL, *aux;
 genera_archivo(void);
 void setCola(&p,&u);
 while(p)
 {
    printf("%4d %-20s 0x%x",p->d.id, p->d.n, p->d.tipo);
    aux=p;
    p=p->l;
    free(aux);
 }
 system("pause");
 return 0;
}

void setCola(struct cola **p,struct cola **u)
{
  struct datos bf;
  struct cola *aux;
  FILE *fp;
  if(fp=fopen("paciente.dat",rb))== NULL)
    {
    printf("\n error en el archivo\n");
    return 1;
    }
  fread(&bf,sizeof(struct datos),1,fp);
  while(!feof(fp))
  {
  if(bf.tipo & 0x10)
  {
  aux = (struct cola*)malloc(sizeof(struct cola));
  if(aux)
  {
    aux->d=bf;
    if(*p==NULL)
      *p= *u = aux;
    else
    {
      (*u)->l=aux;
      *u=aux;
    }
    *u)->l= NULL;
}
}
fread(&fb,sizeof(struct datos),1,fp);
}
fclose(fp);
}

void genera_archivo(void)
{
struct datos bf[]={ 1,"juan primero",0x11,
                    2,"juan segundo",0x12,
                    3,"juan tercero",0x13,
                    4,"juan cuarto",0x14,
                    5,"juan quinto",0x15,
                    6,"juan sexto",0x16,
                    7,"juan septimo",0x17,
                    8,"juan octavo",0x18,};
FILE *fp=fopen("paciente.dat","wb");
fwrite(fb,sizeof(struct datos),8,fp);
fclose(fp);
}



