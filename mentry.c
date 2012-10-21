/**
@author Craig Cuthbertson
@login 1002386c
@title AP3 Exercise 1

This is my own work as defined in the Academic Ethics agreement I have signed.
*/

#include <stdio.h>
#include <mentry.h>

#define HASHSIZE 101

/**
Returns pointer to next file entry in hash table, or null if last file entry
*/
MEntry *me_get(FILE *fd){
	if(/** another record exists in mlist */)
		return *(fd+sizeof(MEntry));
	else
		return NULL;
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
