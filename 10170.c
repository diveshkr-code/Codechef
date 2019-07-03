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
  long S,D;
  int i=0;
  while(scanf("%ld ",&S )  !=  EOF)
  {
    scanf("%ld\n",&D);
    i=0;
    while(D>0)
    {
      D-=(S+i);
      i++;
    }
    printf("%ld\n",(S+i-1));
  }
  return 0;
}
