#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{

  unsigned int x,y;
  while(scanf("%u",&x) != EOF)
  {
    scanf("%u",&y);
    int ans[32],i;

    for( i=0;i<32;i++)
    {
      ans[i]=0;
      if( ((x%2)*(y%2)==0)  &&  ((x%2)+(y%2)==1))
      ans[i]=1;
      x=x>>1;
      y=y>>1;
    }

    int ans_dec=0;

    for(i=0;i<31;i++)
    {
      if(ans[i])
      {
        ans_dec+=(pow(2,i));
      }
    }

    /*if(ans[31]==1)
    printf("-");*/
    printf("%d\n",ans_dec);
  }
  return 0;
}
