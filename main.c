#include <stdio.h>
#include "translator.h"
#include "fasta_io.h"

void print_list(struct ProteinNode *node){
    if(node){
        printf("%s",node->polypeptide);
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
        printf("Erorre. Uso: %s <file.fasta>\n", argv[0]);
        return -1;
    }

    if(argv[1] == NULL){
        printf("Erorre. Non riesco ad aprire %s \n", argv[1]);
        return -1;
    }

    char *DnaSequence = read_fasta(argv[1]);

    char *RnaSequence = transcribe(DnaSequence);

    struct ProteinNode *head = translate(RnaSequence);
    
    struct ProteinNode *node = head;
    
    free(DnaSequence);
    free(RnaSequence);
    free_list(head);
    return 0;
}