#include  <stdio.h>
#include  <stdlib.h>
#include <stdbool.h>

typedef struct  node{
    char c;
    struct node* next;                             //indirizzo del nodo successivo
}Node;

int is_empty(Node *head){
    if (head == NULL) return 1;
    else return 0;
}

void push(Node **head, Node *element){
    
    if(is_empty(*head)){
        *head = element;
        element->next = NULL;
    }else {
        element->next = *head;
        *head = element;
    }
    
    /*
    if (!is_empty(*head))
         element->next= *head;
    *head  = element;
    */
}

Node* pop(Node **head){
    Node *ret = *head;
    printf("x");

    if (is_empty(*head))
        return NULL;
    else 
        *head = ret->next;
    
    return ret;
}

void printPila(Node* p) {
    printf("%c\n", p->c);
    if(p->next!=NULL)
        printPila(p->next);
}

int main(){
    Node *pila;
    char str[7] = "((())}";
    bool ok = true;
    int k=0;
    Node *element;
    Node *ret;

    while (ok && str[k]!='\0'){
        switch (str[k])
        {
        case'(':
            element = (Node*)malloc(sizeof(Node));
            element->c='(';
            element->next=NULL;
            push(&pila,element);
            printf("carica (");

            break;
        case'[':
            element = (Node*)malloc(sizeof(Node));
            element->c='[';
            element->next=NULL;
            push(&pila,element);
            printf("carica [");

            break;
        case '{':
            element = (Node*)malloc(sizeof(Node));
            element->c='(';
            element->next=NULL;
            push(&pila,element);
            printf("carica {");
            break;
        }
        
        switch (str[k])
        {
        case')':
            //printf("prima:\n");
            //printPila(pila);
            printf("-)-");
            ret = pop(&pila);
            if (ret->c != '('){
                ok = false;
                printf("Errore ).\n");
            }
            //printf("dopo:\n");
            //printPila(pila);

            break;
        case']':
            //printf("prima:\n");
            //printPila(pila);
            printf("-]-");
            ret = pop(&pila);
            if (ret->c != '['){
                ok = false;
                printf("Errore ].\n");
            }
            //printf("dopo:\n");
            //printPila(pila);

            break;
        case '}':
            //printf("prima:\n");
            //printPila(pila);
            printf("-}-");
            ret = pop(&pila);
            if (ret->c != '{'){
               ok = false;
               printf("Errore }\n");
            }
            //printf("dopo:\n");
            //printPila(pila);

            break;
        }
        k++;

    }

    /*
    ret = pop(&pila);
    printf("%p", ret->next);
    */

    if (is_empty(pila) && !ok)
        printf("Errore.\n");
    else 
        printf("Giusto.\n");

    return 0;
}
