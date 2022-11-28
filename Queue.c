#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

void enqueue(int);
void dequeue();
void display();

int queue[SIZE], front = -1, rear = -1;

void main()
{
   int value, choice;
   while(1)
    {
      printf("1. Insert\n2. Delete\n3. Display\n4. Exit");
      printf("\nEnter your choice: ");
      scanf("%d",&choice);

      switch(choice)
      {
        case 1: printf("Enter the value to be insert: ");
                scanf("%d",&value);
                enqueue(value);
                break;
        case 2: dequeue();
                break;

        case 3: display();
                break;

        case 4: exit(0);

        default: printf("\nInvalid Input");
      }
   }
}


void enqueue(int value)
{
   if(rear == SIZE-1)
      printf("\nQueue is Full!");

   else
    {
        if(front == -1)
        front = 0;
        rear++;
        queue[rear] = value;
   }
}


void dequeue()
{
        if(front == rear)
        printf("\nQueue is Empty!");

        else
        {
            printf("\nDeleted : %d", queue[front]);
            front++;
        }
}

void display()
{
   if(rear == -1)
      printf("\nQueue is Empty!!!");

   else
    {
      int i;
      printf("\nQueue elements are:\n");
      for(i=front; i<=rear; i++)
	  printf("%d\n",queue[i]);
    }
}
