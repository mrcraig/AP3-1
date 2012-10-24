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
	int size;
	bucket *hash;
};

int ml_verbose=0;
int size = HASHSIZE;


MList *ml_create(void) {
	/** Declare mailing list */
	MList *ml;

	/** loop variable */
	int i;

	/** temp hashtable initialisation variable */
	bucket *hashtab;

	if(ml_verbose)
		fprintf(stderr,"mlist: creating mailing list\n");



	if( (ml = (MList *) malloc(sizeof(MList))) == NULL){
		return ml;
	}

	if( ( hashtab = (bucket *) malloc(sizeof(bucket)*size)) == NULL){
		return hashtab;
	}

	/** Set hash pointer to bucket */
	ml->hash = hashtab;

	/** Set mlist size */
	ml->size = size;

}

int ml_add(MList **ml, MEntry *me) {
	MList *m = *ml;
	unsigned long hashval;
	int i;
	bucket *buck;

	/** allocate bucket space for new entry */
	bucket *bucket_new = malloc(sizeof(bucket));

	/** Compute hash value of item */
	hashval = me_hash(me,m->size);

	/** check successful */
	if(bucket_new == NULL)
		return 0;

	bucket_new->entry = me;

	/** choose appropriate bucket array from hash table */
	buck = (m->hash)+hashval;

	/** loop until free bucket */
	while(buck->next!=NULL){
		buck = buck->next;
	}
	
	buck->next = bucket_new;
	return 1;	
	
}

MEntry *ml_lookup(MList *ml, MEntry *me) {
	
	/** print statement if verbose */
	if(ml_verbose)
		fprintf(stderr,"mlist: ml_lookup() entered\n");
}

void ml_destroy(MList *ml) {

}
