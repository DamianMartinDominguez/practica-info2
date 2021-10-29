// crear un archivo binario con la siguiente estructura, codigo, descripcion, stock, stock minimo y precio.// 
//luego bajarlo en un vector de 4 elementos. encontrar el producto de mayor valorizacion(stock *precio)//

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
FILE *p;
int i;
char salir;
struct {
         int codigo;
         char descripcion[20];
         int stock;
         int stockm;
         float precio;
}t,ti[4];

if((p=fopen("pto.dat","wb"))==NULL)
{
  printf("no se puede abrir\n");
  return;
}
salir='s';

while(salir!='n'&& salir!='N')
{
  printf("coloque codigo\n");
  scanf("%d",&t.codigo);
  printf("coloque descripcion del producto\n");
  getchar(t.descripcion);
  printf("coloque stock,precio y stock minimo\n");
  scanf("%d %f %d",&t.stock,&t.precio,&t.stockm);
  if(fwrite(&t,sizeof(t),1,p)!=1)
  printf("error de archivo\n");
  salir='s';
  printf("continuar(S/N):?\n");
  scanf("%c",&salir);
} 
fclose(p);
if((p=fopen("pto.dat","rb"))==NULL)
{
  printf("no se puede abrir\n");
  return;
}
t.stock=0;
while(!feof(p))
{
for(i=0;i<4;i++)
t1[i].precio=0;
fread(&t1,sizeof(t1),4,p);
for(i=0;i<4;i++)
{
  printf("%d %f\n",t1[i].codigo,t1[i].precio);
  if(t1[i].stock * t1[i].precio<t.stock*t.precio)
  t=t1[i];
 }
 }
 fclose(p);
 printf("\n el product de mayor valorizacion es %s",t.descripcion);
 }
}
}


