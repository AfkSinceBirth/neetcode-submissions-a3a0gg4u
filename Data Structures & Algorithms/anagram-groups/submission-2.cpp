class Solution {
public:
    bool checkAnagram(string s1, string s2){
                int alphabet[26] = {};
                if(s1.size() != s2.size()) return false;
                for(int i=0; i<s1.size(); i++){
                    alphabet[s1[i] - 'a']++;
                    alphabet[s2[i] - 'a']--;
                }
                for(int i : alphabet){
                    if(i) return false;
                }
                return true;
            }
    vector<int> genPat(string s){
        vector<int> pat(26,0);
        for(char c: s) pat[c-'a']++;
        return pat;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, int> patIndex;
        vector<vector<string>>ans;
        int x = 0;
        for(int i=0; i<strs.size(); i++){
            bool matched = false;
            auto pat = genPat(strs[i]);
            auto it = patIndex.find(pat);
            if(it!=patIndex.end())  ans[it->second].push_back(strs[i]);
            else{
                ans.push_back(vector<string>{strs[i]});
                patIndex[pat] = x;
                x++;
            }
        }
        return ans;
    }
};
