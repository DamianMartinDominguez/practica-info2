#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct cliente
{
  char clave[6];
  char nombre[20];
  float credito;
}cliente_t;

// prototipos

void carga(void);
void ver(void);
void agregar(void);
void modificar(void);
void listar(void);


void main(void)
{
char s='n';
while(s!='s' && s!='S')
{
system("clear");
printf("\n\n\nMENU DE OPCIONES  \n");
printf("=================  \n");
printf("C_ CARGA DE DATOS  \n");
printf("V_ VER DATOS  \n");
printf("A_ AGREGAR DATOS  \n");
printf("M_ MODIFICAR DATOS  \n");
printf("L_ LISTAR DATOS  \n");
printf("S_ SALIR  \n");
printf("OPCION:  \n");
s=getchar();
switch(s)
{
  case 'c':
  case 'C':
            carga();
            break;
  case 'v':
  case 'V':
            ver();
            break;
  case 'a':
  case 'A':
            agregar();
            break;
  case 'm':
  case 'M':
            modificar();
            break;
  case 'l':
  case 'L':
            listar();
            break;
}

}

printf("\n\n Fin del programa");
system("pause");

}



void carga(void)
{
int f;
char s='n';
FILE *p;
if((p=fopen("menuABM","wb"))==NULL)
{
printf("\n problemas al abrir el archvo\n");
getch();
s=27;
}
while(s!='27')
{
system("clr");
printf("\n\n\nMENU DE CARGA  \n");
printf("=================  \n");
printf("ingrese la clave \n");
fflush(stdin);
gets(cliente_t.clave);
printf("ingrese el nombre  \n");
fflush(stdin);
gets(cliente_t.nombre);
printf("ingrese el credito  \n");
fflush(stdin);
scanf("%f",&cliente_t.credito);
f=fwrite(&cliente_t,sizeof(cliente_t),1,p);
f(f!=1);
{
printf("\n no grabo el ultimo registro");
getch();
}
fflush(stdin);
printf("\n Toque una tecla para continuar, ESC para salir");
s=getche();
}
fclose(p);
}

void ver(void)
{
int f,k=1;
char s='n',clave[6];
FILE *p;
if((p=fopen("menuABM","rb"))==NULL)
{
printf("\n problemas al abrir el archvo\n");
getch();
s=27;
}
if(s!=27)
{
system("clr");
printf("\n\n\nMENU VER  \n");
printf("=================  \n");
printf("ingrese la clave \n");
fflush(stdin);
gets(cliente_t.clave);
while(!feof(p))
{
  f=fread(&cliente_t,sizeof(cliente_t),1,p);
  if(f!=1)
  {
  if(!feof(p))
  {
  printf("\nno leyo el ultimo registro");
  printf("\n *** %d ***",f);
  getche();
  }
  
  }
 if(!strcmp(cliente.clave,clave))
 {
   printf("\nno nombre: %s",cliente_t.nombre);
   printf("\nno credito: %8.2f",cliente_t.credito);
   printf("\n toque una tecla para seguir");
   getche();
   k=0;
   break;
 }
}
if(k)
{
printf("\n no se encontro ");
getche();
}
fclose(p);
}
}

void agregar(void)
{
int f;
char s='n';
FILE *p;
if((p=fopen("menuABM","rb+"))==NULL)
{
printf("\n problemas al abrir el archvo\n");
getch();
s=27;
}
fseek(p,0l,2);
while(s!='27')
{
system("clr");
printf("\n\n\nMENU AGREGAR  \n");
printf("=================  \n");
printf("ingrese la clave \n");
fflush(stdin);
gets(cliente_t.clave);
printf("ingrese el nombre  \n");
fflush(stdin);
gets(cliente_t.nombre);
printf("ingrese el credito  \n");
fflush(stdin);
scanf("%f",&cliente_t.credito);
f=fwrite(&cliente_t,sizeof(cliente_t),1,p);
f(f!=1);
{
printf("\n no grabo el ultimo registro");
getch();
}
fflush(stdin);
printf("\n Toque una tecla para continuar, ESC para salir");
s=getche();
}
fclose(p);
}


void modificar(void)
{
int f,k=1;
char c='n',s='n',clave[6];
FILE *p;
if((p=fopen("menuABM","r+b"))==NULL)
{
printf("\n problemas al abrir el archvo\n");
getch();
s=27;
}
while(s!='27')
{
system("clr");
printf("\n\n\nMENU MODIFICAR  \n");
printf("=================  \n");
printf("ingrese la clave \n");
fflush(stdin);
gets(cliente_t.clave);

while(!feof(p))
{
f=fread(&cliente_t,sizeof(cliente_t),1,p);
if(f!=1)
{
if(!feof(p))
{
  printf("\nno leyo el ultimo registro");
  printf("\n *** %d ***",f);
  getch();
  }
  else
  break;
 }
 if(!strcmp(cliente_t.clave,clave))
 {
  printf("\nno nombre: %s",cliente_t.nombre);
  printf("\nno credito: %8.2f",cliente_t.credito);
  
  printf("\ningrese el nombre  \n");
  fflush(stdin);
  gets(cliente_t.nombre);
  printf("ingrese el credito  \n");
  fflush(stdin);
  scanf("%f",&cliente_t.credito);
  system("clr");
  printf("\n\n\nMENU MODIFICAR  \n");
  printf("=================  \n");
  printf("Datos a grabar \n");
  fseek(p,(long)(-1)*(sizeof(cliente_t)),1);
  printf("\nno nombre: %s",cliente_t.nombre);
  printf("\nno credito: %8.2f",cliente_t.credito);
  printf("\n confirma(S/N)");
  c=getche();
  c=tolower(c);
  if(c=='s')
  {
  f=fwrite(&cliente_t,sizeof(char),sizeof(cliente_t),p);
  printf("\n registro guardado");
  getch();
  
  if(f!=sizeof(cliente_t))
  {
  printf("\nno grabo el ultimo registro");ç
  getch();
  }
  }
  else
  {
  printf("\nno grabo el ultimo registro");ç
  getch();
  }
  k=0;
  break;
  }
  }
  if(k)
  {
  printf("\n no se encontro");
  getch();
  }
  fclose(p);
  }
  }
  

void listar(void)
{
int f,k=1;
char c='n',s='n',clave[6];
FILE *p;
if((p=fopen("menuABM","rb"))==NULL)
{
printf("\n problemas al abrir el archvo\n");
getch();
s=27;
}
if(s!='27')
{
system("clr");
printf("\n\n\nMENU LISTAR  \n");
printf("=================  \n");
printf("ingrese la clave \n");
fflush(stdin);
gets(cliente_t.clave);

while(!feof(p))
{
f=fread(&cliente_t,sizeof(cliente_t),1,p);
k++;
if(f!=1)
{
if(!feof(p))
{
  printf("\nno leyo el ultimo registro");
  printf("\n *** %d ***",f);
  getch();
  }
  else
  break;
 }
 if(!strcmp(cliente_t.clave,clave)>0)
 {
 gotoxy(1,6);
  printf("\n clave nombre credito");
  printf("\n ====================");
  gotoxy(1,8+k);
  printf("\n %5s %-20s %10.2f",cliente_t.clave,cliente_t.nombre,cliente_t.credito);
  gotoxy(1,23);
  printf("toque una tecla para seguir");
  if(k==12)
  {
  getch();
  k=1;
  system("clr");
  printf("\n\n\nMENU LISTAR  \n");
  printf("=================  \n");
  }
  }
  }
  fclose(p);
  if(k!=1)
  getch();
  }
  }
  
  



