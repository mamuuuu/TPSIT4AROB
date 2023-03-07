typedef struct node{
    int val;
    struct node* next;
}Node;


//LISTE
//da array a lista
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

//da lista ad array
void list2array(int vett[], Node *l){
    int k=0;
    while (k<DIM && l!=NULL)                                 //puntatore alla lista diversa da NULL
    {
        vett[k]=l->valore;
        l=l->next; 
        k++;                                 
    }
}

//Disalloca lista
void dis(Node *l){

    Node *temp;
    if (l != NULL){
        temp=l->next;
        free(l);
        dis(temp);
    }
}

//Stampa lista
void stampa(Node *l){
    
    printf("STAMPA CON PROC: \n");
    while (l!=NULL)                                 //puntatore alla lista diversa da NULL
    {
        printf("\n%d - %p \n",l->valore, l->next);
        l=l->next;                                  //assegna ad l il campo successivo, all'ultima iterazione assegna il campo NULL ed esce dal ciclo
    }
}

//Inserimento 
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

//Num elementi
int elementi(Node *l){
    
    int k=0;
    while (l!=NULL)                                 //puntatore alla lista diversa da NULL
    {
        k++;
        l=l->next;                                  //assegna ad l il campo successivo, all'ultima iterazione assegna il campo NULL ed esce dal ciclo
    }

    return k;
}

//Inserimento head
void insertHead(Node** head, int val){              //riferimento all'indirizzo della testa
    
    Node* newHead = (Node*)malloc(sizeof(Node));

    newHead->valore = val;                          //carico il nuovo valore nel nuovo nodo
    newHead->next = (*head);                        //il next punta alla cella head

    (*head) = newHead;                              //assegno la nuova testa 
}



//PILE
//push
void push(Node **head, Node *element){
    
    if(is_empty(*head)){
        *head = element;
        element->next = NULL;
    }else {
        element->next = *head;
        *head = element;
    }
}

//pop
Node* pop(Node **head){
    Node *ret = *head;

    if (is_empty(*head))
        return NULL;
    else 
        *head = ret->next;
    
    return ret;
}

//stampa pila
void printPila(Node* p) {
    printf("%c\n", p->c);
    if(p->next!=NULL)
        printPila(p->next);
}

//is empty
int is_empty(Node *head){
    if (head == NULL) return 1;
    else return 0;
}


//CODE
//is empty
int is_empty(Node *head){
    if (head == NULL) return 1;
    else return 0;
}

//enqueue
void enqueue(Node **head, Node **tail, Node *element){
    if (is_empty(*head))
        *head = element;
    else 
        (*tail)->next = element;

    *tail = element;
    element->next = NULL;
}

//dequeue
Node* dequeue(Node** head, Node** tail){
    Node* ret = *head;

    if(is_empty(*head))
        return NULL;
    else
        *head = ret->next;
    
    if(*head == NULL)
        *tail = NULL;
    
    return ret;
}

//stampa
void stampa_coda(Node *head){
    printf("%d\n", head->val);
    
    if (head->next!=NULL)
        stampa_coda(head->next);
}



/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAXN 4 //minuti max per cliente
#define MINN 1 //minuti min per cliente
#define GLAVORATIVA 720 // minuti

typedef struct cliente{
    int nCliente;
    int tempo;
    struct cliente *next;
}Cliente;

int is_empty(Cliente* head){
    if(head == NULL) return 1;
    else return 0;
}

void enqueue(Cliente** head, Cliente** tail, Cliente* element){
    if(is_empty(*head))
        *head = element;
    else
        (*tail)->next = element;
    
    *tail = element;
    element->next = NULL;
}

Cliente* dequeue(Cliente** head, Cliente** tail){
    Cliente* ret = *head;

    if(is_empty(*head))
        return NULL;
    else
        *head = ret->next;
    
    if(*head == NULL)
        *tail = NULL;
    
    return ret;
}

int Casuale(){
    int casuale;

    casuale = rand()%MAXN+MINN;
    
    return casuale;
}


int main(){
    srand(time(NULL)); 
    //coda dei clienti da servire
    Cliente* current_head = NULL;       
    Cliente* current_tail = NULL; 

    int tempoTraClienti = 4; //tempo tra i clienti
    int numCliente = 0; //tiene conto dei clienti
    
    Cliente* cliente;
    Cliente* clienteUscito;

    //per 720 minuti
    for(int k = GLAVORATIVA; k >= 0; k--){
        tempoTraClienti--;

        if(tempoTraClienti == 0){
            cliente = (Cliente*)malloc(sizeof(Cliente));
            numCliente++;
            cliente->nCliente = numCliente;
            cliente->tempo = Casuale();
            cliente->next = NULL;
            printf("al minuto %d e' entrato %d\n", k, numCliente);
            enqueue(&current_head, &current_tail, cliente);
            tempoTraClienti = Casuale();
        }

        if(!is_empty(current_head)) {
            current_head->tempo--;
            if( current_head->tempo == 0){
                clienteUscito = dequeue(&current_head, &current_tail);
                printf("Il cliente %d e' uscito al minuto %d\n", clienteUscito->nCliente, k); 
                free(clienteUscito);
            }
        }

        

    }


}

*/