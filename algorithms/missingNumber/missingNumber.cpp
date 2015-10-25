/**
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

 * For example,
 * Given nums = [0, 1, 3] return 2.

 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * key words: XOR
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int t = 0;
        /**
         * or more compactly
         * for(size_t i = 0; i < nums.size(); i++)
         *      t = t ^ nums[i] ^ i;
         * t = t ^ nums.size();
         */
        for(size_t i = 0; i < nums.size(); i++)
            t = t ^ nums[i];
        for(size_t i = 0; i < nums.size()+1; i++)
            t = t ^ i;
        return t;
    }
};

int main(){
    Solution solution;
    vector<int> test = {0, 1, 3};
    cout<<solution.missingNumber(test)<<endl;
    return 0;
}
