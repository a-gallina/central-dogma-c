#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct ProteinNode{
    char *polypeptide;
    struct ProteinNode *next;
};

struct ProteinNode *create_list (struct ProteinNode *head, char *protein){
    if(protein != NULL){
        struct ProteinNode *NewNode = malloc(sizeof(struct ProteinNode)); //creo il nuovo nodo
        char *NewProtein = malloc(strlen(protein) + 1); //creo spazio per il nome della nuova proteina
        strcpy(NewProtein, protein);
            
        //faccio puntare il nuovo nodo allo spazio creato per il nome della proteina
        NewNode->polypeptide = NewProtein;
        NewNode->next = NULL;
        
        if(head != NULL){
            struct  ProteinNode *list = head;
        
            while(list->next != NULL) //arrivo in fondo alla lista
                list = list->next;

            list->next = NewNode; //in fondo alla lista aggiungo il nuovo nodo
            
        }
        else{
            head = NewNode;
        }
        return head;
    }
}

char *transcribe(const char *dna){
    char *rna = malloc(strlen(dna) + 1);
    int i = 0;
    while(dna[i] != '\0'){
        if(dna[i] == 'T')
            rna[i] == 'U';
        else
            rna[i] == dna[i];
    
        i++;
    }
    rna[i] == '\0';
    
    return rna;
}

struct ProteinNode *translate(const char *rna){
    char protein[1000] = "";
    struct ProteinNode *result = NULL;
    int writing = 0;
    char *amminoacid;
    int i = 1;
    while(*rna != '\0'){
        amminoacid = "";
        if (strlen(rna) < 3) {
            break; 
        }
        
        switch(*rna){
            
            case 'U':

                switch(*(rna + 1)){

                    case 'U':
                    switch (*(rna + 2)){
                        case 'U': case 'C': amminoacid = "Phe"; break;
                        case 'A': case 'G': amminoacid = "Leu";
                    }
                    break;

                    case 'C': amminoacid = "Ser";
                    break;

                    case 'A':
                    switch (*(rna + 2)){
                        case 'U': case 'C': amminoacid = "Tyr"; break;
                        case 'A': case 'G': amminoacid = "Stop";
                    }
                    break;

                    case 'G':
                    switch (*(rna + 2)){
                        case 'U': case 'C': amminoacid = "Cys"; break;
                        case 'A': amminoacid = "Stop"; break;
                        case 'G': amminoacid = "Trp";
                    }
                }
            break;

            case 'C':

                switch(*(rna + 1)){

                    case 'U': amminoacid = "Leu";
                    break;

                    case 'C': amminoacid = "Pro";
                    break;

                    case 'A':
                    switch (*(rna + 2)){
                        case 'U': case 'C': amminoacid = "His"; break;
                        case 'A': case 'G': amminoacid = "Gln";
                    }
                    break;

                    case 'G': amminoacid = "Arg";
                }
            break;

            case 'A':

                switch(*(rna + 1)){

                    case 'U':
                    switch (*(rna + 2)){
                        case 'U': case 'C': case 'A': amminoacid = "Ile"; break;
                        case 'G': amminoacid = "Met";
                    }
                    break;

                    case 'C': amminoacid = "Thr";
                    break;

                    case 'A':
                    switch (*(rna + 2)){
                        case 'U': case 'C': amminoacid = "Asn"; break;
                        case 'A': case 'G': amminoacid = "Lys"; 
                    }
                    break;

                    case 'G':
                    switch (*(rna + 2)){
                        case 'U': case 'C': amminoacid = "Ser"; break;
                        case 'A': case 'G': amminoacid = "Arg";
                    }
                }
            break;

            case 'G':

                switch(*(rna + 1)){

                    case 'U': amminoacid = "Val";
                    break;

                    case 'C': amminoacid = "Ala";
                    break;

                    case 'A':
                    switch (*(rna + 2)){
                        case 'U': case 'C': amminoacid = "Asp"; break;
                        case 'A': case 'G': amminoacid = "Glu"; 
                    }
                    break;

                    case 'G': amminoacid = "Gly";
                }
        }

        if( !strcmp(amminoacid,"Met")){
            i = 3;
            writing = 1;
        }

        if( !strcmp(amminoacid, "Stop")){
            writing = 0;
            i = 1;
            result = create_list(result, protein);
            protein[0] = '\0';
        }    
        
        if(writing)
            strcat(protein, amminoacid);

        rna += i;
    }
    return result;
}

