#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int length=10;


void cycle_length(int n)
{
  if(n != 1)
  {
    length++;
    if(n%2 != 0)
      cycle_length(3*n+1);
    else
      cycle_length(n/2);
  }
}

void swap(int* start,int* end)
{
  int temp=*start;
  *start=*end;
  *end=temp;
}

int main()
{
  int start,end,j,max,flag=0;

  while (scanf("%d ",&start)  !=  EOF)
  {
    flag=0;
    scanf("%d\n",&end );
    max=1;

    if(start>end)
    {
      flag=1;
      swap(&start,&end);
    }

    for( j=start ; j <= end ; j++ )
    {
      length=1;
      cycle_length(j);
      if( length > max)
        max=length;

    }

    if(flag==1)
      swap(&start,&end);

    printf("%d %d %d\n",start,end,max);
  }
  return 0;
}
