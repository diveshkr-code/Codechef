#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void sort_array_des(int *digits,int no_digit)
{
  int temp;

  for(int i=0;i<no_digit-1;i++)
  {
    for(int j=0;j<no_digit-i-1;j++)
    {
      if(digits[j]<digits[j+1])
      {
        temp=digits[j];
        digits[j]=digits[j+1];
        digits[j+1]=temp;
      }
    }
  }

}



int check_win_lose(int x)
{
  int no_digit=0,sum_digits=0,min_oddno=9,min_oddpos=0;
  int temp=x,i;
  do
  {
    no_digit++;
    temp/=10;
  }while(temp>0);

  int digits[no_digit];
  temp=x;
  i=0;

  while(temp)
  {
    digits[i]=temp%10;
    sum_digits+=digits[i];

    if(digits[i]%2  &&  min_oddno>digits[i])
        (min_oddno=digits[i],min_oddpos=i);

    temp/=10;
    i++;
  }



  if(sum_digits%3)
    return -1;

  else
  {
    temp=digits[no_digit-1];
    digits[no_digit-1]=digits[min_oddpos];
    digits[min_oddpos]=temp;

    sort_array_des(digits,no_digit-1);

    int n=0,multiplier=10;
    n+=digits[no_digit-1];
    for(int i=no_digit-2;i>=0;i--,multiplier*=10)
      n+=digits[i]*multiplier;

    return n;
  }

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
    printf("%d\n",check_win_lose(x));
  }
  return 0;
}
