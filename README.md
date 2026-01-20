This program uses Guassian Elimination to find a nth degree polynomial relationship for n+1 given points

task was to determine the coefficients of a.b & c, in an equation with the
form 𝑦 = ax^2 + bx + c with using the points (1, 5), (2, 14) and (3, 29). This was
initially done on paper using simultaneous equations, but the task was to come up
with a general solution. The general solution that was followed also used
simultaneous equations but we needed n + 1 expressions, where n is the degree of
the polynomial. This created a square matrix of n + 1 terms of x, by n + 1 expressions,
this matrix multiplied by a vector of coefficients would give us a vector for y values.
To find the coefficients we need to divide the vector containing the y values by the
matrix of x values, the resulting vector will contain all the coefficients in increasing
order of x powers. But the division of matrices is not an inherent process, we need
to find its inverse then multiply. The process for calculating an inverse matrix
involves the Gaussian Elimination method, where we perform row calculations on
the matrix in order to make the current matrix into the identity matrix, and also copy
the same operations on an existing identity matrix. This manipulated identity matrix
contains the inverse matrix after all the row operations have been finished. The
multiplication between the inverse matrix and a vector was done by taking the dot
product between each row in the matrix and the vector. The final program was
implemented in C and returns all the coefficients of any polynomial function when
given n + 1 points. 
