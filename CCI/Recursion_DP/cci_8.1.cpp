/*8.1 Triple Step: A child is running up a staircase with n steps and can hop either 
1 step, 2 steps, or 3 steps at a time. Implement a method to count how many possible
ways the child can run up the stairs.*/

//Approach: Lets say at you are at the base. If you take 1 step upwards, the problem reduces to n-1, if you take 2 steps, problem becomes n-2 and if you
//take 3 steps, it becomes n-3. Total number of ways will be a summation of these possible ways

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//standard recursion
int climbStairsSol1(int n) {
    if(n < 0)
        return 0;
    if(n == 0)
        return 1;
   
    return climbStairsSol1(n-1) + climbStairsSol1(n-2) + climbStairsSol1(n-3);
}

//memoization using O(n) space
int climbStairsSol2(int n) {
    if(n < 0)
        return 0;
    if(n == 0)
        return 1;
        
    vector<int> memo(n,-1);
    memo[0] = 1;
    memo[1] = 1;
    memo[2] = 2;
    
    for(int i = 3;i <= n;i++)
        memo[i] = memo[i-1] + memo[i-2] + memo[i-3];
        
    return memo[n];
}

//memoization using O(1) space
int climbStairsSol3(int n) {
    if(n < 0)
        return 0;
    if(n == 0)
        return 1;
        
    int a = 1;
    int b = 1;
    int c = 2;
    int sum = 0;
    
    for(int i = 3;i <= n;i++) {
        sum = c + b + a;
        a = b;
        b = c;
        c = sum;
    }     
    return sum;
}

int main()
{
    int stairs = 20;
    cout << "Number of ways child can climb stairs is " << climbStairsSol1(stairs)  << ", " << climbStairsSol2(stairs) << ", " << climbStairsSol3(stairs) << endl; 
}

