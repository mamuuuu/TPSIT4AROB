#include  <stdio.h>
#include  <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define MIN_TIME 50 
#define MAX_TIME 200 
#define LUNG 10
#define TIME_CPU 30

typedef struct node{
    int PID;
    int TIME;
    char STATO[LUNG];
    struct node* next;
}Node;

void delay( int MilliSecondi)    {
    double Secondi = 0;
    if (MilliSecondi > 0)
        Secondi = MilliSecondi / 1000.0;
    clock_t endwait;
    endwait = clock () + Secondi * CLOCKS_PER_SEC;
    while (clock() < endwait) {}
}

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

Node* dequeue(Node **head, Node **tail){
    Node *ret = *head;

    if (is_empty(*head))
        return NULL;
    else 
        *head = ret->next;
    
    if (*head == NULL)
        *tail = NULL;
    
    return ret;
}

void cambia_stato(Node *head){
    strcpy(head->STATO,"Ready");
}

void stampa_coda(Node *head){
    printf("%d\n", head->PID);
    
    if (head->next!=NULL)
        stampa_coda(head->next);
}

int main(){

    int scelta = 1;
    int pid = 0;
    srand(time(NULL));

    Node* Head_New = NULL;
    Node* Tail_New = NULL;

    Node* Head_Ready = NULL;
    Node* Tail_Ready = NULL;
    
    Node* Head_Terminate = NULL;
    Node* Tail_Terminate = NULL;

    //Caricamento processi nella New_List
    while (scelta == 1){
        Node *processo;
        processo = (Node*)malloc(sizeof(Node));
        processo->PID = pid;
        strcpy(processo->STATO,"New");
        processo->TIME = rand() % (MAX_TIME-MIN_TIME+1) + MIN_TIME;
        
        enqueue(&Head_New, &Tail_New, processo);

        printf(" '1' se vuoi inserire un altro processo: \n");
        scanf("%d", &scelta);
        pid++;
    }

    printf("Stampa coda New: \n");
    stampa_coda(Head_New);

    //Caricamento nella Ready_List
    for (int k=0; k<pid; k++){
        cambia_stato(Head_New);
        enqueue(&Head_Ready, &Tail_Ready, dequeue(&Head_New, &Tail_New));
    }

    //Processi
    while (!is_empty(Head_Ready)){
        Node *esecuzione_processo = dequeue(&Head_Ready, &Tail_Ready);

        if (esecuzione_processo->TIME > TIME_CPU){
            esecuzione_processo->TIME-= TIME_CPU;
            enqueue(&Head_Ready, &Tail_Ready, esecuzione_processo);
            delay(TIME_CPU);
        }else{
            strcpy(esecuzione_processo->STATO,"Terminate");
            enqueue(&Head_Terminate, &Tail_Terminate, esecuzione_processo);
        }
    }

    printf("Stampa coda Terminata:\n");
    stampa_coda(Head_Terminate);

    return 0;
}