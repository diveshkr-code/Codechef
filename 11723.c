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
  int r,n,i=1;
  while (scanf("%d",&r ) !=  EOF)
  {
    scanf(" %d\n",&n );


    if (r-(27*n)>0)
      printf("Case %d: impossible\n",i);

    else if(n!=0)
    {
      if( ( (r-n)%n ) ==  0 )
        printf("Case %d: %d\n",i,(r-n)/n );
      else if(r>n)
      printf("Case %d: %d\n",i,((r-n)/n+1) );
      else if(r<n)
      printf("Case %d: %d\n",i,((r-n)/n) );
      else
	;
    }

    else
	;

    i++;
  }
  return 0;
}
