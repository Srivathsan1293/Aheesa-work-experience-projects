The program tells whether a number is prime or not but instead of using the algorithm from before this program 
checks a known dataset first using a hash table of the numbers stored in prime numbers.txt if it is not in the
dataset then it uses the alagorithm to identify whether the input is a prime number or not. If a new prime number is 
found then it is added to the dataset as well. 

To address the inherent inefficiency in the prime verification
program regarding the repeated verification of numbers. Everytime a number is
entered to be verified we have to process the entire algorithm. The result of
verifications could be stored to address this flaw, but it requires a fast search
algorithm to be effective. Traditional search algorithms proved inadequate in
achieving consistent search times across all primes. Despite exploring fast
algorithms such as jump, binary, and interpolation search, the recurring issue of
inconsistent search times persisted. However, by using hashing we can facilitate
efficient data storage and retrieval by mapping each data element to a specific index
using mathematical functions. Various hashing techniques were evaluated, ranging
from rudimentary methods like storing numbers at their respective indices to more
sophisticated algorithms like xxHash and MurmurHash. Notably, xxHash 32
emerged as the optimal choice for storing the initial 1000 prime numbers. However
Implementation of xxHash 32 necessitated reference to forums and clarifications
through ChatGPT, to implement into a C program. So a premade option in C++ was
used in the final program, the STL unordered_map provided a streamlined approach
to hash table implementation, enabling seamless addition and retrieval of values
across different data types. 
