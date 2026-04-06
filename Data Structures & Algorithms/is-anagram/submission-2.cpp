class Solution {
public:
    bool isAnagram(string s, string t) {
        int alphabet[26] = {};

        for(char c : s){
            alphabet[c-'a']++;
        }
        for(char c : t){
            alphabet[c-'a']--;
        }
        for(int i : alphabet){
            if(i!=0) return false;
        }
        return true;
    }
};
