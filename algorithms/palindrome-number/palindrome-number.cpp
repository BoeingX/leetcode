/**
 * Determine whether an integer is a palindrome. Do this without extra space.
 *
 * click to show spoilers.
 *
 * Some hints:
 * Could negative integers be palindromes? (ie, -1)
 *
 * If you are thinking of converting the integer to string, note the restriction of using extra space.
 *
 * You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
 *
 * There is a more generic way of solving this problem.
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int reverseInteger(int x){
        int s = 0;
        while(x > 0){
            s = s*10 + x%10;
            x /= 10;
        }
        return s;
    }
    bool isPalindrome(int x) {
        return (x >= 0) && reverseInteger(x) == x;
    }
};

int main(){
    Solution solution;
    cout<<solution.isPalindrome(123454321)<<endl;
    return 0;
}
