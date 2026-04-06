class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<int>> allCharSet;
        vector<vector<string>> ans;
        
        for(string s : strs){
            vector<int> currCharSet(26,0);
            for(char c: s){
                currCharSet[c-'a']++;
            }
            if(allCharSet.size() == 0){
                allCharSet.push_back(currCharSet);
                ans.push_back(vector<string>{s});
                continue;
            }
            bool charSetAlreadyExists = false;
            for(int i =0; i<allCharSet.size(); i++){
                if(currCharSet == allCharSet[i]){
                    ans[i].push_back(s);
                    charSetAlreadyExists =true;
                    break;
                }
            }
            if(!charSetAlreadyExists){
                allCharSet.push_back(currCharSet);
                ans.push_back(vector<string>{s});
            }
        }
        return ans;
    }
};
