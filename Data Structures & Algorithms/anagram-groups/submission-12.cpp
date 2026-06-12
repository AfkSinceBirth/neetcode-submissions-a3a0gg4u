class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;
        
        for (const string& s : strs) {
            string t = s;
            sort(t.begin(), t.end()); // Anagrams become identical when sorted
            anagramGroups[t].push_back(s);
        }
        
        vector<vector<string>> ans;
        for (auto& pair : anagramGroups) {
            ans.push_back(move(pair.second));
        }
        
        return ans;
    }
};