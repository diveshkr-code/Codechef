#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max_profit(int *a,int*b,int n,int k)
{
  int max=0,no_stones;
  for(int i=0;i<n;i++)
  {
    no_stones=k/(*(a+i));
    if(max < no_stones*(*(b+i)) )
      max=no_stones*(*(b+i));
  }
  return max;
}

int main()
{
  int t;
  int n,k;
  scanf("%d\n",&t );

  for(int i=0;i<t;i++)
  {
    scanf("%d %d",&n,&k);
    int a[n],b[n];

    for(int j=0;j<n;j++)
      scanf("%d ",&a[j] );
    scanf("\n" );

    for(int j=0;j<n;j++)
      scanf("%d ",&b[j] );
    scanf("\n" );

    printf("%d\n",max_profit(a,b,n,k));
  }
  return 0;
}
