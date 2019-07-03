#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Rectangle
{
  int length;
  int breath;
};

int main()
{
  struct Rectangle r;
  scanf("%d %d\n",&r.length,&r.breath );
  printf("length %d\nbreath %d\n",r.length,r.breath );
  return 0;
}
