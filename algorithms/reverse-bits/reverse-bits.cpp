/**
 * Reverse bits of a given 32 bits unsigned integer.
 * 
 * For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
 * 
 * Follow up:
 * If this function is called many times, how would you optimize it?
 * 
 * Related problem: Reverse Integer
 */

#include <iostream>
#include <cstdint>
#include <bitset>
using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> bit(n);
        bitset<32> inv;
        for(int i = 0; i < 32; i++)
            inv[i] =  bit[32-i-1];
        cout<<inv<<endl;
        return inv.to_ulong();
    }
};

int main(){
    Solution solution; 
    cout<<solution.reverseBits(1)<<endl;
    return 0;
}
