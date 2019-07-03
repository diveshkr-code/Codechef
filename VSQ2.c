#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


 long long factorial(int n)
{
   long long fact_n=1;
  while (n>0)
  {
    fact_n*=n;
    n--;
  }
  return fact_n;
}

 long long derrangemt(int n)
{
   long long no_ways=0;
  int length=n,multiplier=1;
  for(int i=0;i<=length+1;i++,multiplier*=-1)
  {
    no_ways+=(factorial(n)*multiplier)/factorial(i);
  }
  return no_ways;
}

int main()
{
  int t,n;
  long long no_ways;
  scanf("%d",&t);
  for(int i=0;i<t;i++)
  {
    scanf("%d",&n);
    no_ways=derrangemt(n);
    printf("%llu\n",no_ways%1000000007);
  }
  return 0;
}
