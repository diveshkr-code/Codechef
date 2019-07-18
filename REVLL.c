#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list list;
struct list
{
  int data;
  list *next;
};

void check_if_empty(list *head)
{
  if(!head)
    printf("true\n");
  else
    printf("false\n");
}

int main()
{

  return 0;
}
