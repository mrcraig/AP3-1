/**
@author Craig Cuthbertson
@login 1002386c
@title AP3 Exercise 1

This is my own work as defined in the Academic Ethics agreement I have signed.
*/

#include <stdio.h>
#include "mentry.h"
#include <string.h>

#define MAXLINE 500
#define MAXSURNAME 100
#define MAXPOSTCODE 10
#define HASHSIZE 101

/** Global variable pointing to a mailing list entry */
MEntry *me;

/**
Constructor, initialises the struct with information from file
*/
MEntry *me_get(FILE *fd){
	/** Temporary storage for reading in lines */
	char line1[MAXLINE+1];
	char line2[MAXLINE+1];
	char line3[MAXLINE+1];

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
		
		/** Import full address */
		for(i=0;line1[i]!='' && line1[i]!='\0';i++)
			me->full_address[i] = line1[i];
		j = i;
		
		for(i=0;line2[i]!='' && line2[i]!='\0';i++)
			me->full_address[(j+i)] = line2[i];
		j += i;

		for(i=0;line3[i]!='' && line3[i]!='\0';i++)
			me->full_address[(j+i)] = line3[i];

		/** import surname (lowercase) to MEntry */
		for(i=0;line1[i]!=',';i++){
			me->surname[i] = (char)tolower(line1[i]);	
		}

		/** import house number to MEntry */
		me->house_number = strtol(line2,NULL,10);

		/** import postcode to MEntry */
		for(i=0;line3[i]!='\n';i++){
			if(isalnum(line3[i]) && line3[i]!=' ')
				me->postcode[i]=line3[i];
		}

	}
	return me; 
}

/**
Returns a hash of a record
*/
unsigned long me_hash(MEntry *me, unsigned long size){
/**
	unsigned hashvalue;
	
	for(hashvalue = 0; *me != '\0'; me++)
		hashvalue = *me + 31 * hashvalue;
	return hashvalue % sizeof(MEntry);*/

	unsigned hashval=0;
	unsigned temphash;
	int i;

	for(i=0,temphash=0;me->surname[temphash]!='\0';i++)
		temphash *= (int) me->surname[i];

	hashval += (temphash % MAXSURNAME);

	for(i=0,temphash=0;me->postcode[temphash]!='\0';i++)
		temphash *= (int) me->postcode[i];

	hashval += (temphash % MAXPOSTCODE);
	hashval += me->house_number;

	return hashval;
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

}

/** Frees memory from heap at me */
void me_destroy(MEntry *me){
	free(me);
}
