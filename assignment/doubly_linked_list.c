#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
char page[50];
struct Node *prev;
struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

void insertPage(char page[])
{
struct Node *newNode;

newNode = (struct Node *)malloc(sizeof(struct Node));  

strcpy(newNode->page, page);  

newNode->prev = NULL;  
newNode->next = NULL;  

if(head == NULL)  
{  
    head = tail = newNode;  
}  
else  
{  
    tail->next = newNode;  
    newNode->prev = tail;  
    tail = newNode;  
}  

printf("Page '%s' inserted.\n", page);

}

void displayForward()
{
struct Node *temp = head;

if(head == NULL)  
{  
    printf("No pages available.\n");  
    return;  
}  

printf("Pages from first to last:\n");  

while(temp != NULL)  
{  
    printf("%s", temp->page);  

    if(temp->next != NULL)  
        printf(" <-> ");  

    temp = temp->next;  
}  

printf("\n");

}

void displayBackward()
{
struct Node *temp = tail;

if(tail == NULL)  
{  
    printf("No pages available.\n");  
    return;  
}  

printf("Pages from last to first:\n");  

while(temp != NULL)  
{  
    printf("%s", temp->page);  

    if(temp->prev != NULL)  
        printf(" <-> ");  

    temp = temp->prev;  
}  

printf("\n");

}

void deletePage(char page[])
{
struct Node *temp = head;

while(temp != NULL && strcmp(temp->page, page) != 0)  
{  
    temp = temp->next;  
}  

if(temp == NULL)  
{  
    printf("Page '%s' not found.\n", page);  
    return;  
}  

if(temp == head)  
{  
    head = temp->next;  

    if(head != NULL)  
        head->prev = NULL;  
    else  
        tail = NULL;  
}  
else if(temp == tail)  
{  
    tail = temp->prev;  
    tail->next = NULL;  
}  
else  
{  
    temp->prev->next = temp->next;  
    temp->next->prev = temp->prev;  
}  

free(temp);  

printf("Page '%s' deleted successfully.\n", page);

}

void moveForward(char page[])
{
struct Node *temp = head;

while(temp != NULL)  
{  
    if(strcmp(temp->page, page) == 0)  
    {  
        if(temp->next != NULL)  
            printf("Moving forward to: %s\n",  
                   temp->next->page);  
        else  
            printf("Already at the last page.\n");  

        return;  
    }  

    temp = temp->next;  
}  

printf("Page '%s' not found.\n", page);

}

void moveBackward(char page[])
{
struct Node *temp = head;

while(temp != NULL)  
{  
    if(strcmp(temp->page, page) == 0)  
    {  
        if(temp->prev != NULL)  
            printf("Moving backward to: %s\n",  
                   temp->prev->page);  
        else  
            printf("Already at the first page.\n");  

        return;  
    }  

    temp = temp->next;  
}  

printf("Page '%s' not found.\n", page);

}

int main()
{
int choice;
char page[50];

while(1)  
{  
    printf("\n--- Doubly Linked List ---\n");  
    printf("1. Insert Page\n");  
    printf("2. Move Forward\n");  
    printf("3. Move Backward\n");  
    printf("4. Delete Page\n");  
    printf("5. Display Forward\n");  
    printf("6. Display Backward\n");  
    printf("7. Exit\n");  

    printf("Enter choice: ");  
    scanf("%d", &choice);  

    switch(choice)  
    {  
        case 1:  
            printf("Enter page name: ");  
            scanf("%s", page);  
            insertPage(page);  
            break;  

        case 2:  
            printf("Enter current page: ");  
            scanf("%s", page);  
            moveForward(page);  
            break;  

        case 3:  
            printf("Enter current page: ");  
            scanf("%s", page);  
            moveBackward(page);  
            break;  

        case 4:  
            printf("Enter page to delete: ");  
            scanf("%s", page);  
            deletePage(page);  
            break;  

        case 5:  
            displayForward();  
            break;  

        case 6:  
            displayBackward();  
            break;  

        case 7:  
            exit(0);  

        default:  
            printf("Invalid choice!\n");  
    }  
}  

return 0;

}
