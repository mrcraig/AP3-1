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
} MListNode;

struct mlist {
	MListNode *hash;
};

int ml_verbose=0;
struct mlist *ml;

MList *ml_create(void) {
	if((ml = (struct mlist *)malloc(sizeof(struct mlist)))!=NULL){
		if((ml->hash = (MListNode *)malloc(sizeof(MListNode)*HASHSIZE))!=NULL){
			ml->hash->next = malloc(sizeof(MListNode));
			ml->hash->entry = malloc(sizeof(MEntry));
		} else
			return ml; /**malloc failed on MListNode */ 
	}
	return ml; /** malloc failed, return ml */

}

int ml_add(MList **ml, MEntry *me) {

}

MEntry *ml_lookup(MList *ml, MEntry *me) {

}

void ml_destroy(MList *ml) {

}
