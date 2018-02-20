
/*Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space
*/

/*Approach: Very interesting question, without taking extra space and in O(n), this algo places a positive number at its right
index. The while loop is key since it makes sure that before moving to the next index, the number at the current index gets
placed at the right index.*/

   int firstMissingPositive(vector<int>& nums) {
        
        size_t n = nums.size();
        
        for(int i = 0;i < n ;i++) {
           while(nums[i] > 0  && nums[i] <= n && nums[i] != nums[nums[i]-1]) {
               swap(nums[i],nums[nums[i]-1]);
           }
        }
        
        for(int i = 0;i < n;i++) {
           if(nums[i] != i+1)
               return i+1;
        }
        return n+1;   
    }
