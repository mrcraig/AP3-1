/**
@author Craig Cuthbertson
@login 1002386c
@title AP3 Exercise 1

This is my own work as defined in the Academic Ethics agreement I have signed.
*/

#include <stdio.h>
#include "mlist.h"

#define HASHSIZE 20;

typedef struct mlistnode {
	struct mlistnode *next;
	MEntry *entry;
} bucket;

struct mlist {
	bucket *hash;
	int size;
};

int ml_verbose=0;
int size = HASHSIZE;

/** Declare mailing list */
MList *ml;

MList *ml_create(void) {
	/** loop variable */
	int i;

	/** temp bucket initialisation variable */
	bucket *buck;

	if(ml_verbose)
		fprintf(stderr,"mlist: creating mailing list\n");



	if( (ml = (MList *) malloc(sizeof(MList))) == NULL){
		return ml;
	}

	if( ( buck = (bucket *) malloc(sizeof(bucket)*size)) == NULL){
		return buck;
	}

	/** Set hash pointer to bucket */
	ml->hash = buck;

	/** Set mlist size */
	ml->size = size;



	/** Declare heap storage 
	if((ml = (struct mlist *) malloc(sizeof(struct mlist)))!=NULL){
		if((ml->hash = (MListNode *) malloc(sizeof(MListNode)*HASHSIZE))!=NULL){
			ml->hash->next = malloc(sizeof(MListNode));
			ml->hash->entry = malloc(sizeof(MEntry));

			/** Initialise all pointers to NULL 
			for(i=0;i<HASHSIZE;i++){
				ml->hash[i]->next = NULL;
				ml->hash[i]->entry = NULL;
			}

		} else
			return ml; /**malloc failed on MListNode 
	}
	return ml; /** malloc failed, return ml */

}

int ml_add(MList **ml, MEntry *me) {
	
}

MEntry *ml_lookup(MList *ml, MEntry *me) {

}

void ml_destroy(MList *ml) {

}
