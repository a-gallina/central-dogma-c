#include <stdio.h>
#include <stdlib.h>
#include "translator.h"
#include "fasta_io.h"

void print_list(struct ProteinNode *node){
    if(node != NULL){
        printf("Polipeptide trovato: %s\n", node->polypeptide);
        print_list(node->next);
    }
}

void free_list(struct ProteinNode *node){
    if(node != NULL){
        free_list(node->next);
        free(node);
    }    
}

int main(int argc, char *argv[]){

    if(argc != 2){
        printf("Errorre. Uso: %s <file.fasta>\n", argv[0]);
        return -1;
    }

    char *DnaSequence = read_fasta(argv[1]);
    if(DnaSequence == NULL){
        return -1;
    }

    char *RnaSequence = transcribe(DnaSequence);
    if(RnaSequence == NULL){
        free(DnaSequence);
        return -1;
    }
    
    struct ProteinNode *head = translate(RnaSequence);
    
    print_list(head);
    
    free(DnaSequence);
    free(RnaSequence);
    free_list(head);
    return 0;
}