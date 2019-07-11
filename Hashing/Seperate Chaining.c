#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOAD_FACTOR 5

//All the data structures
typedef struct Listnode Listnode;
typedef struct HashTableNode HashTableNode;
typedef struct HashTable HashTable;

struct Listnode
{
  int key;
  int data;
  Listnode *next;
};

struct HashTableNode
{
  int b_count;                    //number of elements in the block
  Listnode *next;                 //the next pointer will point to the head of Singly Linked List if non-empty else  NULL
};

struct HashTable
{
  int t_size;                       // no of index(block) in the hash table
  int count;                        // no of elements in table
  HashTableNode **Table;     // array of pointers to corresponding chains
};

//Hash Function
int Hash(int key,int t_size)
{
  return key%t_size;
}


HashTable *create_HashTable(int size)
{
  HashTable *h;
  h=(HashTable*)malloc(sizeof(HashTable));
  if(!h)
  {
    printf("Memory Error\n");
    return NULL;
  }

  h->count=0;
  h->t_size=size/LOAD_FACTOR ;
  h->Table=(HashTableNode**)malloc(sizeof(HashTableNode*)*(h->t_size));
  if(!h->Table)
    {
      printf("Memory Error\n");
      return NULL;
    }

  for(int i=0;i<h->t_size;i++)
  {
    h->Table[i]=(HashTableNode*)malloc(sizeof(HashTableNode));            //when dynamically allocting a 2-D arry with array of pointers the for
    //pinter in the array you have to dynamically allocate memory refer :https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/.
    h->Table[i]->next=NULL;
    h->Table[i]->b_count=0;
  }
  return h;
}

void Rehash(HashTable **h)
{
  HashTable *newHash=*h;
  int oldsize,i,index;
  Listnode *temp,*temp2,*p;
  HashTableNode **oldTable;
  oldsize=newHash->t_size;
  oldTable=newHash->Table;
  newHash->t_size=newHash->t_size*2;
  newHash->count=newHash->count+1;

  newHash->Table=(HashTableNode**)malloc(sizeof(HashTableNode)*newHash  ->t_size);
  if(!newHash->Table)
  {
    printf("Memory Error\n");
    return;
  }
  for(int i=0;i<newHash->t_size;i++)
    newHash->Table[i]=(HashTableNode*)malloc(sizeof(HashTableNode));


  for(int i=0;i<oldsize;i++)
  {
    for(temp=oldTable[i]->next;temp;temp=temp->next)
    {
      index=Hash(temp->key,newHash->t_size);
      temp2=temp;
      temp=temp->next;
      temp2->next=newHash->Table[index]->next;
      newHash->Table[index]->next=temp2;
    }
  }
  h=&newHash;
}


int HashSearch(HashTable *h,int key)
{
  Listnode *temp;
  temp=( h->Table[Hash(key,h->t_size)] )->next;
  while (temp)
  {
    if(temp->key==key)
      return 1;                                     //found it
    temp=temp->next;
  }
  return 0;
}

int HashInsert(HashTable *h,int key,int data)
{
  int index;
  Listnode *temp,*new_node;
  if(HashSearch(h,key))
    return 0;


  if((h->count+1)/h->t_size > LOAD_FACTOR)
    Rehash(&h);

  index=Hash(key,h->t_size);
  temp=h->Table[index]->next;
  new_node=(Listnode*)malloc(sizeof(Listnode));
  if(!new_node)
  {
    printf("Out of Space\n" );
    return -1;
  }
  new_node->data=data;
  new_node->key=key;
  new_node->next=temp;
  h->Table[index]->next=new_node;
  h->Table[index]->b_count++;
  h->count++;

  return 1;
}

int HashDelete(HashTable *h,int key)
{
  int index;
  Listnode *temp,*prev;
  index=Hash(key,h->t_size);

  for( temp=h->Table[index]->next, prev=NULL ; temp ;prev=temp , temp=temp->next)
  {
    if(temp->key==key)
    {
      if(prev)
        prev->next=temp->next;
      else
        h->Table[index]->next=NULL;
      free(temp);
      h->Table[index]->b_count--;
      h->count--;
      return 1;
    }
  }

  return 0;
}

void print_hash_table(HashTable *h)
{
  if(!h)
    printf("Nothing to print\n" );

  else
  {
    printf("Start of Hash\n" );
    for(int i=0;i<h->t_size;i++)
    {

      for(Listnode *temp=h->Table[i]->next ; temp ; temp=temp->next)
      {
        printf("%d ",temp->data);

      }
      printf("\n");
    }
    printf("End of Hash Table\n");
  }

}


int main()
{
  int size;
  printf("How many numbers will be there in hash table\n");
  scanf("%d",&size);
  HashTable *h=create_HashTable(size);

  int flag=1;
  int data,key;
  do
  {
    printf("Enter the data that you want to add a Space and the key assiciated with it\n");
    scanf("%d %d",&data,&key);

    HashInsert(h,key,data);

    printf("Enter 1 if you want to add more data\n");
    scanf("%d",&flag);
  }while (flag==1);
  print_hash_table(h);

//deleting hash table and then printing it
  int delflag=0;                      // 0:no deleting
  printf("Enter 1 if you want to delete elements from hash table\n");
  scanf("%d",&delflag);
  while (delflag==1)
  {
    printf("Enter the key of the element that you want to delete\n");
    scanf("%d",&key);
    HashDelete(h,key);
    printf("Do you want to delete more entre 1 if yes\n");
    scanf("%d",&delflag);
  }

  print_hash_table(h);

  return 0;
}
