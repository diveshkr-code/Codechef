#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a,int b)
{
  if(a==0)
  return b;

  gcd(b%a,a);
}

int gcd_array(int *a,int n)
{
  int result=a[0];
  for(int i=1;i<n;i++)
    result=gcd(result,a[i]);
  return result;
}

int make_it_odd(int *gcd)
{

  if(gcd%2)
    return gcd;
  else
    {
      gcd/=2;
      make_it_odd(gcd);
    }
}

void check_y_or_n(int *a,int n)
{
  int gcd=gcd_array(a,n);

  if(gcd <= k || gcd==1)
    printf("TRUE\n");

  else
  {
    if(k==1)
      printf("FALSE\n");

    else if(k==2)
    {

    }


  }
}

int main()
{
  int t,n,k;
  scanf("%d",&t );

  for(int i=0;i<t;i++)
  {
    scanf("%d %d",&n,&k);
    int a[n];
    for(int j=0;j<n;j++)
      scanf("%d",&a[j]);

  }
  return 0;
}
