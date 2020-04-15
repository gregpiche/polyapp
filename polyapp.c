/*
 ****************************************************************
 Author       	Dept.           Date            Noted
 ****************************************************************
 Gregory P    	Software Eng.   APR 05 2020     Initial version
 Gregory P	Software Eng.	APR 10 2020	Added file parsing calls
 ****************************************************************
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "poly.h"

int main(int argc, char *argv[]){
	// Verification that proper number of args is given
	if(argc != 2){
		fprintf(stderr, "Error, no file was given.\n");
		return -1;
	}
	
	// Check to see if data file given exists
	char filename[50];
	strcpy(filename, argv[1]);
	FILE *q = fopen(filename, "r");
	if(q == NULL){
		fprintf(stderr, "Error, file could not be located.\n");
		return -1;
	} 
	createHead();	
	// Reads one line at a time
	char str[1024];
	while(!feof(q)){
		fgets(str,1024, q);
		if(feof(q)) break;
		int exp;
		int coef;
		parse(str, &coef, &exp); // calls parse to extract the coeff and exponent from ssv file
		addPolyTerm(coef, exp); // Adds the information to a node in the linked list
	}
	displayPolynomial(); 
	evaluatePolynomial(-2);
	evaluatePolynomial(-1);
	evaluatePolynomial(0);
	evaluatePolynomial(1);
	evaluatePolynomial(2);
	return 0;	
}
