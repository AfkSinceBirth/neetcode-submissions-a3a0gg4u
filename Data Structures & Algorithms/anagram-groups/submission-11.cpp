class Solution {
public:

    string buildAnagramPattern(string s){
        string pat = "00000000000000000000000000";
        for(char c : s){
            int x = (int)pat[c-'a'];
            pat[c-'a'] = ++x;
        }
        return pat;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;
        vector<vector<string>> ans;
        for(string s : strs){
            string pat = buildAnagramPattern(s);
            auto it = anagramGroups.find(pat);
            if(it == anagramGroups.end()){
                anagramGroups[pat] = {s};
            }
            else{
                it->second.push_back(s);
            }
        }
        for(auto &[first,second] : anagramGroups){
            ans.push_back(second);
        }
        return ans;
    }
};
