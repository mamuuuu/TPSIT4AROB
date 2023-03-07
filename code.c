#include  <stdio.h>
#include  <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int val;
    struct node* next;
}Node;

int is_empty(Node *head){
    if (head == NULL) return 1;
    else return 0;
}

void enqueue(Node **head, Node **tail, Node *element){
    if (is_empty(*head))
        *head = element;
    else 
        (*tail)->next = element;

    *tail = element;
    element->next = NULL;
}

void stampa_coda(Node *head){
    printf("%d\n", head->val);
    
    if (head->next!=NULL)
        stampa_coda(head->next);
}

int main(){
    Node *head = NULL;
    Node *tail = NULL;
    Node *element;
    int n;

    while (n!=-1){
        printf("Inserisci: \n");
        scanf("%d", &n);

        if (n!=-1){
            element = (Node*)malloc(sizeof(Node));
            element->val = n;

            enqueue(&head, &tail, element);
        }
    }
    
    stampa_coda(head);

    return 0;
}