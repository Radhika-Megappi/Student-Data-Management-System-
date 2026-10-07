#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    int rollno;
    char name[50];
    float percentage;
    struct student *next;
} SLL;

void addRecord(SLL **);

void deleteNode(SLL **);
void deleteAll(SLL **);

void printNode(SLL *);

void modifyNode(SLL *);

void saveFile(SLL *);
void readFile(SLL **);

void sortData(SLL *);
void reverseLinks(SLL **);

