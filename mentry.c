/**
@author Craig Cuthbertson
@login 1002386c
@title AP3 Exercise 1

This is my own work as defined in the Academic Ethics agreement I have signed.
REMEMBER TO CONVERT ARRAYS TO CHAR POINTERS IF TIME IS AVAILABLE.
*/

#include <stdio.h>
#include "mentry.h"
#include <string.h>

#define MAXLINE 500
#define MAXSURNAME 100
#define MAXPOSTCODE 10

/** Global variable pointing to a mailing list entry */
MEntry *me;

/**
Constructor, initialises the struct with information from file
*/
MEntry *me_get(FILE *fd){
	/** Temporary storage for reading in lines */
	char line1[MAXLINE+1] = {};
	char line2[MAXLINE+1] = {};
	char line3[MAXLINE+1] = {};

	/** loop counter */
	int i,j;

	if((me = (MEntry *)malloc(sizeof(MEntry))) != NULL){
		/** allocate memory on heap for entry */
		me->surname = malloc(sizeof(char)*MAXSURNAME);
		me->postcode = malloc(sizeof(char)*MAXPOSTCODE);
		me->full_address = malloc(sizeof(char)*MAXLINE*3);

		/** import data into temp storage */
		fgets(line1,MAXLINE,fd);
		fgets(line2,MAXLINE,fd);
		fgets(line3,MAXLINE,fd);

		/** Nothing left in file to input, return null */
		if(line1[0]=='\0'){
			return NULL;
		}

		/** Import full address by concatenating three lines */
		sprintf(me->full_address,"%s%s%s",line1,line2,line3);

		/** import surname (lowercase) to MEntry */
		for(i=0;line1[i]!=',';i++){
			me->surname[i] = (char)tolower(line1[i]);	
		}
		me->surname[i] = '\0';

		/** import house number to MEntry */
		me->house_number = atoi(line2);

		/** import postcode to MEntry removing spaces and non-alphanumeric chars */
		for(i=0,j=0;line3[i]!='\n';i++){
			if(isalnum(line3[i]) && line3[i]!=" "){
				me->postcode[j]=line3[i];
				j++;
			}
		}
		me->postcode[j] = '\0';

	}
	return me; 
}

/**
Returns a hash of a record
*/
unsigned long me_hash(MEntry *me, unsigned long size){

	unsigned hashval=0;
	unsigned temphash;
	int i;

	for(i=0,temphash=0;me->surname[temphash]!='\0';i++)
		temphash += (int) me->surname[i];

	hashval += temphash;

	for(i=0,temphash=0;me->postcode[temphash]!='\0';i++)
		temphash += (int) me->postcode[i];

	hashval += temphash;
	hashval += me->house_number;

	return (hashval%size);
}

/**
Outputs the details of a mentry to stdout
*/
void me_print(MEntry *me, FILE *fd){
	/**
	int i;
	/** Print full address 
	for(i=0;me->full_address[i]!='\0';i++){
		printf("%c",me->full_address[i]);
	} */

	fprintf(fd,"%s",me->full_address);
}

/**
Compares two mail entries to determine:
me1 = me2 (returns 0)
me1 < me2 (returns <0)
me1 > me2 (returns >0)
*/
int me_compare(MEntry *me1, MEntry *me2){

	if((strcmp(me1->surname,me2->surname)==0) && (strcmp(me1->postcode,me2->postcode)==0) && (me1->house_number == me2->house_number))
		return 0;
	else
		return -1;

/**

	if(strcmp(me1->surname,me2->surname)!=0)
		return -1;
	
	if(strcmp(me1->postcode,me2->postcode)!=0)
		return -1;
	
	if(me1->house_number == me2->house_number)
		return 0;

	return 1;*/
}

void me_destroy(MEntry *me){
	free(me->surname);
	free(me->full_address);
	free(me->postcode);
	free(me);
}
