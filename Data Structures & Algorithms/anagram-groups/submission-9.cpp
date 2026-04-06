class Solution {
public:
    string genPat(string s){
        vector<int> pat(26,0);
        for(char c: s) pat[c-'a']++;
        string patStr = "";
        for(int i:pat){
            patStr+=char(i);
            patStr+='#';
        }
        return patStr;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        static const int speedup = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();
        unordered_map<string, int> patIndex;
        vector<vector<string>>ans;
        int x = 0; //represent the next index of ans where new pattern string vector will be added.
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
