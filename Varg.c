//  Stephen Sumner, NID 3977991

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "Varg.h"


char mostFrequentChar(int n, ...);

char fancyMostFrequentChar(char c, ...);

double difficultyRating(void);

double hoursSpent(void);


char mostFrequentChar(int n, ...){

	//  First we will work on mostFrequentChar, which will always have a 
	//  integer number to lead the function call. The integer tells the
	//  function how many additional arguments there are. Can only read 
	//  the list of arguments once. 
	//
	//  The plan to deal with this is to implement a 26 element integer
	//  array which stores an integer value representing the frequency with
	//  which that character appeared in the list. A selection algorithm 
	//  then scans through the array for the highest value and assigns that
	//  element to a variable that keeps track of the most frequent char.

	int freqArray[26] = {0}, freq = 0;
	int i, j, k, nextChar, index;
	char freqChar;
	
	va_list vargChar;
	va_start(vargChar, n); 

	if(n == 0) {

		return '\0';
		i = ++n;
	}

	for(i = 0; i < n; i++) {
        
		//  the nextChar variable is self explanatory. The index is the nextChar 
		//  converted to an integer value minus the integer value for 'a'. 

		nextChar = (va_arg(vargChar, int));
		index = (nextChar - 'a');
		freqArray[index]+= 1;

		for(j = 0;j < 26;j++) {

			// After one iteration of the previous loop, this next algorithm loop
			// goes through the array element by element and then checks the 
			// frequency value stored in that element.

			if(freqArray[j] > freq) {

				// if the value stored in that element of the array is greater than 
				// the previous most frequent number of times a character has appeared
				// then the freqChar variable is changed to the character that element
				// of the array represents, and the freq variable is incremented. 
				// subsequent characters that equal the same frequency of occurence
				// will not change the freqChar variable.

				freqChar = (char)j + 'a';
				freq++;
			}
		}
	}
    
	va_end(vargChar);
	return freqChar;
}

char fancyMostFrequentChar(char c, ...) {

	//  Next is the fancyMostFrequentChar function. A list of characters
	//  is passed to the function, but unlike mostFrequentChar(), this one
	//  does not receive an integer indicating how many characters it will
	//  receive. Instead, the list will end with '\0'. If '\0' is the only
	//  character received, it is required to return that character. Can  
	//  only read the list of arguments once. 
	//
	//  The plan to deal with this is to implement a 26 element integer
	//  array which stores an integer value representing the frequency with
	//  which that character appeared in the list. A selection algorithm 
	//  then scans through the array for the highest value and assigns that
	//  element to a variable that keeps track of the most frequent char.

	int freqArray[26] = {0}, freq = 0;
	int i, j, k, nextChar = c, index;
	char freqChar = '\0';
	
	va_list vargChar;
	va_start(vargChar, '\0'); 

	do {
        
		//  the nextChar variable is self explanatory. The index is the nextChar 
		//  converted to an integer value minus the integer value for 'a'. 

		index = (nextChar - 'a');

		// important break from the loop if nextChar = \0 to avoid a segmentation fault.

		if(nextChar == '\0') {

			break;
		}

		freqArray[index]+= 1;
		nextChar = (va_arg(vargChar, int));

		for(j = 0;j < 26;j++) {

			// After one iteration of the previous loop, this next algorithm loop
			// goes through the array element by element and then checks the 
			// frequency value stored in that element.

			if(freqArray[j] > freq) {

				// if the value stored in that element of the array is greater than 
				// the previous most frequent number of times a character has appeared
				// then the freqChar variable is changed to the character that element
				// of the array represents, and the freq variable is incremented. 
				// subsequent characters that equal the same frequency of occurence
				// will not change the freqChar variable.

				freqChar = (char)j + 'a';
				freq++;
			}
		}

	}while(vargChar != '\0');
    
	va_end(vargChar);
	return freqChar;
}

double difficultyRating(void) {

	return 3.5;
}

double hoursSpent(void) {

	return 7.0;
}
