class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        cin.tie(NULL);
        unordered_map<int, int> freq;

        for(int i : nums){
            if(freq.count(i)) return true;
            freq[i]++;
        }
        return false;
    }
};