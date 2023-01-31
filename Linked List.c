#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList
{
   char data;
   struct linkedList* nextNode;   
}ListNode;

char instructions (void);
void insert (ListNode** , char);
char delete (ListNode** , char);
void printList(ListNode* );
int isEmpty(ListNode* );

int  main(void)
{
    ListNode* startList = NULL;

    int choice;
    char item;

    while ((choice = instructions()) != 3)
    {
        switch (choice)
        {
        case 1:
            printf("Enter a character: ");
            scanf("\n%c", &item);
            insert(&startList, item);
            printList(startList);        
        break;
        
        case 2: 
            if(!isEmpty(startList))
            {
                printf("Enter a character to be removed: ");
                scanf("\n%c", &item);

                if (delete(&startList, item))
                {
                    printf("%c deleted.\n", item);
                    printList(startList);
                } else {
                    printf("%c was not found.\n", item);
                }
                
            } else {
                printf("Empty List.\n\n");
            }
                        
        break;

        default:
            break;
        }
    }    

    return 0;
}

char instructions (void)
{
    int choice;

    printf("Enter your choice: \n");
    printf("  1- Insert a new data.\n");
    printf("  2- Remove a data.\n");
    printf("  3- Exit.\n");
    scanf("%d", &choice);

    return choice;
}

void insert (ListNode** startPtr, char value)
{
    ListNode* newNode;
    ListNode* previousNode;
    ListNode* currentNode;

    newNode = (ListNode*) malloc (sizeof(ListNode));

    if (newNode != NULL)
    {
        newNode->data = value;
        newNode->nextNode = NULL;

        previousNode = NULL;
        currentNode = *startPtr;

        while (currentNode != NULL && value > currentNode->data)
        {
            previousNode = currentNode;
            currentNode = currentNode->nextNode;
        }
        
        //Insere novo nó no inicio da lista
        if (previousNode == NULL)
        {
            newNode->nextNode = currentNode;
            *startPtr = newNode;
        }
        else
        {
            newNode->nextNode = currentNode;
            previousNode->nextNode = newNode;
        }        

    } else {
        printf("%c cannot be inserted. Not enough available memory.\n", value);
    }    
}

char delete (ListNode** startPtr, char value)
{  
    ListNode* previousNode = NULL;
    ListNode* currentNode = *startPtr;
    ListNode* tempNode;

    while (currentNode != NULL && currentNode->data != value)
    {
        previousNode = currentNode;
        currentNode = currentNode->nextNode;
    }
    
    //Remove nó no inicio da lista
    if (previousNode == NULL)
    {
        tempNode = *startPtr;
        *startPtr = (*startPtr)->nextNode;
        free(tempNode);
        return value;
    } 

    if (currentNode != NULL)
    {
        tempNode = currentNode;
        previousNode->nextNode = currentNode->nextNode;
        free(tempNode);
        return value;
    }
       
    return '\0';
}

int isEmpty(ListNode* startPtr) 
{
    return startPtr == NULL;   
}

void printList(ListNode* currentPtr)
{
    if(currentPtr == NULL) 
    {
        printf("Empty List.\n\n");
        return;
    }    

    printf("List: \n");

    while (currentPtr != NULL)
    {
        printf("%c -- > ", currentPtr->data);
        currentPtr = currentPtr->nextNode;
    }
    
    printf("NULL\n\n");
}