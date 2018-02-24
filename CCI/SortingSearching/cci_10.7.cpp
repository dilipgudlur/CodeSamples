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

#define CONTAINERS (INT_MAX+1)/32; //all 32 bits can be used to represent the numbers
int uniqueNumber(FILE *fp) {

   long vecRange = (long) (INT_MAX+1);//all 32 bits can be used to represent the numbers
   int containers = math.ceiling(vecRange/32); //numbers of containers required, use ceiling to prevent shortage of containers
   unsigned int vec[containers]; //array of unsigned ints
   /*read the file, populate the bit vector*/
   while(fp != EOF) { //read file till end
      int index = fp.readline(); //lets assume readline will return an integer in the file
      int containerNumber = index/32; //finds the right container number
      int indexInContainer = index%32 //finds the index within the container
      uniqueNumber[containerNumber] |= (1 << indexInContainer); //set that bit in the container, indicates that integer is present
   }

   //now bit vectore has been created, its time to search for unique integer

   for(int i = 0;i < containers;i++) { //search amongst the containers
      for(int j = 0;j < 32;j++) { //search within each container
         if(vec[i] & (1 << j) == 0) {
            /*in the container i, check if bit at position j is not set*/
            //construct the number
            return (32*i + j); //this is the first integer not contained in the file
         }
      }
   }
   return -1; //if control reaches here
}
