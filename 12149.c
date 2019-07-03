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
  int n,i,ans;
  while (scanf("%d\n",&n) !=   EOF)
  {
    ans=0;
    for ( i = 1; i <= n; i++)
    ans+=(i*i);
    if(ans!=0)
    printf("%d\n", ans);
  }
  return 0;
}
