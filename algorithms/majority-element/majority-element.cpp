/**
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

 * You may assume that the array is non-empty and the majority element always exist in the array.
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> tmp;
        if(nums.size() == 1)
            return nums[0];
        for(int i = 0; i < nums.size(); i++){
            map<int,int>::iterator it = tmp.find(nums[i]);
            if(it == tmp.end()){
                std::pair<int, int> p(nums[i], 1);
                tmp.insert(p);
            }
            else{
                it->second = it->second+1;
                if(it->second > nums.size()/2)
                    return it->first;
            }
        }
    }
};
