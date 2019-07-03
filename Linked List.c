#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reversePrint(node* head)
{
    node *current=head;
    node *current_p1 = current->next;

    if(current->next=NULL)
    printf("%d\n",current->data);

    else
    {
      while (current_p1->next != NULL)
      {
        current = current->next;
        current_p1 = current->next;
      }

        printf("%d\n", current_p1->data);
        current->next = NULL;
        reversePrint(head);
    }

}



struct node
{
  int value;
  struct node *next;
};

int main()
{
  struct node *A;
  int i;
  A=(struct node*)malloc(4*sizeof(struct node));
  for(i=0;i<4;i++)
  {
    scanf("%d\n",&((A+i).value));
    if(i==3)
    (A+i).next=NULL;
    else
    (A+i).next=&(A+i+1);
  }
  for(i=0;i<4;i++)
  {
    printf("%d ",((A+i).value));
  }

  reversePrint(A  );
  return 0;
}
