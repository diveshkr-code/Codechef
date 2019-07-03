#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int t,n,age,temp,i,j;
  scanf("%d\n",&t );
  for(i=0;i<t;i++)
  {
    scanf("%d ",&n);
    for( j=0;j<(n-1)/2;j++)
    scanf("%d ",&temp);
    scanf("%d ",&age);
    for( j=0;j<(n-1)/2;j++)
    scanf("%d ",&temp);
    scanf("\n");
    printf("Case %d: %d\n",i+1,age);
  }
  return 0;
}
