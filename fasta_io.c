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
    char sequence[] = "";

    while(fgets(buffer, sizeof(buffer), file) != NULL){

        buffer[strcspn(buffer, "\n")] = 0;

        if(buffer[0] == '>') { //se la riga e' una intestazione(inizia con >)
            printf("Trovata intestazione: %s\n", buffer);

        }
        else{
            printf("Letta sequenza: %s\n", buffer);
            strcat(sequence, buffer);
        }
    }
    *sequence = '/0';

    char *result = malloc(strlen(sequence) + 1);
    strcpy(result, sequence);

    fclose(file);
    return result;
}