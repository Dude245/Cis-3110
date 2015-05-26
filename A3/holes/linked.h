#include <stdio.h>
#include <stdlib.h>
#include "linked.c"


void addToBack(int value, char ID, int pos, int ran, int isOld);

struct Node lookUp(char ID);

struct Node getRemove();

void setRan(int ran);

struct Node getFront();

struct Node getBack();

int checkNumArray(int numProc);

int checkMem(char * procA);

int checkHoles(char * procA);

int checkProc(char * procA);

void changeOld(char ID);

void addToFront(int value);

void setValues(int ran, int pos);

void removeFromFront();

void killList();

void removeFromBack();

int display();

void bFit(int * sizes, char * ID, int theSize);

void wFit(int * sizes, char * ID, int theSize);

void nFit(int * sizes, char * ID, int theSize);

void fFit(int * sizes, char * ID, int theSize);

void memPrint(char * procA);

void addNext(char * procA, int numProc);

void rMem(char * procA, struct Node cNode);
