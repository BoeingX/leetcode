/**
 * Given two strings s and t, determine if they are isomorphic.
 *
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 *
 * All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
 *
 * For example,
 * Given "egg", "add", return true.
 *
 * Given "foo", "bar", return false.
 *
 * Given "paper", "title", return true.
 *
 * Note:
 * You may assume both s and t have the same length.
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        const int MAX_CHAR = 256;
        vector<char> mapST(MAX_CHAR, 0), mapTS(MAX_CHAR, 0);
        for(size_t i = 0; i < s.size(); i++){
            if(mapST[s[i]] == 0 && mapTS[t[i]] == 0){
                mapST[s[i]] = t[i];
                mapTS[t[i]] = s[i];
            }
            else{
                if(!(mapST[s[i]] == t[i] && mapTS[t[i]] == s[i]))
                    return false;
            }
        }
        return true;
    }
};

int main(){
    Solution solution;
    cout<<solution.isIsomorphic("paper","title")<<endl;
    return 0;
}
