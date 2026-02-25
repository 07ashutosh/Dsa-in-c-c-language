#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next, *prev;
} *start = NULL, *nn, *temp,*tail = NULL,*loc;

void insBeg(int d){
    nn = (struct node *)malloc(sizeof(struct node));
    nn ->data = d;
    nn->prev = NULL;
    if(start == NULL){
        start =nn;
        start->next =NULL;
    }else{
        nn->next = start;
        start->prev = nn;
        start = nn;        
    }

}

void insEnd(int d){
    nn = (struct node *)malloc(sizeof(struct node));
    nn->data = d;
    nn->next = NULL;
    if(start == NULL){
        printf("underflow");
    }else{
        temp = start;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp ->next = nn;
        nn ->prev =temp;

    }

}

void insSpecific(int af, int d){
    nn= (struct node *)malloc(sizeof(struct node));
    nn ->data = d;
    if(start == NULL){
        printf("underflow");

    }else{
        temp = start;
        while(temp !=NULL){
            if(temp->data ==af){
                nn->next = temp->next;
                nn->prev =temp;
                if(temp->next != NULL){
                    temp->next->prev = nn;
                }
                temp->next = nn;
                break;

            }
            temp = temp->next;
              }
    }
}

void delBeg(){
    if(start == NULL){
        printf("underflow");
    }else{
        temp = start;
        start = temp->next;
        temp ->next = NULL;
        start->prev= NULL;
        free(temp);
    }
}

void delEnd(){
    if(start == NULL){
        printf("underflow");
    }else{
        temp = tail;
        tail = temp->prev;
        tail->next = NULL;
        free(temp);
    }
}

void delSpecfic(int d){
    if(start == NULL){
        printf("underflow");
    }else{
        temp = start;
        while (temp != NULL){
            if(temp->data == d){
            temp ->next ->prev= temp ->prev;
            temp->prev->next= temp->next;
            free(temp);
            break;
            }
            temp = temp->next;
        }
        

    }
}





void traveral(){
    temp = start;
    while(temp != NULL){
        printf("%d ->",temp->data);
        temp = temp->next;
    }
}

int main(){
    insBeg(5);
    insBeg(4);
    insBeg(3);
    insBeg(2);
    insBeg(1);
    insEnd(6);
    insSpecific(3,8);
    delBeg();
    delEnd();
    delSpecfic(8);
    traveral();
}