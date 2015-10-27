/**
 * Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.empty())
            return false;
        int min = nums[0];
        int max = nums[0];
        for(size_t i = 0; i < nums.size(); ++i){
            if(nums[i] < min)
                min = nums[i];
            else if(nums[i] > max)
                max = nums[i];
        }
        vector<int> occur(max-min+1, 0);
        for(size_t i = 0; i < nums.size(); ++i){
            int tmp = nums[i] - min;
            if(occur[tmp] != 0)
                return true;
            occur[tmp] = 1;
        }
        return false;
    }
};

int main(){
    Solution solution;
    vector<int> test = {1, 2, 3, 3};
    cout<<solution.containsDuplicate(test)<<endl;
    return 0;
}
