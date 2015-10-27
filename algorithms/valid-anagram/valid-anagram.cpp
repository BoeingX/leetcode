/**
 * Given two strings s and t, write a function to determine if t is an anagram of s.
 * 
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * 
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your solution to such case?
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        int counts[26], countt[26];
        for(int i = 0; i < 26; i++){
            counts[i] = 0;
            countt[i] = 0;
        }
        for(int i = 0; i < s.length(); i++){
            counts[s[i]-'a']++;
            countt[t[i]-'a']++;
        }
        for(int i = 0; i < 26; i++)
            if(counts[i]!=countt[i])
                return false;
        return true;
    }
};
