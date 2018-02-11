/*10.3 Search in Rotated Array: Given a sorted array of n integers that has been rotated 
an unknown number of times, write code to find an element in the array. You may assume 
that the array was originally sorted in increasing order. 
EXAMPLE lnput:find5in{15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14} 
Output: 8 (the index of 5 in the array)   
*/

//Approach: O(lgn) time complexity. Use binary search but modified
//Determine which side of the array is sorted normally and then check
//if the target lies within the range of elements in that side.
//If not then search in the other side.

int search(vector<int>& nums, int target) {
        size_t n = nums.size();
        if(!n)
            return false;
        
        int l = 0;
        int h = n-1;
        
        while(l <= h) {
            int m = (l+h) >> 1;
            
            if(nums[m] == target)
                return m;
            
            else if(nums[l] == nums[m] && nums[m] == nums[h]) {
                l++;h--;
            }
            
            else if(nums[l] > nums[m]) { //right side is sorted normally
                if(target > nums[m] && target <= nums[h])
                    l = m+1; //search right
                else
                    h = m-1; //search left
            }
            else if(nums[l] <= nums[m]) { //left sorted normally
                if(target >= nums[l] && target < nums[m])
                    h = m-1; //search left
                else
                    l = m+1; //search right
            }
        }
        return -1;
    }
