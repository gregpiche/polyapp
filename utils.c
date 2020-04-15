/*
 ****************************************************************
 Author       	Dept.           Date            Noted
 ****************************************************************
 Gregory P    	Software Eng.   APR 09 2020     Initial version
 Gregory P	Software Eng.	APR 10 2020	Completed powi and parse functions	
 Gregory P	Software Eng.	APR 11 2020	Created Header file
 ****************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Powi takes two integers and returns and integer which is the first integer raised to the second
int powi(int x, int exp){
        int pow = x;
	if(exp == 0) return 1;
	
	for(int i = exp-1; i > 0; i--){
                pow = pow * x;
        }
        return pow;
}

// Store the coefficient and exponent to the address
void parse(char line[], int *coef, int *exp){
	        const char s[2] = " ";
                char *token;
                token = strtok(line, s);
                *coef = atoi(token);
                token = strtok(NULL, s);
                *exp = atoi(token);
}
