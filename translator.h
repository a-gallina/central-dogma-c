#ifndef FASTA_IO_H
#define FASTA_IO_H

char *trancribe(const char *dna);
struct ProteinNode *translate(const char *rna);

struct ProteinNode{
    char *polypeptide;
    struct ProteinNode *next;
};

#endif