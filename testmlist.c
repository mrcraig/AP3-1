#include "mlist.h"
#include <stdio.h>

int main(void){
	MList *ml;
	MEntry *me;

	ml = ml_create();
	me = me_get(stdin);

	ml_add(ml,me);
}
