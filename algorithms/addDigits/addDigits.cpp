/**
 * Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
 * 
 * For example:
 * 
 * Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
 * 
 * Follow up:
 * Could you do it without any loop/recursion in O(1) runtime?
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        if(num == 0)
            return num;
        int tmp = num / 10;
        int sum_step = num % 10;
        while(tmp > 0){
            sum_step += tmp % 10;
            tmp /= 10;
        }
        return addDigits(sum_step);
    }
};

int main(){
    Solution solution;
    cout<<solution.addDigits(38)<<endl;
    return 0;
}
