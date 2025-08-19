#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 5
#define MAX_MESSAGE 100

typedef char Data[MAX_MESSAGE];
char message[MAX_MESSAGE];

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
void Peek(Queue *ptr, char *outBuffer);
void Enqueue(Queue *ptr, char *message);
void Dequeue(Queue *ptr);

/*Main point of the program*/
int main()
{
  Queue q;
  InitQueue(&q); /*This will set both front and rear to zero*/

  /*Case 1: full enqueue*/
  Enqueue(&q, "This is the first message");
  Enqueue(&q, "This is the second message");
  Enqueue(&q, "This is the third message");
  Enqueue(&q, "This is the fourth message");
  // Enqueue(&q, "This is the fifth message");

    for (int i = 0; i < MAX_QUEUE_SIZE - 1; i++)
  {
    printf("%s\n", q.items[i]);
  }

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
  return (ptr->rear + 1) % MAX_QUEUE_SIZE == ptr->front;
}

void Peek(Queue *ptr, char *outBuffer)
{
  if (IsEmpty(ptr))
  {
    printf("The queue is empty\n");
    exit(1);
  }

  strcpy(outBuffer, ptr->items[ptr->front]);
}

void Enqueue(Queue *ptr, char *message)
{
  if (IsFull(ptr))
  {
    printf("The queue is full\n");
    exit(1);
  }

  strcpy(ptr->items[ptr->rear], message);
  ptr->rear = (ptr->rear + 1) % MAX_QUEUE_SIZE;
}

void Dequeue(Queue *ptr)
{
  if (IsEmpty(ptr))
  {
    printf("The queue is empty\n");
    exit(1);
  }

  ptr->front = (ptr->front + 1) % MAX_QUEUE_SIZE;
}
