#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SinglyLinkedListNode SinglyLinkedListNode;

struct SinglyLinkedListNode
{
    int data;
    SinglyLinkedListNode* next;
};



SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2)
{
    SinglyLinkedListNode *curr1=head1,*curr2=head2,*curr,*head;

    if(head1==NULL)
        return head2;
    else if(head2==NULL)
        return head1;

/*
    else
    {
        if( head1->data > head2->data )
            head=head2;
        else
            head=head1;

        curr=head;

        while(curr1&&curr2)
        {
          ((curr1->data - curr2->data) > 0 )? (curr->next = curr2,curr2=curr2->next)
                                          : (curr->next = curr1,curr1=curr1->next);
            curr=curr->next;
        }

        if(curr1==NULL)
        {
            while(curr2)
            {
                curr->next=curr2;
                curr2=curr2->next;
                curr=curr->next;
            }
        }
        else
        {
          while (curr1)
          {
            curr->next = curr1;
            curr1 = curr1->next;
          }
            curr = curr->next;
          }
        }

*/
    //return head;

}


void input_linklist(SinglyLinkedListNode *head,int no_ele)
{
  SinglyLinkedListNode *curr=head;
  while(no_ele)
  {
    scanf("%d\n",&curr->data);
    curr->next=curr+1;
    curr=curr->next;
  }
}


void  print_linklist(SinglyLinkedListNode *head)
{
  SinglyLinkedListNode *curr=head;
  while(curr)
  {
    printf("%d ",curr->data );
    curr=curr->next;{

    printf("\n");
  }
}


int main()
{
  SinglyLinkedListNode *a1,*a2,*curr;
  int no_ele1,no_ele2;
  scanf("%d %d", &no_ele1,&no_ele2);
  a1=(SinglyLinkedListNode*)malloc(no_ele1*sizeof( SinglyLinkedListNode ));
  a2=(SinglyLinkedListNode*)malloc(no_ele2*sizeof( SinglyLinkedListNode ));
  input_linklist(a1,no_ele1);
  //input_linklist(a2,no_ele2);


  print_linklist(a1);
  //print_linklist(a2);

  return 0;
}
