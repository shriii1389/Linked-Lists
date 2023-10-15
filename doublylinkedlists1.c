#include <stdio.h>
#include <stdlib.h>
typedef struct dnode{
    struct dnode *prev;
    int data;
    struct dnode *next;
}dnode;
//Insertion functions
dnode *frontinsertion(dnode *head,int a){
    dnode *n=(dnode *)malloc(sizeof(dnode));
    n->data=a;
    n->next=NULL;
    n->prev=NULL;
    if (head==NULL) head=n;
    else{
        n->next=head;
        head->prev=n;
        head=n;
    }
    return head;
}
dnode *backinsertion(dnode *head, int a){
    dnode *n=(dnode *)malloc(sizeof(dnode));
    n->data=a;
    n->next=NULL;
    if(head==NULL) head=n;
    else{
        dnode *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=n;
        n->prev=temp;
    }
    return head;
}
dnode *middleinsert(dnode *head, int a, int pos){
    dnode *temp=head;
    dnode *n= (dnode *)(malloc(sizeof(dnode)));
    n->data=a;
    n->next=head;
    if(pos<0){
        printf("Not a valid position\n\n");
    }
    else if(pos==0){
        head=n;
    }
    else{
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
            if(temp==NULL){
                printf("Position out of bound\n\n");
                return head;
            }
        }
        n->next=temp->next;
        n->prev=temp;
        (temp->next)->prev=n;
        temp->next=n;
    }
    return head;
}
dnode *successiveinsert(dnode *head, int a, int successor){
    dnode *temp=head;
    dnode *n= (dnode *)(malloc(sizeof(dnode)));
    n->data=a;
    n->next=head;
    while(temp->next!=NULL && temp->next->data!=successor){
        temp=temp->next;
    }
    if(temp->next->data==successor){
        n->next=temp->next;
        n->prev=temp;
        (temp->next)->prev=n;
        temp->next=n;
    }
    else{
        printf("Element not available.\n");
    }
    return head;
}

//Deletion functions
dnode *frontdeletion(dnode *head){
    if (head==NULL){
        printf("Nothing to delete\n"); 
        return NULL;
    }
    dnode *temp=head;
    head=head->next;
    head->prev=NULL;
    int a=temp->data;
    printf("%d is deleted\n",a);
    free(temp);
    return head;        
}
dnode *backdeletion(dnode *head){
    dnode *temp=head;
    int a;
    if (temp==NULL) 
        printf("Nothing to delete\n");
    else if(temp->next==NULL){
        head=NULL;
        free(temp);
    }
    else
    {
        while(temp->next!=NULL){
            temp=temp->next;
        }
        a=temp->data;
        printf("%d is deleted\n",a);
        temp->prev->next=NULL;
        free(temp);
    }
    return head;
}
dnode *middledeletion(dnode *head,int pos){
    dnode *temp=head; int n;
    if(head==NULL){
        printf("List is empty\n");
        
    }
    else if(pos<0){
        printf("Not a valid position\n\n");
    }
    else if(pos==0){
        head=head->next;
        dnode *temp=head->prev;
        free(temp);
        head->prev=NULL;
    }
    else{
        for(int i=0;i<pos;i++){
            temp=temp->next;
            if(temp==NULL){
                printf("Position out of bound\n\n");
                return head;
            }
        }
        printf("%d is deleted\n", n=temp->data);
        if(temp->next!=NULL){
            (temp->prev)->next=temp->next;
            (temp->next)->prev=temp->prev;
        }
        else{
            (temp->prev)->next=NULL;
        }free(temp);
    }

    return head;
}
dnode *valuedeletion(dnode *head,int adieuBrother){
    dnode *temp=head; int n;
    if(head==NULL){
        printf("List is empty\n");
        
    }
    while(temp!=NULL && temp->data!=adieuBrother){
        temp=temp->next;
    }
    if(temp->data==adieuBrother){
        n=temp->data;
        if(temp->next!=NULL){
            (temp->prev)->next=temp->next;
            (temp->next)->prev=temp->prev;
        }
        else{
            (temp->prev)->next=NULL;
        }
        free(temp);
        printf("%d is deleted\n", n);
    }
    else{
        printf("Element not present\n");
    }
    return head;
}

dnode *orderedinsertion(dnode *head,int a){
    dnode *n=(dnode *)malloc(sizeof(dnode));
    dnode *temp=head;
    n->data=a;
    n->next=NULL; n->prev=NULL;
    if(head==NULL){ 
        head=n;
    }
    else if(head->data>a){
        head->prev=n;
        n->next=head;
        head=n;        
    }
    else{
        while((temp->next)!=NULL && (temp->next)->data<a){
            temp=temp->next;
        }
        if((temp->next)==NULL){
            temp->next=n;
            n->prev=temp;
        }
        else{
            n->next=temp->next;
            n->prev=temp;
            (temp->next)->prev=n;
            temp->next=n;
        }

    }
    return head;
}

//Display functions
void display(dnode *head){
    dnode *temp=head;
    if(temp==NULL){
        printf("Nothing to print\n");
    }
    else{
        while(temp!=NULL){
            printf("%d\t",temp->data);
            if(temp->next==NULL) break;
            temp=temp->next;
        }
        printf("\nIn reverse order\n\n");
        
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->prev;
        }
        printf("\n\n");
    }
}

//Main function
void main(){
    dnode *head=NULL;
    int choice=1,num,pos,mode;
    printf("Enter the mode you want to work with\n1)Ordered list \n2)Unordered list\n");
    scanf("%d",&mode);
    if(mode==2){
        while(choice){
            printf("Enter your choice:\n1)Insert Front\t2)Insert Back\n3)Insert Middle\t4)Successive Insert\n5)Delete Front\t6)Delete Back\n7)Delete middle\t8)Delete value\n9)Display\t0)Exit\n");
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
                    printf("Enter value: ");scanf("%d",&num);
                    printf("Enter the successive element: "); scanf("%d",&pos);
                    head=successiveinsert(head,num,pos);
                    break;
                case 5:
                    head=frontdeletion(head);
                    break;
                case 6:
                    head=backdeletion(head);
                    break;
                case 7:
                    printf("Enter position to be deleted this value: ");
                    scanf("%d",&pos);
                    head=middledeletion(head,pos);
                    break;
                case 8:
                    printf("Enter value to be deleted: ");scanf("%d",&num);
                    head=valuedeletion(head,num);
                    break;
                case 9:
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
    else if(mode==1){
        while(choice){
            printf("What do you want to do?\n1)Insert an element\t2)Delete first element\n3)Delete last element\t4)Delete number by index\n5)Display\t0)Exit\n");
            scanf("%d",&choice);
            switch (choice){
            case 1:    
                printf("Enter an element: ");
                scanf("%d",&num);
                head=orderedinsertion(head,num);
                //display(head);
                break;
            case 2:
                head=frontdeletion(head);
                break;
            case 3:
                head=backdeletion(head);
                break;
            case 4:
                printf("Enter the index to delete\n");
                scanf("%d",&num);
                head=middledeletion(head,num);
            case 5:
                printf("The elements present are:\n");
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
}