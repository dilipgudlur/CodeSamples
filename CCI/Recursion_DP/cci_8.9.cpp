/*8.9 Parens: Implement an algorithm to print all valid (i.e., properly opened and closed) combinations of n pairs of parentheses.
EXAMPLE Input: 3 
Output: (( () ) ) , ( () () ) , ( () ) () , () ( () ) , ()( ) () 
*/

/*Approach: This method avoids generating duplicates. Terminating condition is important -
a. As long as we haven't used up all the left parentheses, we can always insert a left paren, if remaining left parens is less than 0, terminate
b. right parens can only be added once a corresponding left parens has been added, number of right parens added cannot be more than left parens,
so if remaining right parens are more than left parens then terminate

*/

#include <iostream>
#include <string>
#include <vector>
#include <stack> 

using namespace std;

void printParens(vector<string>& result, int leftRem, int rightRem, int index, vector<char>& tmpParenStr) {
    if(leftRem < 0 || rightRem < leftRem)
        return;
    if(leftRem == 0 && rightRem == 0) {
        string s(tmpParenStr.begin(),tmpParenStr.end());
        result.push_back(s);
        return;
    }
    
    tmpParenStr[index] = '(';
    printParens(result,leftRem-1,rightRem,index+1,tmpParenStr);
    
    tmpParenStr[index] = ')';
    printParens(result,leftRem,rightRem-1,index+1,tmpParenStr);
}

int main()
{
    int count = 3;
    int index = 0;
    vector<string> result;
    vector<char> tmpParenStr(2*count);
    printParens(result,count,count,index,tmpParenStr);
    for(int i = 0;i < result.size();i++)
        cout << result[i] << endl;
}

