#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_fasta(const char *filename){
    FILE *file = fopen(filename, "r"); //apertura file in lettura

    if(file == NULL){
        printf("Errore lettura file");
        return NULL;
    }

    char buffer[256]; //legge una riga
    char *sequence = calloc(10000, sizeof(char));
    if(sequence == NULL){
        fprintf(stderr, "Errore, memoria insufficiente\n");
        fclose(file);
        return NULL;
    }

    while(fgets(buffer, sizeof(buffer), file) != NULL){

        buffer[strcspn(buffer, "\n")] = 0;//rimuove andata a capo

        if(buffer[0] == '>') { //se la riga e' una intestazione(inizia con >)
            printf("Trovata intestazione: %s\n", buffer);
        }

        else{
            printf("Letta sequenza: %s\n", buffer);
            strcat(sequence, buffer);
        }
    }
    printf("\n");

    fclose(file);
    return sequence;
}