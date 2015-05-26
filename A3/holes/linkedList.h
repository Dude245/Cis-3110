#ifndef BOOL_H
#define BOOL_H
typedef int bool;

enum {
    false, true
};


/* this header file outlines all of the required functions for your linked list
   and the struct.  you may, of course, add any functions you wish.  This is the minimum set */

/*define your struct here */
#endif
#ifndef myList
#define myList
#include <stdio.h>
#include <stdlib.h>
struct linkedRecord {
    char *id;
    int movie;
    int snack;
    int time;
    int tTime;
    struct linkedRecord *nextPtr;
};

/*fix this typedef so that it refers properly to your struct*/
typedef struct linkedRecord Patron;



typedef Patron * ListHeadPtr;


/*********************
REQUIRED
Linked List functions
 *************************/


/*This function returns true if the list is empty and false in all other cases.  
  The function does not change the list in any way */

bool isEmpty(ListHeadPtr theList);



/*This function adds the node sent in as a parameter to the front of the list that
  is given as a parameter.  The function returns the new head of the list.  */
ListHeadPtr addToFront(ListHeadPtr theList, int value);

/*This function removes the first item from the given list,  sets the next pointer of that item to NULL
  and returns a pointer to the new head of the list (the item that was the second item*/
ListHeadPtr removeFromFront(ListHeadPtr theList);


/*This function returns a pointer to the item that is at the front of the list. 
  It does not change the list in any way */
Patron * getFront(ListHeadPtr theList);

/*This function adds the node sent as a parameter to the back of the list sent in as a parameter.
  It returns a pointer to the head of the list */
ListHeadPtr addToBack(ListHeadPtr theList, int value);

/*This function removes the last item from the list and returns a pointer
  to the head of the list. The function sets the next pointer of the new last 
item to NULL and it sets the next pointer of the removed item to NULL */
ListHeadPtr removeFromBack(ListHeadPtr theList);

/*This function returns a pointer to the last item in the linked list that is
  given as a parameter.  The function does not change the list in any way */
Patron * getBack(ListHeadPtr theList);

/*this function must print the patron ID for each patron in the list to a string beginning with 
the front of the list. The 
Patron Ids must be printed one per line with a newline immediately following the id.
The function should return the string */
char * printList(ListHeadPtr theList);

bool list();
/*this function must return the number of patrons in the list */
int length(ListHeadPtr theList);

/*this function should free all the memory for the list, except possibly the head pointer
  which will need to be freed separately */
void destroyPatronList(ListHeadPtr theList);


/***********
REQUIRED
Patron functions
 ************/

/*This list must take in four parameters and return a pointer to 
  a patron struct*/
Patron * createPatron(char * id, bool movie, bool snack, int time);

/*This function must return a pointer to the ID of the Patron.  It should
  not allocate extra memory */
char * getID(Patron * thePatron);

/*This function should return the amount of time that a patron takes
  to purchase items */
int getTime(Patron * thePatron);

/*this function should return a boolean indicating whether or not the Patron
  is attending the movie */
bool getMovie(Patron * thePatron);

/*this function should return a boolean indicating whether or not the Patron
  is purchasing a snack */
bool getSnack(Patron * thePatron);

/*this function should free any memory allocated to the patron and 
should set all of the non-dynamic variables to a default value.  The pointer
to the patron will have to be freed separately */
void destroyPatron(Patron * thePatron);


/*This function is for testing purposes only and doesn't belong in a linked list 
implementation.  Please include it so we can use it to test your software.  It should
return the pointer to the 'next' item in the linked list, given a patron pointer as a parameter */
Patron * getNextPatron(Patron * thePatron);

/*Opens a file pointer*/
FILE * openFile(char * fileName);

/*Reads the entire next line of the file*/
char * readNextLine(FILE * filePointer);

/*Gets the next delimted token*/
char * getNextToken(char * line);
#endif