# polyapp
Program to compute polynomial from SSV file

# How to run
1. Download all the source files, header files, data.ssv and the makefile to a single directory.
2. To compile to program run `make` from command line.
3. To execute the program run `./polyapp data.ssv`.
    * `data.ssv` is the sample data file included in the repo, but feel free to create your own SSV file

# What the program does
1. The program start my reading the SSV file given.
2. Parses the file line by line to extract coefficients from the first term and exponents from the second term.
3. Stores the extracted values into a node of a linked list according to increasing exponent values and merges nodes with same exponents.
4. Displays the polynomial.
5. Computes the value of the polynomial for the following values for x: -2, -1, 0, 1, 2. 

![image](https://user-images.githubusercontent.com/46686623/79383733-b120d500-7f33-11ea-842f-de7fc3039c08.png)
