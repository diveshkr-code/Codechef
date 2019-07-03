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
  unsigned long long int n,m;
  int i,no_disks[3];
  while(scanf("%llu %llu",&n,&m)  !=  "0 0")
  {
    i=1;
    no_disks[0]=n;
    no_disks[1]=0;
    no_disks[2]=0;
    for(i=2;i<=m;i+=2)
    {

      if(no_disks[1]==0)
      {
        no_disks[1]=1;
        no_disks[0]--;
      }

      else
      {
        no_disks[1]--;
        no_disks[0]++;
      }
    }

  }
  return 0;
}
