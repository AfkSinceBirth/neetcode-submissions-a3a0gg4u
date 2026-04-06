class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        map<int,vector<int>> freqOrder;
        vector<int> ans;
        for(int i: nums){
            freq[i]++;
        }
        
        for(auto &[first, second] : freq) {
            freqOrder[second].push_back(first);
        }

        auto it = freqOrder.end();
        it--;
        while(k>0){
            for(int i : it->second) {
                ans.push_back(i);
                k--;
            }
            it--;
        }
        return ans;
    }
};
