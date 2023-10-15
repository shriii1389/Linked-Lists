/*
Now we are officially done with everything theory based for linked list
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;
node *ascending(node *head,int a){
    if(head==NULL){
        node *n=(node*)malloc(sizeof(node)); //First node.
        n->data=a;
        n->next=NULL;
        head=n;
        return head;
    }
    else if(head->data>a){
        node *n=(node*)malloc(sizeof(node)); //Equivalent to front insertion.
        n->data=a;
        n->next=head;
        head=n;
        return head;
    }
    node *temp=head;
    while((temp->next)!=NULL && (temp->next)->data<a){
        temp=temp->next;
    }
    node *n=(node *)malloc(sizeof(node));
    n->data=a;
    n->next=temp->next;
    temp->next=n;
    return head;
}

int frontdeletion(node *head){
    if (head==NULL){
        printf("Nothing to delete\n"); 
        return -1;
    }
    node *temp=head;
    head=head->next;
    int a=temp->data;
    printf("%d is deleted\n",a);
    free(temp);
    return a;        
}
int backdeletion(node *head){
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
    return a;
}
int middledeletion(node *head,int pos){
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

void display(node *head){
    node *temp=head;
    if(temp==NULL){
        printf("Nothing to print\n");
    }
    else{
        printf("\nElements of the list are\n");
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

void main(){
    node *head=NULL;
    int choice=1,num,pos;
    while(choice){
        printf("What do you want to do?\n1)Insert an element\t2)Delete first element\n3)Delete last element\t4)Delete number by index\n5)Display\t0)Exit\n");
        scanf("%d",&choice);
        switch (choice){
        case 1:    
            printf("Enter an element: ");
            scanf("%d",&num);
            head=ascending(head,num);
            //display(head);
            break;
        case 2:
            frontdeletion(head);
            break;
        case 3:
            backdeletion(head);
            break;
        case 4:
            printf("Enter the index to delete\n");
            scanf("%d",num);
            middledeletion(head,num);
        case 5:
            display(head);
            break;
        case 0:
            printf("Bye!!\n");
            choice=0;
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}