#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "translator.h"

struct ProteinNode *create_list (struct ProteinNode *head, char *protein){
    if(protein == NULL || protein[0] == '\0')
        return head;

    
    struct ProteinNode *newNode = malloc(sizeof(struct ProteinNode)); //creo il nuovo nodo
    if(newNode == NULL){
        fprintf(stderr, "Errore, memoria insufficiente\n");
        return head;
    }

    char *newProtein = malloc(strlen(protein) + 1); //creo spazio per il nome della nuova proteina
    if(newProtein == NULL){
        fprintf(stderr, "Errore, memoria insufficiente\n");
        return head;
    }

    strcpy(newProtein, protein);
           
    //faccio puntare il nuovo nodo allo spazio creato per il nome della proteina
    newNode->polypeptide = newProtein;
    newNode->next = NULL;
        
    if(head != NULL){
        struct  ProteinNode *list = head;
        
        while(list->next != NULL) //arrivo in fondo alla lista
            list = list->next;

        list->next = newNode; //in fondo alla lista aggiungo il nuovo nodo
            
    }
    else{
        head = newNode;
    }
    return head;
    
}

char *transcribe(const char *dna){
    char *rna = malloc(strlen(dna) + 1);
    int i = 0;
    while(dna[i] != '\0'){
        if(dna[i] == 'T')
            rna[i] = 'U';
        else
            rna[i] = dna[i];
    
        i++;
    }
    rna[i] = '\0';
    
    return rna;
}

struct ProteinNode *translate(const char *rna){
    int max_len = strlen(rna) + 1;
    char *protein = calloc(max_len, sizeof(char));
    struct ProteinNode *result = NULL;
    int writing = 0;
    char *aminoacid;
    int i = 1;
    while(*rna != '\0'){
        aminoacid = "";
        if (strlen(rna) < 3) {
            break; 
        }
        
        switch(*rna){
            
            case 'U':

                switch(*(rna + 1)){

                    case 'U':
                    switch (*(rna + 2)){
                        case 'U': case 'C': aminoacid = "Phe"; break;
                        case 'A': case 'G': aminoacid = "Leu";
                    }
                    break;

                    case 'C': aminoacid = "Ser";
                    break;

                    case 'A':
                    switch (*(rna + 2)){
                        case 'U': case 'C': aminoacid = "Tyr"; break;
                        case 'A': case 'G': aminoacid = "Stop";
                    }
                    break;

                    case 'G':
                    switch (*(rna + 2)){
                        case 'U': case 'C': aminoacid = "Cys"; break;
                        case 'A': aminoacid = "Stop"; break;
                        case 'G': aminoacid = "Trp";
                    }
                }
            break;

            case 'C':

                switch(*(rna + 1)){

                    case 'U': aminoacid = "Leu";
                    break;

                    case 'C': aminoacid = "Pro";
                    break;

                    case 'A':
                    switch (*(rna + 2)){
                        case 'U': case 'C': aminoacid = "His"; break;
                        case 'A': case 'G': aminoacid = "Gln";
                    }
                    break;

                    case 'G': aminoacid = "Arg";
                }
            break;

            case 'A':

                switch(*(rna + 1)){

                    case 'U':
                    switch (*(rna + 2)){
                        case 'U': case 'C': case 'A': aminoacid = "Ile"; break;
                        case 'G': aminoacid = "Met";
                    }
                    break;

                    case 'C': aminoacid = "Thr";
                    break;

                    case 'A':
                    switch (*(rna + 2)){
                        case 'U': case 'C': aminoacid = "Asn"; break;
                        case 'A': case 'G': aminoacid = "Lys"; 
                    }
                    break;

                    case 'G':
                    switch (*(rna + 2)){
                        case 'U': case 'C': aminoacid = "Ser"; break;
                        case 'A': case 'G': aminoacid = "Arg";
                    }
                }
            break;

            case 'G':

                switch(*(rna + 1)){

                    case 'U': aminoacid = "Val";
                    break;

                    case 'C': aminoacid = "Ala";
                    break;

                    case 'A':
                    switch (*(rna + 2)){
                        case 'U': case 'C': aminoacid = "Asp"; break;
                        case 'A': case 'G': aminoacid = "Glu"; 
                    }
                    break;

                    case 'G': aminoacid = "Gly";
                }
        }

        if( !writing && !strcmp(aminoacid,"Met")){
            i = 3;
            writing = 1;
        }

        if( !strcmp(aminoacid, "Stop")){
            if(writing){
                result = create_list(result, protein);
            }
            writing = 0;
            i = 1;
            protein[0] = '\0';
        }    
        else if(writing){
            strcat(protein, aminoacid);
        }

        rna += i;
    }
    if(writing && protein[0] != '\0')
        result = create_list(result, protein);
    
    free(protein);
    return result;
}

