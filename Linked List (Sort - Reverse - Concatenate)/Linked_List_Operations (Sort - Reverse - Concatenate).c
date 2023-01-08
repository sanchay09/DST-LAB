#include<stdio.h>
#include<stdlib.h>

struct node
{
        int info;
        struct node *link;
};

struct node* start = NULL;
struct node *create(struct node *start);
struct node *insert_s(struct node *start,int data);
struct node *insert(struct node *start,int data);

void display(struct node *start );
void merge(struct node *p1,struct node *p2);

void merge(struct node *p1,struct node *p2)
{
        struct node *start3;
        start3=NULL;

        while(p1!=NULL && p2!=NULL)
        {
                if(p1->info < p2->info)
                {
                        start3=insert(start3,p1->info);
                        p1=p1->link;
                }
                else if(p2->info < p1->info)
                {
                        start3=insert(start3,p2->info);
                        p2=p2->link;
                }
                else if(p1->info==p2->info)
                {
                        start3=insert(start3,p1->info);
                        p1=p1->link;
                        p2=p2->link;
                }
        }
        /*If second list has finished and elements left in first list*/
        while(p1!=NULL)
        {
                start3=insert(start3,p1->info);
                p1=p1->link;
        }
        /*If first list has finished and elements left in second list*/
        while(p2!=NULL)
        {
                start3=insert(start3,p2->info);
                p2=p2->link;
        }
        printf("Merged list is : ");
        display(start3);
}

struct node *create(struct node *start )
{
        int i,n,data;
        printf("Enter the number of nodes : ");
        scanf("%d",&n);
        start=NULL;
        for(i=1;i<=n;i++)
        {
                printf("Enter the element to be inserted : ");
                scanf("%d",&data);
                start=insert_s(start, data);
        }
        return start;
}/*End of create_slist()*/

struct node *insert_s(struct node *start,int data)
{
        struct node *p,*tmp;
        tmp=(struct node *)malloc(sizeof(struct node));
        tmp->info=data;
        /*list empty or data to be added in beginning */
        if(start==NULL || data<start->info)
        {
                tmp->link=start;
                start=tmp;
                return start;
        }
        else
        {
                p=start;
                while(p->link!=NULL && p->link->info < data)
                        p=p->link;
                tmp->link=p->link;
                p->link=tmp;
        }
        return start;
}/*End of insert_s()*/

struct node *insert(struct node *start,int data)
{
        struct node *p,*tmp;
        tmp=(struct node *)malloc(sizeof(struct node));
        tmp->info=data;
        /*If list is empty*/
        if(start==NULL)
        {
                tmp->link=start;
                start=tmp;
                return start;
        }
        else    /*Insert at the end of the list*/
        {
                p=start;
                while(p->link!=NULL)
                        p=p->link;
                tmp->link=p->link;
                p->link=tmp;
        }
        return start;
}/*End of insert()*/

void display(struct node *start)
{
        struct node *p;
        if(start==NULL)
        {
                printf("List is empty\n");
                return;
        }
        p=start;
        while(p!=NULL)
        {
                printf("%d ",p->info);
                p=p->link;
        }
        printf("\n");
}/*End of display()*/

//sort the List
void sort()
{
    struct node* current = start;
    struct node* index = NULL;
    int temp;
  
    // If LL is empty
    if (start == NULL) {
        return;
    }
  
    // Else
    else {
  
        // Traverse the LL
        while (current != NULL) {
            index = current->link;
  
            // Traverse the LL nestedly
            // and find the minimum
            // element
            while (index != NULL) {
  
                // Swap with it the value
                // at current
                if (current->info > index->info) {
                    temp = current->info;
                    current->info = index->info;
                    index->info = temp;
                }
                index = index->link;
            }
  
            // Update the current
            current = current->link;
        }
    }
}

// Function to reverse the linked list
void reverseLL()
{
    struct node *t1, *t2, *temp;
    t1 = t2 = NULL;
  
    // If LL is empty
    if (start == NULL)
        printf("List is empty\n");
  
    // Else
    else {
  
        // Traverse the LL
        while (start != NULL) {
  
            // reversing of points
            t2 = start->link;
            start->link = t1;
            t1 = start;
            start = t2;
        }
        start = t1;
  
        // New head Node
        temp = start;
  
        printf("Reversed linked list is : ");
  
        // Print the LL
        while (temp != NULL) {
            printf("%d ", temp->info);
            temp = temp->link;
        }
    }
}
  
// Function to insert at the front
// of the linked list
void insertAtFront()
{
    int data;
    struct node* temp;
    temp = malloc(sizeof(struct node));
    printf("\nEnter number to be inserted : ");
    scanf("%d", &data);
    temp->info = data;
  
    // Pointer of temp will be
    // assigned to start
    temp->link = start;
    start = temp;
}
  
// Function to insert at the end of
// the linked list
void insertAtEnd()
{
    int data;
    struct node *temp, *head;
    temp = malloc(sizeof(struct node));
  
    // Enter the number
    printf("\nEnter number to be inserted : ");
    scanf("%d", &data);
  
    // Changes links
    temp->link = 0;
    temp->info = data;
    head = start;
    while (head->link != NULL) {
        head = head->link;
    }
    head->link = temp;
}
  
// Function to insert at any specified
// position in the linked list
void insertAtPosition()
{
    struct node *temp, *newnode;
    int pos, data, i = 1;
    newnode = malloc(sizeof(struct node));
  
    // Enter the position and data
    printf("\nEnter position and data :");
    scanf("%d %d", &pos, &data);
  
    // Change Links
    temp = start;
    newnode->info = data;
    newnode->link = 0;
    while (i < pos - 1) {
        temp = temp->link;
        i++;
    }
    newnode->link = temp->link;
    temp->link = newnode;
}

// Function to traverse the linked list
void traverse()
{
    struct node* temp;
  
    // List is empty
    if (start == NULL)
        printf("\nList is empty\n");
  
    // Else print the LL
    else {
        temp = start;
        while (temp != NULL) {
            printf("Data = %d\n", temp->info);
            temp = temp->link;
        }
    }
}

int main()
{
    int choice;
    struct node *start1=NULL,*start2=NULL;

    while (1) {
  
        printf("\n1. Display List\n");
        printf("2. Insert At First Position\n");
        printf("3. Insert At Last Position\n");
        printf("4. Insert At Any Position\n");
        printf("5. Sort The List\n");
        printf("6. Reverse the list\n");
        printf("7. Concatenate 2 Linked Lists\n");
        printf("8. To exit\n");
        printf("\nEnter Choice: \n");
        scanf("%d", &choice);
  
        switch (choice) {
        case 1:
            traverse();
            break;
        case 2:
            insertAtFront();
            break;
        case 3:
            insertAtEnd();
            break;
        case 4:
            insertAtPosition();
            break;
        case 5:
            sort();
            break;
        case 6:
            reverseLL();
            break;
        case 7:
            start1=create(start1);
            start2=create(start2);
            printf("List1 : ");
            display(start1);
            printf("List2 : ");
            display(start2);
            merge(start1, start2);
            break;
            
        case 8:
            exit(1);
            break;
            
        default:
            printf("Incorrect Choice\n");
        }
    }
    return 0;
}