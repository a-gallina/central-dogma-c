#include <stdio.h>
#include "translator.h"
#include "fasta_io.h"

int main(int argc, char *argv[]){

    if(argc != 2){
        pritnf("Erorre. Uso: %s <file.fasta>\n", argv[0]);
        return -1;
    }

    if(argv[1] == NULL){
        pritnf("Erorre. Non riesco ad aprire %s \n", argv[1]);
        return -1;
    }

    char DnaSequence[1000] = read_fasta(argv[1]);

    char RnaSequence[1000] = trancribe(DnaSequence);

    struct ProteinNode *node = translate(RnaSequence);
    
    while(node){
        printf("%s\n", node->polypeptide);
        node = node->next;
    }

    return 0;
}