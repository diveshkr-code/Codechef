#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cir_node cir_node;

struct cir_node
{
  int data;
  cir_node *next;
};

void print_cirLinkList(cir_node *head)
{
  cir_node *curr=head;

  if(curr==NULL)
    printf("List is empty\n");

  while(curr)
  {
    printf("%d  ",curr->data );
    curr=curr->next;

    if(curr==head)
      break;
  }

}



cir_node* create_cirLinkList()
{
  int flag=1;                 //want to add more elements
  cir_node *head,*curr,*prev;
  head=(cir_node*)malloc(sizeof(cir_node));
  printf("Enter value of head\n" );
  scanf("%d",&head->data);
  prev=head;
  head->next=NULL;

  printf("Enter 1 if you want to add more elements\n" );
  scanf("%d", &flag);

  while(flag==1)
  {
    curr=(cir_node*)malloc(sizeof(cir_node));
    prev->next=curr;

    printf("Enter value of next node\n" );
    scanf("%d",&curr->data);
    curr->next=NULL;
    prev=curr;

    printf("Enter 1 if you want to add more elements\n" );
    scanf("%d", &flag);
  }

  curr->next=head;
  return head;
}

int main()
{
  cir_node *head=create_cirLinkList();
  print_cirLinkList(head);
}
