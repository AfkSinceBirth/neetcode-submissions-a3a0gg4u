class Solution {
public:

    vector<int> buildAnagramPatternVector(string s){
        vector<int> v(26,0);
        for(char c : s){
            v[c-'a']++;
        }
        return v;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> anagramGroups;
        vector<vector<string>> ans;
        for(string s : strs){
            vector<int> anagramPattern = buildAnagramPatternVector(s);
            auto it = anagramGroups.find(anagramPattern);
            if( it == anagramGroups.end()){
                anagramGroups[anagramPattern] = {s};
            }
            else{
                it->second.push_back(s);
            }
        }
        for(auto &[first, second] : anagramGroups){
            ans.push_back(second);
        }
        return ans;
    }
};
