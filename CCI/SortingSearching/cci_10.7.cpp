/*10.7 Missing Int: Given an input file with four billion non-negative integers, 
provide an algorithm to generate an integer that is not contained in the file. 
Assume you have 1 GB of memory available for this task*/

//Approach - If there is sufficient memory, use an in-memory bit vector to
//set bits when corrsponding number is seen in the file. Once bit vector is generated
//parse it again and return the first integer corresponding to the bit that has not been
//set

/*Relevant questions - 
1. Is enough memory present in the system to make the bit vector? 
a. file contains 4 billion numbers but only positive numbers. How many positive numbers are there?
That depends on the machine type, lets assume its a 32 bit machine, that means you can represent total of 2^32
numbers (half of which are negative and other half are positive. So file could potentially contain (2^31 + 1) unique positive
numbers including zero, which comes around to 2 billion + 1 unique positive numbers. Since file contains 4 billion
numbers, it definitely has some duplicates. So in effect we should have a bit vector to represent the 2 billion +1 unique numbers.
Each byte can represent 8 unique numbers 
b. so how many bytes are required to resent 2billion+1 numbers=  2^31/8 = 2^28 bytes.
c. How many bytes does 1 GB have - 1024 * 1024 * 1024 bytes = 2^30 bytes
d. that means 1 GB memory is sufficient to store the bit vectore of 2^28 bytes.
*/
