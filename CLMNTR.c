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
  int t;
  scanf("%d\n",&t);
  int xs,ys,zs,rs;
  int xa,ya,za,ra;
  int xb,yb,zb,rb;

  scanf("%d\n",&t);
  for(int i=0;i<t;i++)
  {
    scanf("%d %d %d %d\n",&xs,&ys,&zs,&rs);
    scanf("%d %d %d %d\n",&xa,&ya,&za,&ra);
    scanf("%d %d %d %d\n",&xb,&yb,&zb,&rb);

    if( rs==ra && rs==rb )
    {

    }
  }
  return 0;
}
