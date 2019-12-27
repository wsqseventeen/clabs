#include <stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
int a[100];
int m=1;
int x=0;
for(m=1;m<argc;m++,x++)
{
     a[x]=atof(argv[m]);
}
    int i ;
    int min=a[0];
     for(i=0;i<argc;i++)
     {
if(a[i]<min){
min=a[i];
 }
     }
printf("%d\n",min);
}