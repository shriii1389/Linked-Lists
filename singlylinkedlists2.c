/*
Now we are officially done with everything theory based for linked list
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

//Insertion functions
node *frontinsertion(node *head,int a){
    node *n= (node *)(malloc(sizeof(node)));
    n->data=a;
    n->next=head;
    return n;
}
node *backinsertion(node *head,int a){
    node *temp=head, *n= (node *)(malloc(sizeof(node)));
    n->next=NULL;
    n->data=a;
    if(head==NULL){
        return n;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=n;
    }
    return head;
}
node *middleinsert(node *head, int a, int pos){
    node *temp=head;
    if(pos<0){
        printf("Not a valid position\n\n");
    }
    else if(pos==0){
        node *n= (node *)(malloc(sizeof(node)));
        n->data=a;
        n->next=head;
        return n;
    }
    else{
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
            if(temp==NULL){
                printf("Position out of bound\n\n");
                return head;
            }
        }
        node *n=(node *)malloc(sizeof(node));
        n->data=a;
        n->next=temp->next;
        temp->next=n;
    }
    return head;
}

//Deletion Functions
node *frontdeletion(node *head){
    if (head==NULL){
        printf("Nothing to delete\n"); 
        return NULL;
    }
    node *temp=head;
    head=head->next;
    int a=temp->data;
    printf("%d is deleted\n",a);
    free(temp);
    return head;        
}
node *backdeletion(node *head){
    node *temp=head;
    int a;
    if (temp==NULL) 
        printf("Nothing to delete\n");
    else if(temp->next==NULL){
        head=NULL;
        free(temp);
    }
    else
    {
        while((temp->next)->next!=NULL){
            temp=temp->next;
        }
        a=temp->next->data;
        free((temp->next)->next);
        temp->next=NULL;
    }
    return head;
}
node *middledeletion(node *head,int pos){
    node *temp=head; int n;
    if(head==NULL){
        printf("List is empty\n");
        
    }
    else if(pos<0){
        printf("Not a valid position\n\n");
    }
    else if(pos==0){
        frontdeletion(head);
    }
    else{
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
            if(temp==NULL){
                printf("Position out of bound\n\n");
                return head;
            }
        }
        node *tobedeleted=temp->next;
        temp->next=(temp->next)->next;
        printf("%d is deleted", n=tobedeleted->data);
        free(tobedeleted);
    }

    return head;
}

//Display functions
void display(node *head){
    node *temp=head;
    if(temp==NULL){
        printf("Nothing to print\n");
    }
    else{
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
int sum(node *head){
    node *temp=head;
    int sum=0;
    if(temp==NULL){
        printf("Nothing to add\n");
    }
    else{
        while(temp!=NULL){
            sum+=temp->data;
            temp=temp->next;
        }
    }
    return sum;
}
//Main function
void main(){
    node *head=NULL;
    int choice=1,num,pos;
    while(choice){
        printf("Enter your choice:\n1)Insert Front\t2)Insert Back\n3)Insert Middle\t4)Delete Front\n5)Delete Back\t6)Delete middle\n7)Display\n0)Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter value: ");
                scanf("%d",&num);
                head=frontinsertion(head,num);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d",&num);
                head=backinsertion(head,num);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d",&num);
                printf("Enter position to add this value: ");
                scanf("%d",&pos);
                head=middleinsert(head,num,pos);
                break;
            case 4:
                head=frontdeletion(head);
                break;
            case 5:
                head=backdeletion(head);
                break;
            case 6:
                printf("Enter position to be deleted this value: ");
                scanf("%d",&pos);
                head=middledeletion(head,pos);
                break;
            case 7:
                printf("The elements of the linked lists are:\n");
                display(head);
                break;
            case 0:
                printf("Bye!\n");
                break;
            default:
                printf("invalid Choice\n");
        }
    }
}