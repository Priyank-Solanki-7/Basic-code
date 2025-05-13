#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *first;

void insertAtBegin(int value) {
   struct node *avail, *newNode;
    avail = (struct node *)malloc(sizeof(struct node));
    
    if (avail == NULL) {
        printf("Space not allocated\n");
    } else {
        newNode = avail;
        
        newNode->data = value;
        
        if (first == NULL) {
            newNode->next = NULL;
        } else {
            newNode->next = first;
        }
        
        first = newNode;
    }
}

void insertAtEnd(int value) {
   struct node *avail, *newNode;
    avail = (struct node *)malloc(sizeof(struct node));
    
    if (avail == NULL) {
        printf("Space not allocated\n");
    } else {
        newNode = avail;
        
        newNode->data = value;
        newNode->next = NULL;
        
        if (first == NULL) {
            first = newNode;
        } else {
            struct node *tempPtr = first;
            
            while (tempPtr->next != NULL) {
                tempPtr = tempPtr->next;
            }
            
            tempPtr->next = newNode;
        }
    }
}

void deleteAtFirst(){
    struct node *ptr;
    // condition for linkedlist null
    if(first==NULL){
        printf("linked list is empty\n");
        return;
    }
    else{
        //if only one node exist
        if(first->next==NULL){
            free(first);
            first=NULL;
        }
        //if morethen one 
        else{
            ptr=first;
            first=ptr->next;
            free(ptr);            
        }
    }
}

void insertAtSpecific(int pos, int data) {
    struct node *ptr, *avail, *newnode;
    int count = 0;

    // Check count
    ptr = first;
    while (ptr != NULL) {
        ptr = ptr->next;
        count++;
    }

    // 1. Check if position is invalid or not
    if (pos <= 0 || pos > count + 1) {
        printf("invalid position");
        return;
    }

    // 2. Check availability for memory allocation
    avail = (struct node *)malloc(sizeof(struct node));
    if (avail == NULL) {
        printf("memory allocation failed");
        return;
    }

    // Assign a new node
    newnode = avail;
    newnode->data = data;

    // Check condition for first position
    if (pos == 1) {
        newnode->next = first;
        first = newnode;
        return;
    }

    // Insert at the specified position
    ptr = first;
    for (int i = 1; i < pos - 1 && ptr != NULL; i++) {
        ptr = ptr->next;
    }

    newnode->next = ptr->next;
    ptr->next = newnode;
}

void deleteAtSpecific(int p){
    int count=0;
    struct node *ptr;
    // when ptr null no plus count
    if(ptr!=NULL){
        ptr=ptr->next;
        count++;
    }
    //check position valid or not
    if(p<=0 && p>count){
        printf("position is envlid plese enter a valid position");
        return;
    }
    //check link list empty or not
    if(first==NULL){
        printf("linked list is empty");
    }
    // if pos is first then delete at first
    if(p==1){
        ptr=first;
        first=first->next;
        free(ptr);
        return;
    }
    struct node *preptr;
    ptr=0;
    preptr=0;
    int i=0;
    while(i<p){
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=ptr->next;
    free(ptr);
}

void delateAtEnd(){
     //check linked list empty or not
     if(first==NULL){
        printf("linked list is empty\n");
        return;
     }
     //if only one node is avilable
     if(first->next==NULL){
        free(first);
        first=NULL;
     }
     //if more then one
     struct node *ptr=first,*preptr=first;
     //teaverse until last node
     while(ptr->next!=NULL){
        preptr=ptr;
        ptr=ptr->next;
     }
     preptr->next=NULL;
     free(ptr);
}

void display() {
    if (first == NULL) {
        printf("Linked list is empty\n");
    } else {
       struct node *tempPtr = first;
        
        while (tempPtr != NULL) {
            printf("%d ", tempPtr->data);
            tempPtr = tempPtr->next;
        }
        printf("\n");
    }
}

void Count(){
    struct node *ptr;
    int nodecount=0;
    if(first==NULL){
        printf("linked isst is empty");
    }
    else{
        ptr=first;
        while(ptr->next!=NULL){
            ptr=ptr->next;
            nodecount++;
            printf("count of node is:",nodecount);
        }
    }
}
int main() {
    int ch, value;

    while (1) {
        printf("Enter Choice :\n1. INSERT_BEGIN\n2. INSERT_END\n3. DISPLAY\n4.DELETE_AT_FIRST\n5.INSERT_AT_SPECIFIC_POSITION\n6.DELETE_AT_SPECIFIC\n7.DELETE_AT_END\n8.Count a node\n0. EXIT\n");

        scanf("%d", &ch);
        int pos,data;
        
        switch (ch) {
            case 1:
                printf("Enter value to insert at beginning: \n");
                scanf("%d", &value);
                insertAtBegin(value);
                break;
            case 2:
                printf("Enter value to insert at end: \n");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                display();
                break;
            case 4:
                deleteAtFirst();
                break;
            case 5:
                printf("enter a position\n");
                scanf("%d",&pos);
                printf("enter a data\n");
                scanf("%d",&data);
                insertAtSpecific(pos,data);
                break;
            case 6:
                printf("enter a position\n");
                scanf("%d",&pos);
                deleteAtSpecific(pos);
                break;
            case 7:
                delateAtEnd();
                break;
            case 8:
                Count();
                break;
            case 0:
                exit(0);
        }
    }
}