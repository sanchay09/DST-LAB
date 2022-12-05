#include<stdio.h>
# define MAX 5

int cqueue_arr[MAX];
int front = -1;
int rear = -1;

void insert(int item) {
    if((front == 0 && rear == MAX-1) || (front == rear+1))
    {
        printf("OVERFLOW");
        return;
    }

    if(front == -1)
        {
            front = 0;
            rear = 0;
        }

    else
        {
            if(rear == MAX-1)
            rear = 0;

            else
            rear = rear+1;
        }

    cqueue_arr[rear] = item ;
}

void delete() {
    if(front == -1)
        {
            printf("UNDERFLOW");
            return ;
        }

    printf("Element deleted from queue is : %d\n",cqueue_arr[front]);

    if(front == rear)
        {
            front = -1;
            rear=-1;
        }
    else
        {
            if(front == MAX-1)
            front = 0;

            else
            front = front+1;
        }
}

void display()
{
        if(front == -1)
        {
            printf("Queue is empty\n");
            return;
        }

        else
        {
            int i;
            printf("\nQueue elements are:\n");

            for(i=front; i<=rear; i++)
            printf("%d\n",cqueue_arr[i]);
        }
}

int main()
{
    int choice,item;

    do
        {
            printf("1.Insert\n");
            printf("2.Delete\n");
            printf("3.Display\n");
            printf("4.Exit\n\n");
            printf("Enter your choice : ");
            scanf("%d",&choice);

    switch(choice)
        {
            case 1: printf("\nInput the element for insertion in queue : ");
                    scanf("%d", &item);
                    insert(item);
                    break;

            case 2: delete();
                    break;

            case 3: display();
                    break;

            case 4: break;

            default: printf("Wrong choice\n");
        }

        }

    while(choice!=4);
    return 0;
}
