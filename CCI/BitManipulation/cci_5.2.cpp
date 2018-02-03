#include <iostream>

using namespace std;

/*5.2 Binary to String: Given a real number between 0 and 1 (e.g., 0.72) that is passed in as a double, 
print the binary representation. If the number cannot be represented accurately in binary with at most 32 characters, 
print"ERROR:'
*/

//Approach - multiply the decimal portion successfully by 2, if product is > 1,subtract 1 from the product and repeat the process
//Ref to conversions: https://blog.angularindepth.com/the-simple-math-behind-decimal-binary-conversion-algorithms-d30c967c9724

void toBinary(double n) {
    if(n >=1 || n <= 0) {
        cout << "ERROR" <<endl;
        return;
    }
        
    double tmp = n;
    int count = 0;
    while(tmp) {
        tmp = tmp * 2; //left shift or multiply by 1
        if(++count > 32) {
            cout << "ERROR" << endl;
            return;
        }
        if(tmp > 1) {
            cout << "1";
            tmp -= 1;
        }
        else {
            cout << "0" ;
        }
    }
}

int main() {
    
    double n = 0.72;//real number between 0 and 1
    
    toBinary(n);

    return 0;   
}
