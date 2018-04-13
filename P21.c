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

void P21() {
	
	FILE *inFile = NULL;
	char fileName[1024];
	char search[1024];
	char temp[1024];
	int pswitch = 0;
	
	strcpy(temp, "");
	
	int counter = 0;
	printf("Please enter the fileName to test with: \n");	
	scanf("%s", fileName);

	
	printf("Please enter the string to search for: \n");
	scanf("%s", search);
	
	inFile = fopen(fileName, "r+");
	
	char string[1024];
	
	clock_t begin = clock();
	
	while (fgets(string, 1024,inFile) != NULL) {
		
		if (strlen(string) > strlen(search)) {
			for (int i = 0; i <= ((strlen(string) - strlen(search))); i++) {
				for (int j = 0; j < strlen(search);j++) {
					
					if (!isalpha(string[i+j])) {
						break;
					}
					
					if (search[j] == string[i+j]) {
						if (j == strlen(search) - 1) {
							counter++;
						}
					}
					else {
						break;
					}
				}
				pswitch++;
			}
		}
	}
	
	clock_t end = clock();
	
	double timeSpent = (double)(end-begin)/ CLOCKS_PER_SEC;
	
	printf("Word : %s\n", search);
	printf("Total strings found : %d\n", counter);
	printf("Total pattern switches : %d\n", pswitch);
	printf("Total time taken : %lf seconds\n", timeSpent);
}
