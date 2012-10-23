#include "mentry.h"
#include <stdio.h>

int main(void){
	MEntry *me1,*me2;
	me1 = me_get(stdin);
	me2 = me_get(stdin);
	
	printf("%s","=== me1 ===\n");
	me_print(me1,stdout);
	printf("%s %s","\n\nSurname:",me1->surname);
	printf("%s %d","\nHouse_Num:",me1->house_number);
	printf("%s %s","\nPostcode:",me1->postcode);
	printf("%s %s","\nFullAddr:\n",me1->full_address);
	printf("%s %d","\nHash:",me_hash(me1,83));

	printf("%s","=== me2 ===\n");
	me_print(me2,stdout);
	printf("%s %s","\n\nSurname:",me2->surname);
	printf("%s %d","\nHouse_Num:",me2->house_number);
	printf("%s %s","\nPostcode:",me2->postcode);
	printf("%s%s","\nFullAddr:\n",me2->full_address);
	printf("%s %d","\nHash:",me_hash(me2,83));

	me_destroy(me1);
	me_destroy(me2);

	
	
}
