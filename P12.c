/* Name : Abir Abbas
 * ID : 0955448
 * CIS3490 A3 
 * 2018-03-11 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <ctype.h>
#include <limits.h>
#include <sys/timeb.h>
#include <time.h>

int compare_char (const void *a, const void *b) {
    if (*(char *)a != *(char *)b)	return *(char *)a - *(char *)b;

    return 0;
}

void sortQ2(char string[]) {
		
	char temp;
	
	int i, j;
	int n = strlen(string);
	
	qsort (string, strlen (string), sizeof *string, compare_char);
}

int compareLength (const void * first, const void * second) {
	long int temp1 = strtol((char*)first, NULL, 10);
	long int temp2 = strtol((char*)second, NULL, 10);
	
	return ( temp1 - temp2 );
}

void P12() {
	
	FILE *inFile = NULL;
	char fileName[1024];
	char anagram[1024];
	int index = 0;
	int counter = 0;
	printf("Please enter the fileName to test with: \n");	
	scanf("%s", fileName);

	
	printf("Please enter the anagram to test with: \n");
	scanf("%s", anagram);
	
	inFile = fopen(fileName, "r+");
	
	char string[1024];
	char arr[30000][30];
	
	sortQ2(anagram);
	
	while (fscanf(inFile, "%s", string) != EOF) {
		strcpy(arr[index], string);
		index++;
	}
	
	//pre-sorted list being scanned for anagrams now

	clock_t begin = clock();
	
	for (int i = 0; i < 30000; i++) {
		sortQ2(arr[i]);
	}
	
	for (int i = 0; i < 30000; i++) {
		if (strlen(anagram) == strlen(arr[i])) {
			if(strcmp(anagram, arr[i]) == 0) {
				printf("Matching anagram found : index %d\n", i);
				counter++;
			}	
		}
	}
	
	clock_t end = clock();
	
	double timeSpent = (double)(end-begin)/ CLOCKS_PER_SEC;
	
	printf("Total anagrams found : %d\n", counter);
	printf("Total time taken : %lf seconds\n", timeSpent);
}
