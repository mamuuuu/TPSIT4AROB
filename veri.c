#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LUNG 1024
#define N_ALUNNI 22
#define NOME "Meinero"
//AUTHOR: MEINERO SAMUELE

typedef struct{
    char *nome;
    int euro;
}Alunno;

typedef struct{
    char *cognome;
    int quota;
}mioNome;

void ricercaNome(Alunno* alunni, int _dim) {
    Alunno controllo;
    controllo.nome = NULL;
    controllo.euro = 0;

    for(Alunno* a = alunni; a - alunni < _dim; a ++) {
        if(!strcmp(NOME, a->nome)) {
            if(controllo.nome == NULL)
                controllo.nome = a->nome;
            controllo.euro += a->imp;
        }
    }

    if(controllo.nome == NULL)
        printf("il nome %s non è presente\n", NOME);
    else if(controllo.euro > QUOTA)
        printf("l'alunno %s ha pagato %d in più della quota prevista di %d\n", controllo.nome, controllo.imp - QUOTA, QUOTA);
    else if(controllo.euro == QUOTA)
        printf("l'alunno %s ha pagato la quota prevista di %d\n", controllo.nome, QUOTA);
    else
        printf("l'alunno %s ha pagato %d in meno della quota prevista di %d\n", controllo.nome, QUOTA - controllo.imp, QUOTA);
}

bool alunnoGiaInserito(Alunno* alunni, Alunno a, int _dim) {
    for(Alunno* p = alunni; p - alunni < _dim; p++)
        if(!strcmp(p->nome, a.nome))
            return true;
    return false;
}

void stampaALunni(Alunno* alunni, int _dim) {
    for(Alunno* a = alunni; a- alunni < _dim; a ++) {
        printf("%s %d", a->nome, a->imp);
        if(a->imp != QUOTA)
            printf(" -- da controllare");
        printf("\n");
    }
}

void incrementaQuota(Alunno* alunni, Alunno a, int _dim) {
    for(Alunno* p = alunni; p - alunni < _dim; p ++)
        if(!strcmp(p->nome, a.nome)) {
            p->imp += a.imp;
            return;
        }
}

void setAlunni_3(Alunno* alunni, int _dim) {
    Alunno* alunni2 = (Alunno*) malloc(sizeof(Alunno) * _dim);
    Alunno* p2 = alunni2;
    int _dim_2 = 0;

    for(Alunno* p = alunni; p - alunni < _dim; p ++) {
        if(!alunnoGiaInserito(alunni2, *p, _dim_2)) {
            *p2 = *p;
            p2 ++;
            _dim_2 ++;
        } else
            incrementaQuota(alunni2, *p, _dim_2);
    }

    stampaALunni(alunni2, _dim_2);
    free(alunni2);
}

int conta(int l){
    int righe =0;
    char c[l];
    char *riga=c;

    FILE *fp;

    fp = fopen("4AROB_GITA.csv","r");

    if (fp == NULL){
        printf("Il file non esiste.");
    }else {
        while (fgets(riga,l,fp)){
            righe ++;
        }
    }

    fclose(fp);

    return righe;
}

void carica (Alunno* a, int dim, int lung){
    FILE* fp;
    char c[lung];
    char* riga = c;
    Alunno* posizione = a;

    fp = fopen("4AROB_GITA.csv", "r");

    if(fp != NULL){
        for(a = posizione; a < posizione + dim; a++){
            fgets(riga, lung, fp);

            strtok(riga,";");
            a->nome = strdup(strtok(NULL, ";"));
            a->euro = atoi(strtok(NULL,";"));

            printf("%s %d\n", a->nome, a->euro);
        }
        a = posizione;
    }else
        printf("Il file non esiste\n");

    fclose(fp);
}

int incasso(Alunno *a, int dim){
    int tot = 0;

    Alunno *pos = a;

    for (a = pos; a < pos +dim; a++){
        tot = tot + a->euro;
    }

    return tot;
}

void nome (mioNome* io, Alunno *classe, int dim, int lung){
    FILE* fp;
    char c[lung];
    char* riga = c;
    Alunno* pos = classe;

    char s [LUNG];

    int tot = 0;

    printf("\nInserisci il tuo cognome: ");
    fflush(stdin);
    gets(s);

    strcpy(io->cognome,s);

    for (classe = pos; classe < pos + dim; classe++){
        if (strcmp(s,classe->nome)==0)
            tot = tot + classe->euro;
    }

    io->quota=tot;

    if (tot == 100){
        printf("Ha pagato tutta la quota");
    }else {
        printf("Non ha pagato tutta la quota");
    }

}

int main(){

    Alunno *classe;
    mioNome io;
    mioNome *riepilogo;
    int tot_euro;

    int dim = conta(LUNG);

    classe =(Alunno*)malloc(dim*sizeof(Alunno));
    riepilogo = (mioNome*)malloc(dim*sizeof(mioNome));

    carica(classe,dim,LUNG);
    
    tot_euro = incasso(classe,dim);

    if (tot_euro < 2200){
        printf("Mancano %d", 2200-tot_euro);
    }
    if (tot_euro > 2200){
        printf("Ci sono in più %d", tot_euro-2200); 
    }
            
    ricercaNome(classe,dim);
    setAlunni_3(classe,dim);

    free(classe);

    system("pause");
    return 0;
}