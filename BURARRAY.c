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
  int t,q,query;
  long n,s=0,q_2,p_2,y_1,max_2;
  scanf("%d",&t);

  for(int i=0;i<t;i++)
  {
    s=0;
    scanf("%ld %d",&n,&q);
    long a[n];

    for(int i=1;i<=n;i++)
      a[i-1]=i;

    for(int i=0;i<q;i++)
    {
      scanf("%d ",&query);

      if(query == 1)
      {
        scanf("%ld\n",&y_1);
        a[s+y_1]=0;
      }

      else if(query == 2)
      {

        scanf("%ld %ld\n",&p_2,&q_2);
        max_2=0;
        for(int i=p_2+s;i<=q_2+s;i++)
          if(a[i-1]>max_2)
            max_2=a[i-1];
        }
        printf("%ld\n",max_2);
        s+=max_2;``
      }

    }

  }
  return 0;
}
