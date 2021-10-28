#include <stdio.h>
#include <stdlib.h>

int main()
{
int *a,i,c;
printf("\ningrese cuantos elementos desea reservar\n");
fflush(stdin);
scanf("%d",&c);
a=(int *)malloc(sizeof(int));
if(!a)
{
  printf("\nerror en la reserva de memoria");
  return 1;
}
for(i=0;i<c;i++)
a[i]=i+1;
for(i=0;i<c;i++)
printf("%d - ",*a+i);
printf("\n");
return 0;
}
