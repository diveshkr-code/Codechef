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

void print_LinkList(node* head)
{
  node *curr=head;

  if(curr==NULL)
    printf("List is empty\n");

  while(curr)
  {
    printf("%d  ",curr->data );
    curr=curr->next;
  }
  printf("\n");
}

void delete_LinkList(node** head)
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

void sorted_insert(node **head,int value)
{

  node *curr=*head,*new_node,*prev;
  new_node=(node*)malloc(sizeof(node));
  new_node->data=value;

  if(*head==NULL)
    *head=new_node;

  if(curr->data > value)
  {
    new_node->next=curr;
    *head=new_node;
  }
  else
  {
    prev=curr;
    curr=curr->next;
    while (curr->next)
    {
      if(value < curr->data)
      {
        new_node->next=curr;
        prev->next=new_node;
        break;
      }
      curr=curr->next;
      prev=prev->next;
    }

  }

}

int hashf(int key)
{
  return key%10;
}

void insert_in_hash_table(node *hash[],int key)
{
  node *head=*hash;
  int index=hashf(key);
  sorted_insert((head[index]),key);
}

void print_hash_table(node **hash)
{
  node *head=*hash;
  for(int i=0;i<10;i++)
  {
    print_LinkList(head+i);
  }
}



int main()
{
  node *hash[10];
  for(int i=0;i<10;i++)
    hash[i]=NULL;                 //initailizing hash table

  insert_in_hash_table(hash,12);
  insert_in_hash_table(hash,22);
  insert_in_hash_table(hash,2);

  print_hash_table(hash);

  return 0;
}
