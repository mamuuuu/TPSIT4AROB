/*crea  una  lista e la  stampa*/
#include  <stdio.h>
#include  <stdlib.h>

typedef struct  node{
    int  valore;
    struct  node* next;                             //indirizzo del nodo successivo
}Node;

void dis(Node *l){

    Node *temp;
    if (l != NULL)
        temp=l->next;
        free(l);
        dis(temp);
}

void disIT(Node *l){
    Node *temp;
    while (l!=NULL){
        temp=l;
        l=l->next;
        free(temp);
    }
}

void stampaRic(Node *l){
    
    printf("\n%d - %p \n", l->valore, l->next);

    if (l->next != NULL)
        stampaRic(l->next);
}

void stampa(Node *l){
    
    printf("STAMPA CON PROC: \n");
    while (l!=NULL)                                 //puntatore alla lista diversa da NULL
    {
        printf("\n%d - %p \n",l->valore, l->next);
        l=l->next;                                  //assegna ad l il campo successivo, all'ultima iterazione assegna il campo NULL ed esce dal ciclo
    }
}

int elementi(Node *l){
    
    int k=0;
    while (l!=NULL)                                 //puntatore alla lista diversa da NULL
    {
        k++;
        l=l->next;                                  //assegna ad l il campo successivo, all'ultima iterazione assegna il campo NULL ed esce dal ciclo
    }

    return k;
}

void insertHead(Node** head, int val){       //riferimento all'indirizzo della testa
    
    Node* newHead = (Node*)malloc(sizeof(Node));

    newHead->valore = val;      //carico il nuovo valore nel nuovo nodo
    newHead->next = (*head);    //il next punta alla cella head

    (*head) = newHead;          //assegno la nuova testa 
}

void inserimento(Node **head, Node *element){
    Node *curr=*head;
    Node *prev = NULL;

    while (curr != NULL){
        if (element->valore <= curr->valore)
            break;
        prev = curr;
        curr = curr->next;
    }

    if (prev == NULL){
        *head = element;
    }else {
        prev->next = element;
    }

    element->next=curr;
}

int  main()
{
    int n;
    Node* lista;        //tipo a puntatore a node
    Node* l;            //tipo a puntatore a node
    lista = NULL;
    
    do
    {
        printf("Inserisci  un  naturale o  -1 per  terminare\n");
        scanf("%d",&n);

        if (n!=-1){
            Node *elem;
            elem = (Node*)malloc(sizeof(Node));
        
            elem->valore=n;
            elem->next=NULL;

            inserimento(&lista,elem);
        }
        
    } while (n>=0);
    
    l = lista;
    stampa(lista);

    dis(lista);

    l = lista;
    stampa(lista);
    
    return  0;
}

/*
    FUNZIONI

    l = lista;
    stampa(l);

    l = lista;
    printf("\n%d", elementi(l));

    l=lista;
    stampaRic(l);
*/