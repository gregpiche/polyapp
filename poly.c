/*
 ****************************************************************
 Author         Dept.           Date            Noted
 ****************************************************************
 Gregory P      Software Eng.   APR 09 2020     Initial version
 Gregory P      Software Eng.   APR 10 2020     Functions implemented
 Gregory P	Software Eng.	APR 11 2020	Created header file
 Gregory P	Software Eng.	APR 14 2020	Added Comments
 ****************************************************************
*/

#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

struct PolyTerm *head; // Defines the head pointer

struct PolyTerm { // Defines the node structure
	int coeff;
	int expo;
	struct PolyTerm *next;
};

// Initialize the head node and pointer to the linked list
int createHead(){ 
	head = (struct PolyTerm *) malloc(sizeof(struct PolyTerm));
	head->coeff = 0;
	head->expo = 0;
	head->next = NULL;
};

int addPolyTerm(int coef, int exp){
	//create new node
	struct PolyTerm *prev;
	struct PolyTerm *aNode = (struct PolyTerm *) malloc(sizeof(struct PolyTerm));
	if (aNode == NULL) exit(-1);
	
	//prev->next = aNode;	
	aNode->coeff = coef;
	aNode->expo = exp;	
	aNode->next = NULL;

	struct PolyTerm *n = head; 
	while (n != NULL){ //find last node in linked list
		prev = n;
		n = n->next;
		if(n == NULL) break;
		int aExpo = aNode->expo;
		int nExpo = n->expo;
		if( nExpo == aExpo){	// add same exponent
			n->coeff = (n->coeff) + (aNode->coeff);
			return 0;
		}
		
		if((n->expo) > (aNode->expo)){ // if exponent is smaller than the exponent of the following nodeinsert new node
			prev->next = aNode;
			aNode->next = n;
			return 0;
		}
	}
	prev->next=aNode;
	return 0;
};

// Displays the polynomial equation
void displayPolynomial(){
	struct PolyTerm *n;
	n = head->next;
	while (n != NULL){
		printf("%dx%d", n->coeff, n->expo); // print and expression
		n = n->next;
		if(n != NULL){ // if not at last node then add a +
			if (n->coeff >= 0) printf("+"); // if coeff is not negative add plus
		}
	}
	printf("\n");
};

// Computes the value of the equation for given x value
int evaluatePolynomial(int x){
	struct PolyTerm *n;
	n = head->next;
	int sum = 0;
	while (n != NULL){
		sum = sum + ((n->coeff)*powi(x, n->expo)); // calls powi to evaluate the value of the exponential 
		n = n->next; 
	}
	printf("For x=%d, y=%d\n", x, sum); 
};
