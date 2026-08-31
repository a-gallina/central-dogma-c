#ifndef FASTA_IO_H
#define FASTA_IO_H

void *trancribe(const char *dna, const char *rna);
void *translate(const char *rna, const char *protein);

struct ProteinNode{
    char *polypeptide;
    struct ProteinNode *next;
};

#endif