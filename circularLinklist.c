#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next,*prev;
}*start =NULL,*nn,*tail,*temp;

void insBeg(int d){
    nn = (struct node *)malloc(sizeof(struct node));
    nn->data = d;
    if(start == NULL){
        start = nn;
        start->next = start;
        start->prev = start;
        tail = start;

    }else{
        temp = start;
        nn->next = start;
        nn->prev = tail;
        start->prev=nn;
        tail->next = nn;
        start = nn;
    }
}

void insEnd(int d){
    nn = (struct node *)malloc(sizeof(struct node));
    nn->data = d;
    if(start == NULL){
        insBeg(d);
    }else{
        temp = tail;
        nn->prev = temp;
        nn->next = start;
        temp->next = nn;
        start->prev = nn;
        tail = nn;
    }
}

void insSpecfic(int af, int d){
    nn = (struct node *)malloc(sizeof(struct node));
    nn->data =d;
    if(start == NULL){
        printf("underflow");
    }else{
        temp = start;
        while(temp != NULL){
            if(temp->data == af){
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

void traversal(){
    if(start != NULL){
        temp = start;
        do{
            printf("%d ->",temp->data);
            temp = temp->next;
        }while(temp != start);
    }
}
int main(){
    insBeg(1);
    insBeg(2);
    insBeg(3);
    insBeg(4);
    insEnd(0);
    insSpecfic(2,3);
    traversal();
}