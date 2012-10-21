/**
@author Craig Cuthbertson
@login 1002386c
@title AP3 Exercise 1

This is my own work as defined in the Academic Ethics agreement I have signed.
*/

#include <stdio.h>
#include <mentry.h>
#include <string.h>

#define MAXLINE 500
#define MAXSURNAME 100
#define MAXPOSTCODE 10
#define HASHSIZE 101

/**
Constructor, initialises the struct with information from file
*/
MEntry *me_get(FILE *fd){
	/** Temporary storage for reading in lines */
	char line1[MAXLINE+1];
	char line2[MAXLINE+1];
	char line3[MAXLINE+1];
	char house_num[5];

	/** loop counter */
	int i;
	
	if((me = (struct MEntry *)malloc(sizeof(struct MEntry))) != NULL){
		/** allocate memory on heap for entry */
		me->surname = malloc(sizeof(char)*MAXSURNAME);
		me->postcode = malloc(sizeof(char)*MAXPOSTCODE);
		me->full_address = malloc(sizeof(char)*MAXLINE*3)

		/** import data into temp storage */
		fgets(line1,MAXLINE,fd);
		fgets(line2,MAXLINE,fd);
		fgets(line3,MAXLINE,fd);

		me->fulladdress = strcat(line1,strcat(line2,line3));

		/** import surname (lowercase) to MEntry */
		for(i=0;line1[i]!=',';i++){
			me->surname = strcat(me->surname,tolower(line1[i]));	
		}

		/** import house number to MEntry */
		me->house_number = strtol(line2,NULL,10);

	}
	return me; 
}

/**
Returns a hash of a record
*/
unsigned long me_hash(MEntry *me, unsigned long size){
	unsigned hashvalue;
	
	for(hashvalue = 0; *me != '\0'; me++)
		hashvalue = *me + 31 * hashvalue;
	return hashvalue % sizeof(MEntry);
}

/**
Outputs the details of a mentry to stdout
*/
void me_print(MEntry *me, FILE *fd){
	int i;
	/** Print full address */
	for(i=0;me->*(full_address+i)!='\0';i++){
		printf("%c",me->*(full_address+i));
	}
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
