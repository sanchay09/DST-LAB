/*WAP to Implement doubly link list with primitive operations:
a) Create a doubly linked list.
b) Insert a new node to the left of the node.
c) Delete the node based on a specific value
d) Display the contents of the list
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *prev, *next;
};

struct node* start = NULL;

void insertFront()
{
    int data;

    struct node* temp;

    temp=(struct node*)malloc(sizeof(struct node));

    printf("Enter Number to be inserted: ");
    scanf("%d",&data);

    temp->info = data;
    temp->prev = NULL;

    temp->next = start;
    start = temp;
}

void insertEnd()
{
    int data;
    struct node *temp, *trav;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("Enter the Number to be inserted: ");
    scanf("%d", &data);
    temp->info=data;
    temp->next=NULL;
    trav=start;

    if (start == NULL)
    {
         start = temp;
    }

    else
    {
        while (trav->next != NULL)
        trav = trav->next;
        temp->prev = trav;
        trav->next = temp;
    }
}

void insertPosition()
{
    int data, pos, i=1;
    struct node *temp, *newnode;

    newnode = malloc(sizeof(struct node));
    newnode->prev = NULL;
    newnode->next = NULL;

    printf("Enter position: ");
    scanf("%d", &pos);

     if (start == NULL) {
        start = newnode;
        newnode->prev = NULL;
        newnode->next = NULL;
    }

    else if (pos == 1)
    {
        insertFront();
    }

    else
    {
        printf("\nEnter number to be inserted: ");
        scanf("%d", &data);
        newnode->info = data;
        temp = start;

        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }

        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;
        temp->next->prev = newnode;
    }
}

void deleteFirst()
{
    struct node* temp;

    if (start == NULL)
        printf("\nList is empty\n");

    else
    {
        temp = start;
        start = start->next;
        if (start != NULL)
        start->prev = NULL;

        free(temp);
    }
}

void deleteEnd()
{
    struct node* temp;
    if (start == NULL)
        printf("\nList is empty\n");
    temp = start;
    while (temp->next != NULL)
        temp = temp->next;
    if (start->next == NULL)
        start = NULL;
    else {
        temp->prev->next = NULL;
        free(temp);
    }
}

void deletePosition()
{
    int pos, i = 1;
    struct node *temp, *position;
    temp = start;

    if (start == NULL)
        printf("\nList is empty\n");

    else
    {
        printf("\nEnter position : ");
        scanf("%d", &pos);

        if (pos == 1)
        {
            deleteFirst();

            if (start != NULL)
            {
                start->prev = NULL;
            }

            free(position);
            return;
        }

        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }

        position = temp->next;
        if (position->next != NULL)
            position->next->prev = temp;

        temp->next = position->next;

        free(position);
    }
}

void traverse()
{
    if (start == NULL)
    {
        printf("\nList is empty\n");
        return;
    }

    struct node* temp;
    temp = start;

    while (temp != NULL)
    {
        printf("Data = %d\n", temp->info);
        temp = temp->next;
    }
}

int main()
{
        printf("\n1. Display List\n");
        printf("2. Insert At Front\n");
        printf("3. Insert At End\n");
        printf("4. Insert At Position\n");
        printf("5. Delete First Element\n");
        printf("6. Delete Last Element\n");
        printf("7. Delete From Any Position\n");
        printf("8. Exit\n");

        while (1)
        {
            int choice;
            printf("\nEnter Choice: \n");
            scanf("%d", &choice);

        switch (choice)
        {
        case 1: traverse();
                break;

        case 2: insertFront();
                break;

        case 3: insertEnd();
                break;

        case 4: insertPosition();
                break;

        case 5: deleteFirst();
                break;

        case 6: deleteEnd();
                break;

        case 7: deletePosition();
                break;

        case 8: exit(1);
                break;

        default: printf("Incorrect Choice. Try Again \n");
        }
    }
    return 0;
}
