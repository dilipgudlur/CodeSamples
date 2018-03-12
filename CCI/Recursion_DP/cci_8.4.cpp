/*8.4 Power Set: Write a method to return all subsets of a set.*/

//Approach: an array of n elements will have 2^n subsets. Each element occurs in exactly half the total subsets. That is each element will occur in 2^(n-1) subsets. 
//So space and time complexity will be O(n*2^(n-1)), basically meaning that for each element 2^n-1 time and space is consumed.
//For an array with 4 elements, total subsets are 16 (2^4). From 0 to 15, we can see that each element element if present is represented as 1 and if not present is a 0
// So each number from 0 to 15 if represented as a subset, will give all possible subsets for these 4 elements.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> convertToSubset(int bitPattern,vector<int> nums) {
    vector<int> tmp;
    int index = 0;
    for(int i = bitPattern;i > 0;i >>= 1, index++) {
        if(i & 1) //bit is set, add this index to subset
            tmp.push_back(nums[index]);
    }
    return tmp;
}

void subsets(vector<int> nums, vector<vector<int>>& result) {
    size_t n = nums.size();
    if(!n)
        return;
    int maxSubsets = 1 << n;//2^n
    for(int i = 0;i < maxSubsets;i++) {
        vector<int> tmp = convertToSubset(i,nums);
        result.push_back(tmp);
    }
}

int main()
{
    vector<int> arr = {1,2,3};
    vector<vector<int>> result;
    subsets(arr, result);
    for(int i = 0;i < result.size();i++) {
        for(int j = 0;j < result[i].size();j++) {
            cout << result[i][j] << ",";
        }
        cout << endl;
    }        
}

