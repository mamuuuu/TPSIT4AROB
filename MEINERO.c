#include  <stdio.h>
#include  <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MIN 1
#define MAX 10

typedef struct  node{
    int num_arrivo;
    int num_casuale;
    struct node* next;                             //indirizzo del nodo successivo
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

void push(Node **head, Node *element){
    
    if(is_empty(*head)){
        *head = element;
        element->next = NULL;
    }else {
        element->next = *head;
        *head = element;
    }
}

void printPila(Node* head) {
    printf("%d-%d\n", head->num_arrivo, head->num_casuale);
    if(head->next!=NULL)
        printPila(head->next);
}

void stampa_coda(Node *head){
    printf("%d-%d\n", head->num_arrivo, head->num_casuale);
    
    if (head->next!=NULL)
        stampa_coda(head->next);
}

Node* pop(Node **head){
    Node *ret = *head;

    if (is_empty(*head))
        return NULL;
    else 
        *head = ret->next;
    
    return ret;
}

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

int main(){
    srand(time(NULL));  //srand per generazione valore pseudo causale
    int num_arrivo = 1;

    Node *element;      //elemento per la pila
    Node *element1;     //elemento per la coda

    Node* pila = NULL;  //struttura della pila

    Node *head = NULL;  //struttura head della coda
    Node *tail = NULL;  //struttura tail della coda

    while(num_arrivo<=5){   //while per cinque iterazioni

        element = (Node*)malloc(sizeof(Node));          //allocazione elemento pila
        element->num_arrivo = num_arrivo;
        element->num_casuale = rand() % (MAX-MIN) + MIN;

        push(&pila, element); //caricamento nella pila

        element1 = (Node*)malloc(sizeof(Node));         //allocazione elementno coda
        element1->num_arrivo = num_arrivo;
        element1->num_casuale = rand() % (MAX-MIN) + MIN;

        enqueue(&head, &tail, element1);

        num_arrivo++;                                   //aggioranamento del avlore di arrivo
    }

    printf("Stampa pila: \n");
    printPila(pila);
    printf("Stampa coda: \n");
    stampa_coda(head);

    while (!is_empty(pila) && !is_empty(head)){         //while fino a che una dele due pile non è vuota
        Node *ret_pila;         //Node per il nodo estratto dalla pila
        Node *ret_coda;         // '' '' ''' '' '' '' coda

        ret_pila = pop(&pila);
        ret_coda = dequeue(&head, &tail);

        printf("Valore estratto pila: %d\nValore estratto coda: %d", ret_pila->num_casuale, ret_coda->num_casuale);

        if (ret_pila->num_casuale != ret_coda->num_casuale){        //controllo che non siano uguali
            
            if (ret_coda->num_casuale > ret_pila->num_casuale){     //caso in cui il valore della coda è maggiore
                printf("\nLa coda ha il valore maggiore!\n");
                ret_coda->num_casuale -= ret_pila->num_casuale;
                enqueue(&head, &tail, ret_coda);
            }else {                                                  //caso in cui il valore della pila è maggiore
                printf("\nLa pila ha il valore maggiore!\n");
                ret_pila->num_casuale -= ret_coda->num_casuale;
                push(&pila, ret_pila);
            }
        }else {
            printf("\nHanno lo stesso valore! ELiminati entrambi.\n");
        }

    }

    if (is_empty(pila)){            //se la pila è vuota -> stampo la coda
        printf("Ha vinto la coda: \narrivo - valore\n");
        stampa_coda(head);
    }else {                         //se la coda è vuota -> stampo la pila
        printf("Ha vinto la pila: \narrivo - valore\n");
        printPila(pila);
    }

    return 0;
}