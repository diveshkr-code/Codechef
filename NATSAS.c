#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_win_lose(int x)
{
  int no_digit=0,sum_digits=0;
  int temp=x,i;
  do
  {
    no_digit++;
    temp/=10;
  }while(temp>0)

  int digits[no_digit];
  temp=x;
  i=0

  while(temp)
  {
    digits[i]=temp%10;
    sum+=digits[i];
    temp/=10;
    i++;
  }


  if(sum_digits%3)
    return -1;




}

int main()
{
  int t;
  scanf("%d",&t);
  int n,x;
  for(int i=0;i<t;i++)
  {
    scanf("%d",&x);

  }
  return 0;
}
