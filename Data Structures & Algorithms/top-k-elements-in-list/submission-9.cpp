class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> numFreq;
        map<int,vector<int>>freqNum;
        vector<int> ans;
        for(int i : nums){
            auto it = numFreq.find(i);
            if(it!=numFreq.end()) numFreq[i]++;
            else numFreq[i] = 1;
        }
        for(auto &[first,second] : numFreq){
            freqNum[second].push_back(first);
        }
        auto it = freqNum.end();
        while(k){
            it--;
            for(int i: it->second){
                ans.push_back(i);
                k--;
            }
        }
        return ans;
    }
};
