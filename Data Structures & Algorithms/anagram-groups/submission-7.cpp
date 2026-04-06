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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        static const int speedup = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();
        // unordered_map<int,string> anagramPats;
        vector<vector<string>>ans;
        // ans.push_back(vector<string>{strs[0]});
        for(int i=0; i<strs.size(); i++){
            bool matched = false;
            for(auto &x : ans){
                if(checkAnagram(x[0], strs[i])){
                    matched = true;
                    x.push_back(strs[i]);
                    break;
                }
            }
            if(!matched) ans.push_back(vector<string>{strs[i]});
        }
        return ans;
    }
};
