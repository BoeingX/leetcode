/**
 * Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 *
 * For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 * the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 *
 * click to show more practice.
 *
 * More practice:
 * If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 */
#include<iostream>
#include<vector>
#include<limits>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArrayDP(nums);
    }
    // Dynamic Programming
    int maxSubArrayDP(vector<int>& nums) {
        if(nums.empty()) 
            return 0;
        // global maximum
        int max_g = -numeric_limits<int>::max();
        // local maximum including current element
        int max_l = -numeric_limits<int>::max();
        for(auto it = nums.begin(); it != nums.end(); ++it){
            max_l = max_l < 0 ? *it : max_l + *it;
            max_g = max(max_l, max_g);
        }
        return max_g;
    }
    // Divide and Conquer
    int maxSubArrayRec(vector<int>& nums, int left, int right){
        if(left >= right - 1)
            return nums[left];
        int middle = left + (right - left)/2;
        int s1 = maxSubArrayRec(nums, left, middle);
        int s2 = maxSubArrayRec(nums, middle, right);
        //check max sum crossing the line
        int tmp;
        int s31 = -numeric_limits<int>::max();
        tmp = 0;
        for(int i = middle; i < right; i++){
            tmp += nums[i];
            if(tmp > s31)
                s31 = tmp;
        }
        int s32 = -numeric_limits<int>::max();
        tmp = 0;
        for(int i = middle - 1; i >= left; i--){
            tmp += nums[i];
            if(tmp > s32)
                s32 = tmp;
        }
        return max(max(s1, s2), s31 + s32);
    }
};
int main(){
    Solution s;
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<s.maxSubArray(v)<<endl;
    return 0;
}

