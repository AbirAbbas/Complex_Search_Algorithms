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

# define NO_OF_CHARS 256

int pswitch = 0;

int max (int a, int b) {
	return (a > b)? a: b; 
}

void badTable( char *str, int size, int *badchar)	{
    int i;
    
    while (i < NO_OF_CHARS) {
		
		badchar[i] = -1;
		
		i = i + 1;
	}
	
	i = 0;
	
	 while (i < size) {
		
		badchar[(int) str[i]] = i;
		
		i = i + 1;
	}
 
    for (i = 0; i < size; i++) {
         badchar[(int) str[i]] = i;
	}
}

int searchT( char *txt,  char *pat)
{
	int counter = 0, s = 0;
    int m = strlen(pat), n = strlen(txt);
 
    int *badchar = malloc(sizeof(int) * NO_OF_CHARS);
 
    badTable(pat, m, badchar);

    for(int j = 0; s <= (n - m) ; )	{
		j = m-1;

        while(j >= 0 && pat[j] == txt[s+j]) {
            j--;
		}
		
        if (j < 0)	{
			counter+=1;
            s = s + ((s+m < n)? m-badchar[txt[s+m]] : 1);
        }
 
        else
            s = s + max(1, j - badchar[txt[s+j]]);
        
        
        pswitch++;
    }
    
    return counter;
}

void P23() {
	
	FILE *inFile = NULL;
	char fileName[1024];
	char search[1024];
	
	int counter = 0;
	printf("Please enter the fileName to test with: \n");	
	scanf("%s", fileName);

	
	printf("Please enter the string to search for: \n");
	scanf("%s", search);
	
	inFile = fopen(fileName, "r+");
	
	char string[1024];
	
	clock_t begin = clock();
	
	while (fgets(string, 1024,inFile) != NULL) {
		counter+=searchT(string, search);
	}
	
	clock_t end = clock();
	
	double timeSpent = (double)(end-begin) / CLOCKS_PER_SEC;
	
	printf("Total strings found : %d\n", counter);
	printf("Total pattern switches : %d\n", pswitch);
	printf("Total time taken : %lf seconds\n", timeSpent);
}
