/**
 * Given a non-negative number represented as an array of digits, plus one to the number.
 *
 * The digits are stored such that the most significant digit is at the head of the list.
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if(n == 0){
            vector<int> res = {1};
            return res;
        }
        if(digits[digits.size()-1] < 9){
            vector<int> res(digits);
            res[res.size()-1] += 1;
            return res;
        }
        vector<int> sub(digits.begin(), digits.begin()+n-1);
        vector<int> res = plusOne(sub);
        res.push_back(0);
        return res;
    }
};

int main(){
    Solution solution;
    vector<int> test = {9, 9, 9, 9, 9};
    vector<int> res = solution.plusOne(test);
    for(size_t i = 0; i < res.size(); i++)
        cout<<res[i];
    cout<<endl;
    return 0;
}
