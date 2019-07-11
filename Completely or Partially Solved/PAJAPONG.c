#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void who_will_serve(long int x,long int y,long int k)
{
  int residual=(x+y)%k;
  /*
  if(residual== k-1 )
  {
    if( ((x+y)/k) % 2)
      printf("Chef\n");
    else
      printf("Paja\n" );
  }
  else
  {*/
    if( ((x+y)/k) % 2 == 0)
      printf("Chef\n");
    else
      printf("Paja\n" );
  //}
}

int main()
{
  int t;
  long int x,y,k;
  scanf("%d",&t);
  for(int i=0;i<t;i++)
  {
    scanf("%ld %ld %ld",&x,&y,&k);
    who_will_serve(x,y,k);
  }
  return 0;
}
