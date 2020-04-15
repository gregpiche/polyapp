/*
 ****************************************************************
 Author         Dept.           Date            Noted
 ****************************************************************
 Gregory P      Software Eng.   APR 11 2020     Created header file
 Gregory P	Software Eng. 	APR 14 2020	Added Comments
 ****************************************************************
*/

#ifndef POLY
#define POLY

struct PolyTerm {
	int coeff;
	int expo;
	struct PolyTerm *next;
};

extern struct PolyTerm *head; // Make head point a global var

/*
* The following are functions definition for functions in poly.c
* the function definition make it possible for other files to call these functions
*/

int createHead(); // createHead() function definition

int addPolyTerm(int coef, int exp); // addPolyTermm function definition

void displayPolynomial(); 

int evaluatePolynomial(int x);

#endif
