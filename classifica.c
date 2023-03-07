#include  <stdio.h>
#include  <stdlib.h>
#include <string.h>

typedef struct  node{
    int  valore;
    struct  node* next;                                     //indirizzo del nodo successivo
}Node;

void dis(Node *l){

    Node *temp;
    if (l != NULL){
        temp=l->next;
        free(l);
        dis(temp);
    }
}

void inserimento(Node **head, Node *element){
    Node *curr=*head;
    Node *prev = NULL;

    while (curr != NULL){       //cicla e va ad inserire il valore tra curr e prev
    /*
        if (element->valore >= curr->valore)
            break;
    */
        prev = curr;
        curr = curr->next;
    }

    if (prev == NULL){          //lista vuota
        *head = element;
    }else {
        prev->next = element;
    }

    element->next=curr;
}

int pop(Node *l){
    
    int k=0;
    while (l!=NULL)                                  //puntatore alla lista diversa da NULL
    {
        printf("\n %d \n", l->valore);
        l=l->next;                                          //assegna ad l il campo successivo, all'ultima iterazione assegna il campo NULL ed esce dal ciclo
        k++;
    }

    return l->valore;
}

void insertTail(Node** head, int val){       //riferimento all'indirizzo della testa
    
    Node* newHead = (Node*)malloc(sizeof(Node));

    newHead->valore = val;      //carico il nuovo valore nel nuovo nodo
    newHead->next = (*head);    //il next punta alla cella head

    (*head) = newHead;          //assegno la nuova testa 
}

int  main()
{
    int n;
    char nom[20];
    Node* lista;//tipo a puntatore a node
    Node* coda;
    lista = NULL;
    int k=0;
    
    do
    {
        printf("Inserisci il valore del viodeogioco o -1 per  terminare\n");
        scanf("%d",&n);

        //if (n!=-1){
          //  printf("Inserisci il nome: \n");
          //  fflush(stdin);
          //  gets(nom);
        //}
        if (n !=-1)
            insertTail(&coda,n);

        k++;
            /*
            if(k>=5){
                dis(lista);
            }
            */
        
    } while (n>=0);
    
    pop(coda);
    //stampa(coda);
    
    return  0;
}