/*The following code considers the linked list to be a global variable. 
Due to the fact that it's global we could skip some aspects such as calling the head as an argument to the function
It makes it more readable as well.
Considering the linked lists as local variables will be done in singlylinkedlists2
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef struct node{
    int data; 
    struct node* next;
}node;
node *head;

void frontinsertion(int a){
    node *n=malloc(sizeof(node)),*temp=head;
    n->data=a;
    n->next=head;
    head=n;
}
void backinsertion(int a){
    node *n=malloc(sizeof(node));
    n->data=a;
    n->next=NULL;
    node *temp=head;
    if(head==NULL){
        head=n;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=n;
    }
    //return n;
}
void middleinsert(int a, int pos){
    node *temp=head;
    if(pos<0){
        printf("Not a valid position\n\n");
    }
    else if(pos==0){
        node *n=(node *)malloc(sizeof(node));
        n->data=a;
        n->next=head;
        head=n;
    }
    else{
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
            if(temp==NULL){
                printf("Position out of bound\n\n");
                break;
            }
        }
            if(temp->next==NULL){
                backinsertion
            }
            node *n=(node *)malloc(sizeof(node));
            n->data=a;
            n->next=temp->next;
            temp->next=n;
    }
}

int frontdeletion(){
    if (head==NULL){
        printf("Nothing to delete\n"); 
        return -1;
    }
    node *temp=head;
    head=head->next;
    int a=temp->data;
    printf("%d is deleted\n\n",a);
    free(temp);
    return a;
}
int backdeletion(){
    node *temp=head;
    int a;
    if (temp==NULL) {
        printf("Nothing to delete\n");
    }
    else if(temp->next==NULL){
        printf("%d is deleted\n",a=temp->data);
        head=NULL;
        free(temp);
    }
    else{
        while((temp->next)->next!=NULL){
            temp=temp->next;
        }
        int a=temp->next->data;
        printf("%d is deleted\n\n",a);
        free((temp->next)->next);
        temp->next=NULL;
    }
    return a;
}
int middledeletion(int pos){
    node *temp=head; int n;
    if(pos<0){
        printf("Not a valid position\n\n");
    }
    else{
        for(int i=-1;i<pos-2;i++){
            temp=temp->next;
            if(temp==NULL){
                printf("Position out of bound\n\n");
                return -1;
            }
        }
        node *tobedeleted=temp->next;
        temp->next=(temp->next)->next;
        printf("%d is deleted", n=tobedeleted->data);
        free(tobedeleted);
    }

    return n;
}

void display(){
    node *temp=head;
    if(temp==NULL){
        printf("Nothing to print");
    }
    while(temp!=NULL){
        printf("%d \t",temp->data,temp->next);
        temp=temp->next;
    }
    printf("\n");
}


int main(){
    int choice=1,num,pos;
    while(choice){
        printf("Enter your choice:\n1)Insert Front\t2)Insert Back\n3)Insert Middle\t4)Delete Front\n5)Delete Back\t6)Delete Middle\nDisplay\n0)Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter value: ");
                scanf("%d",&num);
                frontinsertion(num);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d",&num);
                backinsertion(num);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d",&num);
                printf("Enter position to add this value: ");
                scanf("%d",&pos);
                middleinsert(num,pos);
                break;
            case 4:
                frontdeletion();
                break;
            case 5:
                backdeletion();
                break;
            case 6:
                printf("Enter position to be deleted: ");
                scanf("%d",&pos);
                middledeletion(pos);
                break;
            case 7:
                printf("The elements of the linked lists are:\n");
                display();
                break;
            case 0:
                printf("Bye!\n");
                break;
            default:
                printf("invalid Choice\n");
        }
    }
}