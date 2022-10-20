/*
FILE csv Anno Mese Giorno
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

typedef struct{
    char *nome;
    char *cognome;
    int aammgg;
}Dati;

int contaRighe(){
    FILE *fp;
    int k=0;
    char riga[1024];

    fp = fopen("file.csv","r");

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

    printf("%d", k);

    fclose(fp);

    return k;
}

void lettura(Dati* p){
    FILE *fp;
    char riga[1024];

    fp = fopen("file.csv","r");

    if(fp==NULL){
        printf("Erore nell'apertura del file.\n");
    }else {
        //fgets(riga,1024,fp);
            while (fgets(riga,1024,fp)){

                (*p).nome = strtok(riga,",");

                (*p).cognome = strtok(NULL, ",");

                (*p).aammgg = atoi(strtok(NULL, ","));

                *p++;

            }

        fclose(fp);
        free(fp);
    }

    return;

}

void ordinamento(Dati *p, int n){
    int k, sup;
    Dati t;

    Dati* a = p;
    
    for (sup = n-1; sup > 0; sup--) {

        p = a;
        
        for (k=0; k<sup; k++) {
            
            if ((*p).aammgg < (*p+1).aammgg){
                t=*(p);
                *(p)=*(p+1);
                *(p+1)=t;
            }

            p += 1;
        }
    }

    return;
}

int main(){
    Dati *pers;

    //pers = (Dati*)malloc(contaRighe()*sizeof(Dati));
    pers = (Dati*)malloc(4*sizeof(Dati));

    lettura(pers);
    //ordinamento(pers,contaRighe());
    ordinamento(pers,4);

    printf("%s %s %d", (*pers).nome, (*pers).cognome, (*pers).aammgg);

    return 0;
}