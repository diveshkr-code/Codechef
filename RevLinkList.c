#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap_1_2(struct node *var1,struct node *var2)
{
    struct node *temp;
    temp=var1;
    var1=var2;
    var2=temp;
}

struct node *reverse(struct node *head)
{
  struct node *current1;
  struct node *current2;

  current1 = head;
  current2 = head->next;
  head->next = NULL;
  while ( current2 != NULL )
  {
    current2->next = current1;
    current1 = current2->next;
    swap_1_2(current1, current2);
  }

    return current1;
}


struct node
{
  int data ;
  struct node *next;
}*a;


int main()
{
  int n;
  scanf("%d\n",&n);
  a = (struct node*)malloc(n*sizeof(struct node));

  for(int i=0;i<n;i++)
    scanf("%d\n",(a+i)->data );

  reverse(a);

  for(int i=0;i<n;i++)
    printf("%d  ",(a+i)->data);

  return 0;
}
