#include <stdio.h>
#include <string.h>

int main( int argc, char *argv[] )
{
  printf("请输入七个数字（以空格隔开）：%s %s %s %s %s %s %s\n", argv[1], argv[2] ,argv[3], argv[4], argv[5], argv[6], argv[7]);	
int *n1_c,*n2_c,*n3_c,*n4_c,*n5_c,*n6_c,*n7_c; 
int n1,n2,n3,n4,n5,n6,n7,min;

n1_c= strtok(argv[1], "/");
n1 = atoi(n1_c);
min=n1;

n2_c= strtok(argv[2], "/");
n2 = atoi(n2_c);
if(n2<min){min=n2;}

n3_c= strtok(argv[3], "/");
n3 = atoi(n3_c);
if(n3<min){min=n3;}

n4_c= strtok(argv[4], "/");
n4 = atoi(n4_c);
if(n4<min){min=n4;}

n5_c= strtok(argv[5], "/");
n5 = atoi(n5_c);
if(n5<min){min=n5;}

n6_c= strtok(argv[6], "/");
n6 = atoi(n6_c);
if(n6<min){min=n6;}

n7_c= strtok(argv[7], "/");
n7 = atoi(n7_c);
if(n7<min){min=n7;}

printf( "%d\n", min);

}