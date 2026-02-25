#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int id;
    char name[30];
    struct node *next,*prev;
}*start=NULL,*nn,*temp,*tail=NULL ;

void insBeg(int id,char name[]){
    nn=(struct node*)malloc(sizeof(struct node));
    nn->id=id;
    strcpy(nn->name,name);
    nn->next=NULL;
    nn->prev=NULL;
    if(start==NULL){
        start=nn;
        tail=nn;
    }
    else{
        nn->next=start;
        start->prev=nn;
        start=nn;
    }
}

void passingPotato(int d){
    if(start == NULL){
        printf("no player is there");
    }else{
        temp = start;
        int count = 0;
        while(count <= d && temp != NULL){
            temp = temp->next;
            count++;
        }
        if(temp != NULL){
            printf("payer eleminated is\t %d \t %s\n",temp->id,temp->name);
            if(temp == start && temp == tail){
                start = NULL;
                tail = NULL;
            }else if(temp == start){
                start = temp->next;
                start->prev = NULL;
            }else if(temp == tail){
                tail = temp->prev;
                tail->next = NULL;
            }else{
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            free(temp);
    }
}

}

void traverse(){
    temp=start;
    while(temp!=NULL){
        printf("%d %s\n",temp->id,temp->name);
        temp=temp->next;
    }
}
int main(){

    insBeg(1,"ashu");
    insBeg(2,"bashu");
    insBeg(3,"sasu");
    insBeg(4,"tasu");
    passingPotato(2);
    traverse();

}