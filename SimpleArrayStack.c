#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct ArrayStack ArrayStack;

struct ArrayStack
{
  int capacity;
  int top;
  int *array;
};

ArrayStack *crete_Stack()
{
  ArrayStack *stack = malloc(sizeof(ArrayStack));
  if(!stack)
    return NULL;
  stack->capacity = MAX_SIZE;
  stack->top = -1;
  stack -> array = malloc(sizeof(int)*stack->capacity);
  if(!stack->array)
    return NULL;
  return stack;
}

int isEmpty(ArrayStack *stack)
{
  if(stack->top==-1)
    return 1;                      //0 means that the stack is Empty
  else
    return 0;
}

int isFull(ArrayStack *stack)
{
  return ((stack->capacity)-(stack->top) );           //Anything other than 1 indicates that not full
}
void push(ArrayStack *stack,int data)
{
  if(isFull(stack)==1)
    printf("Stack Overflow\n" );

  else
    stack->array[++(stack->top)]=data;
}

int pop(ArrayStack *stack)
{
  if(stack->top == -1)
  {
    printf("Underflow exception\n");
    return 0;
  }
  int data=stack->array[stack->top];
  stack->array[stack->top--]=0;
  return data;
}

void delete_stack(ArrayStack *stack)
{
  if(stack)
  {
    if(stack->array)
      free(stack->array);
    free(stack);
  }
}

int main()
{
  ArrayStack *stack=crete_Stack();
  if(isEmpty(stack)==1)
    printf("Stack is empty\n");
  int flag=0;           //This means wont be pushing into the Stack
  printf("Enter 1 if you want to fill the stack\n" );
  scanf("%d",&flag);
  if(flag==1)
  {
    for(int i=0;i<MAX_SIZE;i++)
    push(stack,i);
  }

  if(isFull(stack)==1)
    printf("The stack is full now \n");
 typedef ArrayStack ArrayStack;

  for(int i=0;i<MAX_SIZE;i++)
  {
    printf("This has been poped out:%d\n",pop(stack));
  }

  if(isEmpty(stack)==1)
    printf("Stack is empty\n");

  return 0;
}
