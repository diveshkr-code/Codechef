#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a_odd=0,a_even=0;
int b_odd=0,b_even=0;

long max_height_children(int *a,int *b,int n)
{
  int no_loss = ((a_odd > b_odd)?b_odd:a_odd) + ((a_even > b_even)?b_even:a_even);
  int loss=n-no_loss;
  long sum=0;
  for(int i=0;i<n;i++)
    sum+=a[i]+b[i];

  return (sum/2) - (loss/2);
}


int main()
{
  int t,n;
  scanf("%d",&t );
  for(int i=0;i<t;i++)
  {
    a_odd=0,a_even=0;
    b_odd=0,b_even=0;

    scanf("%d",&n);
    int a[n],b[n];

    for (int i = 0; i < n; i++)
    {
      scanf("%d ",&a[i]);
      if(a[i]%2)
        a_odd++;
      else
        a_even++;
    }
    scanf("\n" );
    for (int i = 0; i < n; i++)
    {
      scanf("%d ",&b[i]);
      if(b[i]%2)
        b_odd++;
      else
        b_even++;
    }

    printf("%ld\n",max_height_children(a,b,n));
  }
  return 0;
}
