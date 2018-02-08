/*5.5 Debugger: Explain what the following code does: ((n & (n-1 )) == 0)*/
//Approach: this basically checks whether n is a power of 2

isPower2(int n) {
   if(n <= 0)
      return false;
   if(n & (n-1) == 0)
      return true;
   else
      return false;
}
