class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> ans(26, 0);

        if(s.size() != t.size()) return false;

        for(char c : s){
            ans[c-'a']++;
        }
        for(char c : t){
            ans[c-'a']--;
        }
        for(int i : ans){
            if (i!= 0) return false;
        }
        return true;
    }
};
