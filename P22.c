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

# define MAX 500

void bTable(char *p, int * t)	{
	int i,j,m;
	m=strlen(p);
	for(i=0;i<MAX;i++)
		t[i]=m;
	for(j=0;j<m-1;j++)
		t[p[j]]=m-1-j;
}


void P22() {
	
	FILE *inFile = NULL;
	char fileName[1024];
	char search[1024];
	char c;
	int counter = 0;
	int pswitch = 0;
	printf("Please enter the fileName to test with: \n");	
	scanf("%s", fileName);

	
	printf("Please enter the string to search for: \n");
	scanf("%s", search);
	
	inFile = fopen(fileName, "r+");
	
	char string[1024];
	
    int m = strlen(search);
 
    int *badchar = malloc(sizeof(int) * MAX);
 
    bTable(search, badchar);
	
	clock_t begin = clock();
	
	while (fgets(string, 1024,inFile) != NULL) {
		
		int n = strlen(string);
		int j = 0;
		while (j <  n - m) {
			c = string[j + m - 1];
			if (isalnum(c)) {
				if (search[m - 1] == c && memcmp(search, string + j, m - 1) == 0) {
					counter++;
				}
				j += badchar[c];
				pswitch++;
			}
			else {
				j++;
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
