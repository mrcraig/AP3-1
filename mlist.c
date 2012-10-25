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
	bucket **hash;
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

	if( (ml->hash = (bucket **) calloc(size,sizeof(bucket *)))!=NULL){
		for(i=0;i<size;i++){
			ml->hash[i] = (bucket *) malloc(sizeof(bucket));
			ml->hash[i]->next = NULL;
		}
	}

	/** Set hash pointer to bucket */
	ml->size=size;	

	/** Set mlist size */
	ml->size = size;

	return ml;

}

/** adds MEntry to list,
Returns 1 if successful
Returns 0 if not successful
*/
int ml_add(MList **ml, MEntry *me) {
	MList *m = *ml;
	unsigned long hashval;
	int i;
	bucket *buck,*bucket_new;

	/** check duplicates 
	if (ml_lookup(ml, m) != NULL)
		return 1;

	/** allocate space for next entry */
	if((bucket_new = (bucket *) malloc(sizeof(bucket)))==NULL)
		return 0;

	bucket_new->next = NULL;

	/** Compute hash value of item */
	hashval = me_hash(me,m->size);


	/** choose appropriate bucket array from hash table */
	buck = m->hash[hashval];


	/** loop until free bucket */
	while(buck->next!=NULL){
		buck = buck->next;
	}
	
	/** set next to an empty bucket, and the entry to mentry */
	buck->next = bucket_new;
	buck->entry = me;

	return 1;	
	
}

/** looks for entry in ml matching me
if found, return pointer, if not return NULL */
MEntry *ml_lookup(MList *ml, MEntry *me) {
	unsigned long hashval;
	bucket *buck_cursor;
	
	/** print statement if verbose */
	if(ml_verbose)
		fprintf(stderr,"mlist: ml_lookup() entered\n");

	/** calculate hashval of me */
	hashval = me_hash(me,ml->size);


	/** loop through cursor values checking entries */
	buck_cursor = ml->hash[hashval];

	while(buck_cursor->next!=NULL){
		if(me_compare(buck_cursor->entry,me)==0){
			/**found match, return pointer */
			return buck_cursor->entry;
		} else {
			/** not found, continue searching*/
			buck_cursor = buck_cursor->next;
		}
	}

	/** entry was not found, return NULL */
	return NULL;
}

void ml_destroy(MList *ml) {
	/*
	int i;
	bucket *cursor;
	bucket *next_cursor;
	
	if (ml_verbose)
		fprintf(stderr, "mlist: ml_destroy() entered\n");
	
	/** for every bucket array 
	for(i=0;i<ml->size;i++){
		cursor = (ml->hash) + i;
		/** free every bucket in each hash entry 
		while(cursor->next!=NULL){
			next_cursor = (cursor->next)+1;
			free(cursor);
			cursor = next_cursor;
		}
	}

	/** free mlist structure 
	free(ml);*/
}
