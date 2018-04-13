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

void sort(char string[]) {
	
	char temp;
	
	int i, j;
	int n = strlen(string);
	
	for (i = 0; i < n-1; i++) {
		for (j = i+1; j < n; j++) {
			if (string[i] > string[j]) {
				temp = string[i];
				string[i] = string[j];
				string[j] = temp;
			}
		}	
	}
}

void P11() {
	
	FILE *inFile = NULL;
	char fileName[1024];
	char anagram[1024];
	char temp[1024];
	
	strcpy(temp, "");
	
	int counter = 0;
	printf("Please enter the fileName to test with: \n");	
	scanf("%s", fileName);

	
	printf("Please enter the anagram to test with: \n");
	scanf("%s", anagram);
	
	inFile = fopen(fileName, "r+");
	
	char string[1024];
	
	clock_t begin = clock();
	
	sort(anagram);
	
	while (fscanf(inFile, "%s", string) != EOF) {
		
		if (strlen(anagram) == strlen(string)) {
			strcpy(temp, string);
			sort(string);
			if(strcmp(anagram, string) == 0) {
				printf("Matching anagram found : %s\n", temp);
				counter++;
			}		
		}
	}
	
	clock_t end = clock();
	
	double timeSpent = (double)(end-begin)/ CLOCKS_PER_SEC;
	
	printf("Total anagrams found : %d\n", counter);
	printf("Total time taken : %lf seconds\n", timeSpent);
}
