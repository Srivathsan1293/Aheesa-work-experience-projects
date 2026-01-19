This assembly program determines whether a number is prime or not. By checking whether it is divisble by 2 or by an odd number 
until the number we are dividing by is more than the square root of the number we want to verify.

The algorithm needs to be very efficient and should not take long to verify even very large prime numbers. 
The initial solution was to check if the number was divisible by all the numbers less than it. But this method 
is very inefficient due to its repeated division by multiples of other numbers. Thinking farther, most numbers 
are divisible by 2, 3, 5 and 7 but some like 121 are only divisible by their square root, so to determine if a 
number is prime we need to check if it is divisible by 2, 3, 5 or 7 and if it is a perfect square. In theory this 
is the best algorithm but the process to compute a square root is very tedious especially in assembly where we 
would have to create an algorithm for that as well. The final method proposed was to divide by odd numbers till 
the square of the number is greater than the number we are checking. This method is simple, efficient and can 
easily be implemented into the NEXYS A7 board. This initial challenge highlights the importance of carefully 
checking each line of code and ensuring that each line has a purpose for the end goal, so that the most efficient 
solution is used. Reducing calculation time and preserving the limited resources of a processor.  
