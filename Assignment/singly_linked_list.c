#include <stdio.h>
#include <stdlib.h>

struct Node
{
int roll;
struct Node *next;
};

struct Node *head = NULL;

void display()
{
struct Node *temp = head;

if(head == NULL)  
{  
    printf("List is empty.\n");  
    return;  
}  

printf("List: ");  

while(temp != NULL)  
{  
    printf("%d -> ", temp->roll);  
    temp = temp->next;  
}  

printf("NULL\n");

}

void insertBeginning(int roll)
{
struct Node *newNode;

newNode = (struct Node *)malloc(sizeof(struct Node));  

newNode->roll = roll;  
newNode->next = head;  
head = newNode;  

printf("%d inserted at beginning.\n", roll);  
display();

}

void insertEnd(int roll)
{
struct Node *newNode, *temp;

newNode = (struct Node *)malloc(sizeof(struct Node));  

newNode->roll = roll;  
newNode->next = NULL;  

if(head == NULL)  
{  
    head = newNode;  
}  
else  
{  
    temp = head;  

    while(temp->next != NULL)  
    {  
        temp = temp->next;  
    }  

    temp->next = newNode;  
}  

printf("%d inserted at end.\n", roll);  
display();

}

void search(int roll)
{
struct Node *temp = head;
int position = 1;

while(temp != NULL)  
{  
    if(temp->roll == roll)  
    {  
        printf("Roll number %d found at position %d.\n",  
               roll, position);  
        return;  
    }  

    temp = temp->next;  
    position++;  
}  

printf("Roll number %d not found.\n", roll);

}

void deleteNode(int roll)
{
struct Node *temp = head;
struct Node *prev = NULL;

if(head == NULL)  
{  
    printf("List is empty.\n");  
    return;  
}  

if(head->roll == roll)  
{  
    head = head->next;  
    free(temp);  

    printf("%d deleted successfully.\n", roll);  
    display();  
    return;  
}  

while(temp != NULL && temp->roll != roll)  
{  
    prev = temp;  
    temp = temp->next;  
}  

if(temp == NULL)  
{  
    printf("Roll number %d not found.\n", roll);  
    return;  
}  

prev->next = temp->next;  
free(temp);  

printf("%d deleted successfully.\n", roll);  
display();

}

int main()
{
int choice, roll;

while(1)  
{  
    printf("\n--- Singly Linked List ---\n");  
    printf("1. Insert at Beginning\n");  
    printf("2. Insert at End\n");  
    printf("3. Search\n");  
    printf("4. Delete\n");  
    printf("5. Display\n");  
    printf("6. Exit\n");  

    printf("Enter choice: ");  
    scanf("%d", &choice);  

    switch(choice)  
    {  
        case 1:  
            printf("Enter roll number: ");  
            scanf("%d", &roll);  
            insertBeginning(roll);  
            break;  

        case 2:  
            printf("Enter roll number: ");  
            scanf("%d", &roll);  
            insertEnd(roll);  
            break;  

        case 3:  
            printf("Enter roll number to search: ");  
            scanf("%d", &roll);  
            search(roll);  
            break;  

        case 4:  
            printf("Enter roll number to delete: ");  
            scanf("%d", &roll);  
            deleteNode(roll);  
            break;  

        case 5:  
            display();  
            break;  

        case 6:  
            exit(0);  

        default:  
            printf("Invalid choice!\n");  
    }  
}  

return 0;

}