class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> numcnt;
        for(int i : nums){
            numcnt[i]++;
            if (numcnt[i] > 1) return true;
        }
        return false;
    }
};