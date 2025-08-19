#include <stdbool.h>
#include <stdio.h>
#define MAX_QUEUE_SIZE 100

typedef int Data;


typedef struct 
{
  int front;
  int rear;
  Data items[MAX_QUEUE_SIZE];
} Queue;


/*Function prototype/ function declaration*/
void InitQueue(Queue *ptr);
bool IsEmpty(Queue *ptr);
bool IsFull(Queue *ptr);
Data Peek(Queue *ptr);
void Enqueue(Queue *ptr, Data item);
void Dequeue(Queue *ptr);

/*Main point of the program*/
int main()
{
  printf("%d\n", true);
  printf("%d\n", false);
  return 0;
}

void InitQueue(Queue *ptr)
{
  ptr->front = ptr->rear = 0;
}

bool IsEmpty(Queue *ptr)
{
  return ptr->front == ptr->rear;
}

bool IsFull(Queue *ptr)
{
  return (ptr->rear++) % MAX_QUEUE_SIZE == ptr->front;
}

Data Peek(Queue *ptr)
{
  if (IsEmpty(ptr)) {
    exit(1);
  }
  return ptr->items[ptr->front];
}

void Enqueue(Queue *ptr, Data item)
{
  if (IsFull(ptr)) {
    exit(1);
  }

  ptr->items[ptr->rear] = item;
  ptr->rear = (ptr->rear++) % MAX_QUEUE_SIZE;
}

void Dequeue(Queue *ptr)
{
  if (IsEmpty(ptr))
  {
    exit(1);
  }

  ptr->front = (ptr->front++) % MAX_QUEUE_SIZE;
  
}
