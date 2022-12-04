#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char name[20];
    struct node *next;
}Node;

int main(){

    Node *lista;
    Node *temp;

    lista = (Node*)malloc(sizeof(Node));
    temp = (Node*)malloc(sizeof(Node));

    char s[2];
    Node *p;

    p = lista;

    do{        
        printf("Inserisci un nome: \n");
        fflush(stdin);
        gets(p->name);

        lista->next=NULL;

        printf("\nContinuare?\n");
        fflush(stdin);
        gets(s);

        p = p->next;
        
    }while(strcmp(s,"si")==0);

    //FREE
    free(lista);
    free(temp);

    system("pause");
    return 0;
}

/*
    //PRIMO NOME
    printf("Inserisci un nome: \n");
    fflush(stdin);
    gets(lista->name);

    lista->next=NULL;

    printf("n1%s\n", lista->name);

    
    //SECONDO NOME
    printf("Inserisci un nome: \n");
    fflush(stdin);
    gets(temp->name);

    temp->next=NULL;
    lista->next=temp;

    printf("n2:%s\n", lista->next->name);

    //TERZO NOME
    printf("Inserisci un nome: \n");
    fflush(stdin);
    gets(temp->name);

    temp->next=NULL;
    lista->next->next=temp;

    printf("n3:%s\n", lista->next->next->name);
*/