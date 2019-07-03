#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int last_node(char *str)
{
  int position=1;

  for(int i=0;i<strlen(str);i++)
  {
    if(str[i]=='r')
      position+=pow(2,(strlen(str)-i-1));
  }

  long long int last_node;
  if(strlen(str)%2==0)
  {
    last_node=1;
    int no_odd=0;
    for(int i=3;i<=strlen(str);i+=2)
      no_odd+=pow(2,(i-1));
    last_node+=( 2*(no_odd+position) );
  }

  else
  {
    last_node=0;
    int no_even=0;
    for(int i=2;i<=strlen(str);i+=2)
      no_even+=pow(2,(i-1));
    last_node+=( 2*(no_even+position) );
  }


  return last_node%1000000007;
}

int main()
{
  int t;
  char str[100000];
  scanf("%d",&t);
  for(int i=0;i<t;i++)
  {
    scanf("%s",str);
    printf("%d\n",last_node(str));
  }
  return 0;
}
