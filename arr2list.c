#include  <stdio.h>
#include  <stdlib.h>
#include <string.h>

#define DIM 4

typedef struct  node{
    int  valore;
    struct  node* next;                                     //indirizzo del nodo successivo
}Node;

void stampa(Node *l){
    
    printf("STAMPA CON PROC: \n");
    while (l!=NULL)                                 //puntatore alla lista diversa da NULL
    {
        printf("\n%d - %p \n",l->valore, l->next);
        l=l->next;                                  //assegna ad l il campo successivo, all'ultima iterazione assegna il campo NULL ed esce dal ciclo
    }
}

void inserimento(Node ***head, Node *element){
    Node *curr=**head;
    Node *prev = NULL;

    while (curr != NULL){
        
        prev = curr;
        curr = curr->next;
    }

    if (prev == NULL){
        **head = element;
    }else {
        prev->next = element;
    }

    element->next=curr;
}


void array2list(int vett[], Node **l){
    int k=0;
    while (k<DIM){
        Node *elem;
        elem = (Node*)malloc(sizeof(Node));
        
        elem->valore=vett[k];
        elem->next=NULL;

        inserimento(&l,elem);

        k++;
    }
}

void list2array(int vett[], Node *l){
    int k=0;
    while (k<DIM && l!=NULL)                                 //puntatore alla lista diversa da NULL
    {
        vett[k]=l->valore;
        l=l->next; 
        k++;                                 
    }
}

void stampaV(int vett[]){
    for (int k=0; k<DIM; k++){
        printf("\n%d\n", vett[k]);
    }
}

void dis(Node *l){

    Node *temp;
    if (l != NULL){
        temp=l->next;
        free(l);
        dis(temp);
    }
}

int main(){
    int vett[DIM]={1,2,3,4};
    int vett1[DIM];

    Node* lista;
    lista = NULL;

    array2list(vett,&lista);
    stampa(lista);

    list2array(vett1,lista);
    stampaV(vett1);

    dis(lista);

    return 0;
}