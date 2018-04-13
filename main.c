/* Name : Abir Abbas
 * ID : 0955448
 * CIS3490 A3 
 * 2018-03-11 
 * */

#include <stdio.h>
#include "allRun.h"

int main () {
	
	while (1) {
		printMenu();
		int choice = 0;
		
		scanf("%d", &choice);
		
		if (choice == 1) {
			P11();
		}
		else if (choice == 2) {
			P12();
		}
		else if (choice == 3) {
			P21();
		}
		else if (choice == 4) {
			P22();
		}
		else if (choice == 5) {
			P23();
		}
		else if (choice == 6) {
			break;
		}
		else {
			printf("Invalid choice!\n");
		}
		
	}
	
	return 0;
}

void printMenu () {
	printf("Menu:\n1. Brute force anagram\n2. Presorted anagram\n3. Brute force string search\n4. Horsepool string search\n5. Boyer moore string search\n6. Exit\n");
}
