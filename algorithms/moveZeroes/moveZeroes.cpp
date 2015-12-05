/**
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

 * For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

 * Note:
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * key words: double pointers
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        size_t left = 0, right = 0;
        while(right < nums.size()){
            if(nums[right])
                nums[left++] = nums[right];
            right++;
        }
        while(left < nums.size())
            nums[left++] = 0;
    }
};

int main(){
    Solution solution;
    vector<int> test = {0, 1, 0, 3, 12};
    solution.moveZeroes(test);
    for(size_t i = 0; i < test.size(); i++)
        cout<<test[i]<<" ";
    cout<<endl;
    return 0;
}
