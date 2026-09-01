#ifndef TRANSLATOR_H
#define TRANSLATOR_H

char *transcribe(const char *dna);
struct ProteinNode *translate(const char *rna);

struct ProteinNode{
    char *polypeptide;
    struct ProteinNode *next;
};

#endif