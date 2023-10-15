#include <stdio.h>
#include <stdlib.h>
typedef struct dnode{
    struct dnode *prev;
    int data;
    struct dnode *next;
}dnode;
//Insertion functions
dnode *frontinsertion(dnode *head,int a){
    dnode *n= (dnode *)(malloc(sizeof(dnode)));
    n->data=a;
    n->next=n;
    n->prev=n;
    if(head==NULL){
        head=n;
        return head;
    }
    dnode *temp=head->prev;
    temp->next=n;
    n->next=head;
    n->prev=temp;
    head->prev=n;
    return head->prev;
}
dnode *backinsertion(dnode *head, int a){
    dnode *n= (dnode *)(malloc(sizeof(dnode)));
    n->data=a;
    n->next=n;
    n->prev=n;
    if(head==NULL){
        head=n;
        return head;
    }
    dnode *temp=head->prev;
    temp->next=n;
    n->next=head;
    n->prev=temp;
    head->prev=n;
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
        temp=temp->prev;
        temp->next=n;
        n->next=head;
        n->prev=temp;
        head->prev=n;
        head=n;
    }
    else{
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
            if(temp==head){
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

//Deletion functions
dnode *frontdeletion(dnode *head){
    if (head==NULL){
        printf("Nothing to delete\n"); 
        return NULL;
    }
    dnode *temp=head;
    (head->next)->prev=head->prev;
    (head->prev)->next=head->next;
    head=head->next;
    int a=temp->data;
    printf("%d is deleted\n",a);
    free(temp);
    return head;        
}
dnode *backdeletion(dnode *head){
    int a;
    if (head==NULL){ 
        printf("Nothing to delete\n");
        return head;
    }
    else if(head->prev==head){
        free(head);
        return NULL;
    }
    else{
        dnode *temp=head->prev;
        a=temp->data;
        temp->prev->next=head;
        head->prev=temp->prev;
        free(temp);
        printf("%d is deleted\n",a);
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
        (head->next)->prev=head->prev; //Front deletion
        (head->prev)->next=head->next;
        head=head->next;
        int a=temp->data;
        printf("%d is deleted\n",a);
        free(temp);
        return head;      
    }
    else{
        for(int i=0;i<pos;i++){
            temp=temp->next;
            if(temp==head){
                printf("Position out of bound\n\n");
                return head;
            }
        }
        printf("%d is deleted\n", n=temp->data);
        (temp->prev)->next=temp->next;
        (temp->next)->prev=temp->prev;
        free(temp);
    }

    return head;
}

//Ordered linked lists
dnode *orderedinsertion(dnode *head,int a){
    dnode *n=(dnode *)malloc(sizeof(dnode));
    dnode *temp=head;
    n->data=a;
    n->next=n; n->prev=n;
    if(head==NULL){ 
        return n;
    }
    if(head->data>a){
        free(n);
        head=frontinsertion(head,a);
        return head;    
    }
    while((temp->next)!=head && (temp->next)->data<a){
        temp=temp->next;
    }
    if((temp->next)==head){
        n->prev=temp;
        n->next=head;
        temp->next=n;
    }
    else{
        n->next=temp->next;
        n->prev=temp;
        (temp->next)->prev=n;
        temp->next=n;
    }
    return head;
}
//Display functions
void display(dnode *head,int count){
    dnode *temp=head;
    if(temp==NULL){
        printf("Nothing to print\n");
    }
    else{
        for(int i=0;i<count;i++){
            printf("%d \t",temp->data);
            temp=temp->next;
        }
        printf("\nIn reverse order\n");
        for(int i=0;i<count;i++){
            printf("%d \t",temp->data);
            temp->prev;
        }
        printf("\nTotal elements present:%d\n\n",count);
    }
}

//Main function
void main(){
    dnode *head=NULL;
    int choice=1,num,pos,mode,count=0;
    printf("Enter the mode you want to work with\n1)Ordered list \n2)Unordered list\n");
    scanf("%d",&mode);
    if(mode==2){
        while(choice){
            printf("Enter your choice:\n1)Insert Front\t2)Insert Back\n3)Insert Middle\t4)Delete Front\n5)Delete Back\t6)Delete middle\n7)Display\n0)Exit\n");
            scanf("%d",&choice);
            switch(choice){
                case 1:
                    printf("Enter value: ");
                    scanf("%d",&num);
                    head=frontinsertion(head,num);
                    count++;
                    break;
                case 2:
                    printf("Enter value: ");
                    scanf("%d",&num);
                    head=backinsertion(head,num);
                    count++;
                    break;
                case 3:
                    printf("Enter value: ");
                    scanf("%d",&num);
                    printf("Enter position to add this value: ");
                    scanf("%d",&pos);
                    head=middleinsert(head,num,pos);
                    count++;
                    break;
                case 4:
                    head=frontdeletion(head);
                    count--;
                    break;
                case 5:
                    head=backdeletion(head);
                    count--;
                    break;
                case 6:
                    printf("Enter position to be deleted this value: ");
                    scanf("%d",&pos);
                    head=middledeletion(head,pos);
                    count--;
                    break;
                case 7:
                    printf("The elements of the linked lists are:\n");
                    display(head,count);
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
                count++;
                //display(head);
                break;
            case 2:
                head=frontdeletion(head);
                count--;
                break;
            case 3:
                head=backdeletion(head);
                count--;
                break;
            case 4:
                printf("Enter the index to delete\n");
                scanf("%d",&num);
                head=middledeletion(head,num);
                count--;
            case 5:
                printf("The elements present are:\n");
                display(head,count);
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