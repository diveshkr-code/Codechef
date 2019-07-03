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
  int t,i,j;
  scanf("%d\n",&t );
  for(i=0;i<t;i++)
  {
    float n;
    scanf("\n%f\n",&n);
    float c[(int)n],a_0,a_np1;
    scanf("%f\n",&a_0);
    scanf("%f\n",&a_np1);

    float sum_1=0;

    for(i=0;i<n;i++)
    {
      scanf("%f\n",&c[i]);

      sum_1+=(2*c[i]*(n-i));

    }

    float t;

    t=(a_np1-a_0-sum_1)/(n+1);

    float a_1 = a_0+t;
    printf("%.2f\n\n",a_1);

  }

  return 0;
}
