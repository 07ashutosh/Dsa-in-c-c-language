#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next, *prev;
} *start = NULL, *nn, *temp,*tail,*loc;

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
    traveral();
}