#include "mentry.h"
#include <stdio.h>

int main(void){
	MEntry *me1,*me2;
	me1 = me_get(stdin);
	me2 = me_get(stdin);
	
	printf("%s","=== me1 ===\n");
	printf("%s %s","\n\nSurname:",me1->surname);
	//printf("%s %s","\nHouse_Num:",me1->house_number);
	printf("%s %s","\nPostcode:",me1->postcode);
	printf("%s %s","\nFullAddr:\n",me1->full_address);

	//printf("%s","=== me2 ===\n");
	//me_print(me2,stdout);

	
	
}
