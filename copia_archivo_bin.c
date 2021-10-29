#include <stdio.h>
#include <stdlib.h>

void main(void)
{
  FILE *p1,p2;
  int c;
  
  if((p1=fopen("archivo2","rb"))==NULL)
  {
  printf("error al abrir el archivo 2\n");
  return;
  }
  
  if((p2=fopen("archivo3","rb"))==NULL)
  {
  printf("error al abrir el archivo 3\n");
  return;
  }
  
  while(!feof(p1))
  {
  c=getc(p1);
  putc(c,p2);
  }
  fclose(p1);
  fclose(p2);

}
