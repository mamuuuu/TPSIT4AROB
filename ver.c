#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define QUOTA 100
#define MAX_INC 2200

typedef char* String;

typedef struct {
    String nome;
    int imp;
} Alunno;

bool existFile() {
    bool ret;
    FILE* fp = fopen("4AROB_GITA.csv", "r");
    if(fp == NULL)
        ret = false;
    else
        ret = true;
    fclose(fp);
    
    return ret;
}

int dim() {
    FILE* fp = fopen("4AROB_GITA.csv", "r");
    int righe = 0;
    String line = (String) malloc(1024 * sizeof(char));
    while(fgets(line, 1024 , fp))
        righe ++;
    free(line);
    fclose(fp);
    return righe;
}

void readFile(Alunno* alunni) {
    Alunno* a = alunni;
    FILE* fp = fopen("4AROB_GITA.csv", "r");

    String line = (String) malloc(sizeof(char) * 1024);
    while (fgets(line, 1024, fp)) {
        String s = strdup(strtok(line, ";"));
        a->nome = strdup(strtok(NULL, ";"));
        a->imp = atoi(strtok(NULL, ";"));
        a ++;
    }
    free(line);
    fclose(fp);
}

void printIncassi(Alunno* alunni, int _dim) {
    int n = 0;
    for(Alunno* a = alunni; a - alunni < _dim; a ++)
        n += a->imp;

    printf("incasso: %d\n", n);
    if(n < MAX_INC)
        printf("mancano ancora %d euro a %d (%d)\n", MAX_INC - n, MAX_INC, n);
    else if( n > MAX_INC)
        printf("ci sono %d in più di %d (%d)\n", n - MAX_INC, MAX_INC, n);
}

void ricercaNome(Alunno* alunni, int _dim) {
    Alunno controllo;
    controllo.nome = NULL;
    controllo.imp = 0;

    for(Alunno* a = alunni; a - alunni < _dim; a ++) {
        if(!strcmp("Meinero", a->nome)) {
            if(controllo.nome == NULL)
                controllo.nome = a->nome;
            controllo.imp += a->imp;
        }
    }

    if(controllo.nome == NULL)
        printf("il nome Meinero non è presente\n");
    else if(controllo.imp > QUOTA)
        printf("l'alunno %s ha pagato %d in più della quota prevista di %d\n", controllo.nome, controllo.imp - QUOTA, QUOTA);
    else if(controllo.imp == QUOTA)
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

int main() {
    if(!existFile()) {
        printf("il file non esiste");
        return 0;
    }

    int _dim = dim();
    Alunno* alunni = (Alunno*) malloc(sizeof(Alunno) * _dim);

    readFile(alunni);
    printIncassi(alunni, _dim);
    ricercaNome(alunni, _dim);
    setAlunni_3(alunni, _dim);

    free(alunni);
    return 0;
}
