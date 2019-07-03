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
  int t,i,x,y,z;
  scanf("%d\n",&t );
  for(i=0;i<t;i++)
  {
    scanf("%d %d %d\n",&x,&y,&z );
    printf("%d\n",(2*x*z-y*z)/(x+y) );
  }
  return 0;
}
