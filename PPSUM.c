#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum(int d,int n)
{
  for(int i=0;i<d;i++)
    n=(n*(n+1))/2;

  return n;
}

int main()
{
  int t,n,d;
  scanf("%d",&t);

  for(int i=0;i<t;i++)
  {
    scanf("%d %d",&d,&n );
    printf("%d\n",sum(d,n));
  }
  
  return 0;
}
