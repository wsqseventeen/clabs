#include <stdio.h>
#include <string.h>
int day_diff(int year_start, int month_start, int day_start, int year_end, int month_end, int day_end);
int main( int argc, char *argv[] )
{

int *year1;
int year_start;
int *month1;
int month_start;
int *day1;
int day_start;
int *year2;
int year_end;
int *month2;
int month_end;
int *day2;
int day_end;
//   printf("请输入两个时间（参数一时间较早）：%s %s\n", argv[0], argv[1]);
//   printf("第%d个参数为：%s\n", 1 , argv[1] );
//   printf("第%d个参数为：%s\n", 2 , argv[2] );
year1 = strtok(argv[1], "/");
year_start = atoi(year1);
//printf( "%d\n", year_start);

month1 = strtok(NULL, "/");
month_start = atoi(month1);
//printf( "%d\n", month_start );
day1 = strtok(NULL, "/");
day_start = atoi(day1);
//printf( "%d\n", day_start );
year2 = strtok(argv[2], "/");
year_end = atoi(year2);
//printf( "%d\n", year_end);

month2 = strtok(NULL, "/");
month_end = atoi(month2);
//printf( "%d\n", month_end );
day2 = strtok(NULL, "/");
day_end = atoi(day2);
//printf( "%d\n", day_end);
int diff=day_diff( year_start,  month_start,  day_start,  year_end,  month_end,  day_end);
  printf( "%d\n", diff ); 
    return 0;
}
int day_diff(int year_start, int month_start, int day_start, int year_end, int month_end, int day_end)
{
 int y2, m2, d2;
 int y1, m1, d1;
 m1 = (month_start + 9) % 12;
 y1 = year_start - m1/10;
 d1 = 365*y1 + y1/4 - y1/100 + y1/400 + (m1*306 + 5)/10 + (day_start - 1);
// printf( "%d\n", d1 );
 m2 = (month_end + 9) % 12;
 y2 = year_end - m2/10;
 d2 = 365*y2 + y2/4 - y2/100 + y2/400 + (m2*306 + 5)/10 + (day_end - 1);
 //printf( "%d\n", d2 );
 return (d2 - d1 + 1);