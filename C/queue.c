#include <stdio.h>
#include <stdlib.h>

struct queue {
  struct queue *next;
  int data;
};


struct queue *init()
{
  struct queue *queue = malloc(sizeof(struct queue));
  queue->next = NULL;
}

void enqueue(struct queue *queue,int elem)
{
  while (queue->next
  queue->next = init();
  queue->next->data = elem;
}

int dequeue (struct queue *queue)
{
  int elem = queue->next

}
