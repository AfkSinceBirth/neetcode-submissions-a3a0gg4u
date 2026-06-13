class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int,int> numFreq;
        for(int i: nums) numFreq[i]++;
        vector<vector<int>> bucket(n+1);
        for(auto &[i,j] : numFreq){
            bucket[j].push_back(i);
        }
        for(int i=n; i>=0; i--){
            for(int x : bucket[i]){
                ans.push_back(x);
                if(ans.size()==k) return ans;
            }
        }
        return ans;
    }
};
