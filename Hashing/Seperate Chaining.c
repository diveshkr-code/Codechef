#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOAD_FACTOR 10

typedef struct Listnode Listnode;
typedef struct HashTableNode HashTableNode;
typedef struct HashTable HashTable;

struct Listnode
{
  int key;
  int data;
  struct Listnode *next;
};

struct HashTableNode
{
  int b_count;                    //number of elements in the block
  struct HashTableNode *next;
};

struct HashTable
{
  int t_size;                       // no of index(block) in the hash table
  int count;                        // no of elements in table
  struct HashTableNode **Table;     // array of pointers to corresponding chains
};


void Rehash(HashTable *h)
{
  printf("This facility isn't available right now\n" );
}

HashTable *create_HashTable(int size)
{
  HashTable *h;
  h=(HashTable*)malloc(sizeof(HashTable));
  if(!h)
    return NULL;

  h->t_size=size/LOAD_FACTOR;
  h->count=0;
  h->Table=(HashTable**)malloc(sizeof(HashTable*)*h->t_size);

  if(!h->Table)
  {
    printf("Memory Error\n");
    return NULL;
  }

  for(int i=0;i<h->t_size;i++)
  {
    h->Table[i]->next=NULL;
    h->Table[i]->b_count=0;
  }

  return h;
}

int HashSearch(HashTable *h,int data)
{
  Listnode *temp;
  temp=h->Table[Hash(data,h->t_size)]->next;
  while (temp)
  {
    if(temp->data==data)
      return 1;                                     //found it
    temp=temp->next;
  }
  return 0;
}

int HashInsert(HashTable *h,int data)
{
  int index;
  Listnode *temp,*new_node;
  if(HashSearch(h,data))
    return 0;

  index=Hash(data,h->t_size);
  temp=h->Table[index]->next;
  new_node=(Listnode*)malloc(sizeof(Listnode));
  if(!new_node)
  {
    printf("Out of Space\n" );
    return -1;
  }
  new_node->data=data;
  new_node->key=index;
  new_node->next=temp;
  h->Table[index]->next=new_node;
  h->Table[index]->b_count++;
  h->count++;

  if(h->count/h->t_size > LOAD_FACTOR)
    Rehash(h);
    return 1;
}

int HashDelete(HashTable *h,int data)
{
  int index;
  Listnode *temp,*prev;
  index=Hash(data,h->t_size);

  for( temp=temp=h->Table[index]->next, prev=NULL ; temp ;prev=temp , temp=temp->next)
  {
    if(temp->data==data)
    {
      if(prev)
        prev->next=temp->next;
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
    for(int i=0;i<h->t_size;i++)
    {

      for(Listnode *temp=h->Table[i]->next ; temp ; temp=temp->next)
      {
        printf("%d ",temp->data);

      }
      printf("\n");
    }
  }

}
int Hash(int data,int t_size)
{
  return data%t_size;
}


int main()
{
  int size;
  printf("How many numbers will be there in hash table\n");
  scanf("%d",&size);
  HashTable *hash=create_HashTable(size);

  int flag=1,int data;
  do
  {
    printf("Enter the data that you want to add\n");
    scanf("%d",&data);

    HashInsert(Hash,data);

    printf("Enter 1 if you want to add more data\n");
    scanf("%d",&flag);
  }while (flag==1);

  print_hash_table(hash);

  return 0;
}
