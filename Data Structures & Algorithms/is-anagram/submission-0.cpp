class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> anagramCheck;

        for(char c : s){
            anagramCheck[c]++;
        }
        for(char c: t){
            anagramCheck[c]--;
        }
        for(auto &[key, value] : anagramCheck){
            if (value!=0) return false;
        }
        return true;
    }
};
