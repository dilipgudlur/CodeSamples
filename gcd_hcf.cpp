#include <iostream>
#include <algorithm>

using namespace std;

int gcdDiv(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    cout << a << " and " << b <<endl; 
    return gcdDiv(b % a, a); //order doesnt matter
} 

int gcdSubtract(int a,int b) {
    
    if(a == 0 || b == 0)
        return 0;
        
    if(a == b) //terminating condition
        return a;
    cout << a << " and " << b <<endl; 
    if(a > b)
        return gcdSubtract(a-b,b); //since a is greater, reduce it by b
    else
        return gcdSubtract(a,b-a); //since b is greater, reduce it by a
}

int main()
{
 cout << gcdDiv(10,35) << endl;
 cout << gcdSubtract(10,35) << endl;  
   
return 0;
}

