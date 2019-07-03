#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node node;

struct node
{
  int data;
  struct node* prev;
  struct node* next;
};




node* create_doubly_linklist()
{
  node *head,*curr,*prev;

  curr=(node*)malloc(sizeof(node));

  int index=1;              //that means more elements are to be added
  scanf("%d",&curr->data);
  curr->prev=NULL;
  curr->next=NULL;
  head=curr;

  printf("Enter 1 if you want to add more\n");
  scanf("%d",&index);

  while(index==1)
  {
    prev=curr;
    curr=(node*)malloc(sizeof(node));
    prev->next=curr;
    curr->prev=prev;
    curr->next=NULL;
    printf("Enter value for next element\n");
    scanf("%d",&curr->data );

    printf("Enter 1 if you want to add more\n");
    scanf("%d",&index);
  }
  return head;
}


void print_DoublyLinkList(node *head)
{
  node *curr=head;
  while(curr)
  {
    printf("%d ",curr->data );
    curr=curr->next;
  }
}


void insert_element_begin(node **head,int data)
{
  node *new_node,*head_prev=*head;
  new_node=(node*)malloc(sizeof(node));
  new_node->next=head_prev;
  new_node->prev=NULL;
  new_node->data=data;

  head_prev->prev=new_node;

  *head=new_node;
}


void insert_element_middle(node *head,int data,int position)
{
  node *new_node,*curr=head;
  new_node=(node*)malloc(sizeof(node));
  new_node->data=data;

  while (position>0)
  {
    curr=curr->next;
    position--;
  }

  (curr->prev)->next=new_node;
  new_node->prev=curr->prev;
  new_node->next=curr;
  curr->prev=new_node;

}

int main()
{
  node *head=create_doubly_linklist();\
  print_DoublyLinkList(head);

  int data,position;
  printf("Enter value of the new and position\n");
  scanf("%d\n%d",&data,&position);
  insert_element_middle(head,data,position);

  print_DoublyLinkList(head);

  return 0;
}
