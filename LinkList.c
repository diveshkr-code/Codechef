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
  struct node *next;
}*head=NULL;


node* create_LinkList()
{
  node *prev,*head,*curr;
  head=(node*)malloc(sizeof(node));
  curr=head;
  int query=1;
  printf("Enter value of 1st element\n" );
  scanf("%d",&head->data);
  printf("Enter 1 if you you want to add more\n");
  scanf("%d",&query);
  curr->next=NULL;
                  //if query==1 then will continue to add elements else will stop

  while(query==1)
  {
    prev=curr;
    curr=(node*)malloc(sizeof(node));
    prev->next=curr;
    printf("Enter value of next element\n" );
    scanf("%d",&curr->data);
    curr->next=NULL;
    printf("Enter 1 if you you want to add more\n" );
    scanf("%d",&query);
  }
  return head;
}

void print_LinkList(node *head)
{
  node *curr=head;

  if(curr==NULL)
    printf("List is empty\n");

  while(curr)
  {
    printf("%d  ",curr->data );
    curr=curr->next;
  }
}

void delete_LinkList(node **head)
{
  node *iterator,*auxillary;
  iterator=*head;

  while (iterator)
  {
    auxillary=iterator->next;
    free(iterator);
    iterator=auxillary;
  }
  *head=NULL;
}

//revll_pairs() function  will reverse linked list in pairs e.g. 1->2->3->4->NULL will result in 2->1->4->3->NULL
node *revll_pairs(node *head)
{
  node *temp,*curr=head,*link;
  if(!curr)
    temp = NULL;
  else
    temp = curr->next;

  if(!temp)
    return curr ;

  link = revll_pairs(temp->next);
  curr->next = link;
  temp->next = curr;
  return temp;

}


z

int main()
{
  node *head=create_LinkList();
  print_LinkList(head);
  delete_LinkList(&head);
  print_LinkList(head);
  head = revll_pairs(head);
  print_LinkList(head);
  return 0;
}
