#include <stdio.h>
#include <stdlib.h>

struct Node {
    int Data;
    char ID;
    int ran;
    int pos;
    int isOld;
    struct Node* nextPtr;
} *rear, *front, Node;

void addToBack(int value, char ID, int pos, int ran, int isOld) {
    struct Node *temp;
    temp = (struct Node *) malloc(sizeof (struct Node));
    temp->Data = value;
    temp->ID = ID;
    temp->pos = pos;
    temp->ran = ran;
    temp->isOld = isOld;
    if (front == NULL) {
        front = temp;
        front->nextPtr = NULL;
        rear = front;
    } else {
        front->nextPtr = temp;
        front = temp;
        front->nextPtr = NULL;
    }
}

struct Node lookUp(char ID) {
    struct Node *temp = rear;
    while (temp != NULL) {
        if (temp->ID == ID) {
            // found it!
            return *temp;
            break;
        }
        temp = temp->nextPtr;
    }
    return * temp->nextPtr;
}

struct Node getRemove() {
    int min = 999;
    struct Node *oldNode;
    struct Node *temp = rear;
    while (temp != NULL) {
        if (temp->isOld < min && temp->isOld != 0 && temp->ran >= 1) {
            min = temp->isOld;
            oldNode = temp;
        }
        temp = temp->nextPtr;
    }
    return *oldNode;
}

void setRan(int ran) {
    struct Node *currentPtr = rear;
    currentPtr->ran = ran;

}

struct Node getFront() {
    struct Node *currentPtr = rear;
    return *currentPtr;

}

struct Node getBack() {
    struct Node *currentPtr = front;
    return *currentPtr;

}

int checkNumArray(int numProc) {
    int ran = 1;
    struct Node *temp = rear;
    while (temp != NULL) {
        if (temp->ran == 3) {
            ran = ran + 1;
        }
        temp = temp->nextPtr;
    }
    if (ran == numProc) {
        return 1;
    } else {
        return 0;
    }

}

int checkMem(char * procA) {
    int numPro = 0;
    for (int i = 0; i < 128; i++) {
        if (procA[i] != '-') {
            numPro++;
        }
    }
    return numPro;
}

int checkHoles(char * procA) {
    int endFound = 0;
    int numHoles = 1;
    for (int i = 0; i < 128; i++) {

        if (procA[i] == '-') {
            for (int j = i; j < 128; j++) {
                if (procA[j] != '-' && procA[j + 1] != '-') {
                    endFound++;
                }

            }
            if (endFound == 1) {
                numHoles++;
            }
        }


    }
    if (numHoles > 4)
        numHoles = 2;

    return numHoles;
}

int checkProc(char * procA) {
    int numPro = 0;
    struct Node *temp = rear;
    while (temp != NULL) {
        for (int i = 0; i < 128; i++) {
            if (temp->ID == procA[i] && procA[i] != procA[i + 1]) {
                numPro++;
            }
        }

        temp = temp->nextPtr;

    }

    return numPro;
}

void changeOld(char ID) {
    int max = 0;
    struct Node *lTemp = rear;
    while (lTemp != NULL) {
        if (lTemp->isOld > max && lTemp->isOld != 0 && lTemp->ran >= 1) {
            max = lTemp->isOld;
        }
        lTemp = lTemp->nextPtr;
    }
    struct Node *temp = rear;
    while (temp != NULL) {
        if (temp->ID == ID) {
            // found it!
            temp->isOld = temp->isOld + max + 1;
            break;
        }
        temp = temp->nextPtr;
    }

}

void addToFront(int value) {
    struct Node *currentPtr = rear;
    currentPtr->nextPtr = rear;

    // Set first to new node
    rear = currentPtr;

}
//Doesnt Works

void setValues(int ran, int pos) {

    struct Node *currentPtr = rear;
    //printf("ID %c  POS %d\n",currentPtr->ID,currentPtr->pos);
    currentPtr->ran = ran;
    currentPtr->pos = pos;
}

void removeFromFront() {

    struct Node *currentPtr = rear;
    currentPtr = currentPtr->nextPtr;
    rear = currentPtr;

}

void killList() {
    struct Node *currentPtr = rear;
    while (currentPtr->nextPtr != NULL) {
        rear = currentPtr;

        currentPtr = currentPtr->nextPtr;
    }


}

void removeFromBack() {

    struct Node *currentPtr = rear;
    struct Node * prePtr;
    prePtr = (struct Node *) malloc(sizeof (struct Node));
    while (currentPtr->nextPtr != NULL) {
        prePtr = currentPtr;
        currentPtr = currentPtr->nextPtr;

    }
    prePtr->nextPtr = NULL;

}

int display() {
    struct Node *var = rear;
    if (var != NULL) {

        while (var != NULL) {
            // printf("ID: %c ",var->ID);
            // printf("Data: %d ",var->Data);
            // printf("Ran: %d ",var->ran);
            // printf("Old: %d \n",var->isOld);
            // printf("Pos: %d \n",var->pos);
            //printf("Num %d\n",num );

            var = var->nextPtr;

        }
        printf("\n");
        return 1;
 
    } else
        //printf("\nQueue is Empty \n");
        return 0;
}
void bFit(int * sizes, char * ID, int theSize);
void wFit(int * sizes, char * ID, int theSize);
void nFit(int * sizes, char * ID, int theSize);
void fFit(int * sizes, char * ID, int theSize);
void memPrint(char * procA);
void addNext(char * procA, int numProc);
void rMem(char * procA, struct Node cNode);
