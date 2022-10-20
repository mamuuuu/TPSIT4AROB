/*
Creare un programma in linguaggio C che legga il file vgsales.csv e lo importi in un array di strutture.
Ogni riga contiene i campi separati da virgole, per cui pu� essere comodo creare una funzione split
che dalla riga letta ritorni la struttura valorizzata.
*/

//FILE CSV, Comma Separated Values
//CPP reference
//Author: Samuele Meinero

/*
REALLOC->

*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define LUNG 100
#define DIM 1024
#define NUM 16599

typedef struct{
    int rank;
    char *name;
    char *platform;
    int year;
    char *genre;
    char *publisher;
    float na_sales;
    float eu_sales;
    float jp_sales;
    float other_sales;
    float global_sales;

}Gioco;

int contaRighe(){
    FILE *fp;
    int k=0;
    char riga[1024];

    fp = fopen("vgsales.csv","r");

    if(fp==NULL){
        printf("Erore nell'apertura del file.\n");
        return 0;
    }else {
        printf("Aperto.\n");
    }

    fgets(riga,1024,fp);

    while (!feof(fp)){
        fgets(riga,1024,fp);
        k++;
    }

    fclose(fp);

    return k;
}


int main (){

    Gioco *p;
    FILE *fp;

    p = (Gioco*)malloc(contaRighe()*sizeof(Gioco));

    char *riga;
    int k=0;

    fp = fopen("vgsales.csv","r");

    if(fp==NULL){
        printf("Erore nell'apertura del file.\n");
        return 0;
    }else {
        printf("Aperto.\n");
    }
    
    riga = (char*)malloc(1024*sizeof(char));
    fgets(riga,1024,fp);
    riga = (char*)realloc(riga, (strlen(riga)+1)*sizeof(char));
    

    while (fgets(riga,1024,fp) != EOF){

        riga = (char*)malloc(strlen(riga)*sizeof(char));
        (*p).rank = atoi(strtok(riga,","));

        (*p).name = strtok(NULL, ",");

        (*p).platform = strtok(NULL, ",");

        (*p).year = atoi(strtok(NULL,","));

        (*p).genre = strtok(NULL, ",");

        (*p).publisher = strtok(NULL, ",");

        (*p).na_sales = atof(strtok(NULL,","));

        (*p).eu_sales = atof(strtok(NULL,","));

        (*p).jp_sales = atof(strtok(NULL,","));

        (*p).other_sales = atoi(strtok(NULL,","));

        (*p).global_sales = atof(strtok(NULL,","));

        printf("%d %s %s %d %s %s %.2f %.2f %.2f %.2f %.2f\n", (*p).rank, (*p).name, (*p).platform, (*p).year, (*p).genre,
                (*p).publisher, (*p).na_sales, (*p).eu_sales, (*p).jp_sales, (*p).other_sales, (*p).global_sales);

        *p++;

    }

    fclose(fp);
    free(p);

    return 0;
}

/*
int main (){

    Gioco *p;
    FILE *fp;

    p = (Gioco*)malloc(contaRighe()*sizeof(Gioco));

    char riga[1024];
    int k=0;

    fp = fopen("vgsales.csv","r");

    if(fp==NULL){
        printf("Erore nell'apertura del file.\n");
        return 0;
    }else {
        printf("Aperto.\n");
    }

    fgets(riga,1024,fp);

    while (fgets(riga,1024,fp) != EOF){

        (*p).rank = atoi(strtok(riga,","));

        (*p).name = strtok(NULL, ",");

        (*p).platform = strtok(NULL, ",");

        (*p).year = atoi(strtok(NULL,","));

        (*p).genre = strtok(NULL, ",");

        (*p).publisher = strtok(NULL, ",");

        (*p).na_sales = atof(strtok(NULL,","));

        (*p).eu_sales = atof(strtok(NULL,","));

        (*p).jp_sales = atof(strtok(NULL,","));

        (*p).other_sales = atoi(strtok(NULL,","));

        (*p).global_sales = atof(strtok(NULL,","));

        printf("%d %s %s %d %s %s %.2f %.2f %.2f %.2f %.2f\n", (*p).rank, (*p).name, (*p).platform, (*p).year, (*p).genre,
                (*p).publisher, (*p).na_sales, (*p).eu_sales, (*p).jp_sales, (*p).other_sales, (*p).global_sales);

        *p++;
    }

    fclose(fp);
    free(p);

    return 0;
}
*/


