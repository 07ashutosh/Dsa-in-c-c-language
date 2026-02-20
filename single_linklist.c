#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *start = NULL, *nn, *temp, *loc;

void insBeg(int data)
{
    nn = (struct node *)malloc(sizeof(struct node));
    nn->data = data;
    if (start == NULL)
    {
        nn->next = NULL;
        start = nn;
    }
    else
    {
        nn->next = start;
        start = nn;
    }
}
void insEnd(int d)
{
    nn = (struct node *)malloc(sizeof(struct node));
    nn->data = d;
    nn->next = NULL;
    if (start == NULL)
    {
        nn->next = NULL;
        start = nn;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nn;
    }
}

void insSpecific(int af, int d)
{
    nn = (struct node *)malloc(sizeof(struct node));
    nn->data = d;
    if (start == NULL)
    {
        printf("list is empty");
    }
    else
    {
        temp = start;
        while (temp != NULL)
        {
            // temp = temp->next;
            if (temp->data == af)
            {
                nn->next = temp->next;
                temp->next = nn;
                break;
            }
            temp = temp->next;
        }
    }
}

void delBeg()
{
    if (start == NULL)
    {
        printf("Under flow");
    }
    else
    {
        temp = start;
        start = temp->next;
        free(temp);
    }
}

void delEnd()
{
    if (start == NULL)
    {
        printf("Underflow");
    }
    else
    {
        temp = start;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void delSpecific(int d)
{
    if (start == NULL)
    {
        printf("Underflow");
    }
    else
    {
        temp = start;
        do
        {
            if (temp->next->data == d)
            {
                loc = temp->next;
                temp->next = loc->next;
                free(loc);
                break;
            }
            temp = temp->next;
        } while (temp != start);
    }
}

void traversal()
{
    if (start != NULL)
    {
        temp = start;
        while (temp != NULL)
        {
            printf("%d ->", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    insBeg(1);
    insBeg(2);
    insBeg(3);
    insBeg(4);
    insBeg(5);

    insEnd(7);
    insSpecific(3, 6);
    traversal();
    printf("\nbefore del\n");
    // delBeg();
    delEnd();
    delSpecific(6);
    traversal();
}