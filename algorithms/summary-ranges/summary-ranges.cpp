/**
 * Given a sorted integer array without duplicates, return the summary of its ranges.

 * For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> summary;
        size_t left = 0, right = 0, last = 0;
        while(right++ < nums.size()){
            if(right == nums.size() || nums[right] - nums[left] != right - left){
                if(right - left == 1)
                    summary.push_back(to_string(nums[left]));
                else
                    summary.push_back(to_string(nums[left]) + "->" + to_string(nums[right-1]));
                left = right;
            }
        }
        return summary;
    }
};

int main(){
    Solution solution;
    vector<int> test = {0, 1, 2, 4, 5 ,7};
    vector<string> summary = solution.summaryRanges(test);
    for(size_t i = 0; i < summary.size(); i++)
        cout<<summary[i]<<" ";
    cout<<endl;
    return 0;
}
