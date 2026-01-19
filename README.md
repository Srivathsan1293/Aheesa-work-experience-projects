This excel sheet uses mathematical formualae to implement a gradient descent algorithm. 
The sheet is set up to calaculate the quadratic relationship between 3 points. 
In the columns x & y. Enter values for 3 points. Drag the formualae down from columns C -> L one row.
Then drag columns C -> O. The values of a,b & c are the coefficients of the quadratic equation in form 
ax^2 + bx + c. If you want to add more points then the formulae need to adjusted but it will still be similar. 

The system should be able to get multiple coordinates and still only give a quadratic output. To
accomplish this a different algorithm was used, called gradient descent. This method
provides us with a very general way to guess the function, for any set of points, to a
very high degree of accuracy. This can be done, as first we guess a random value of
a, b & c, then try the given x values. Using the calculated y value we find our error
rate by using a loss function, in this specific example Mean Squared Error. Which is
the mean difference squared between calculated and actual y values. Afterwards, we
can partially differentiate a, b & c in the loss function, and calculate the gradient,
giving us the direction to move the value of a, b or c towards a value which
minimises the loss function. This process of optimising the value of a, b & c is
independent and so can be parallelised. The equations used was implemented in an
excel sheet as formulas then a, b & c was found by dragging the formula down, until
the MSE (Mean Squared Error) was below 1E-6. Giving very accurate values for the coefficients. 
