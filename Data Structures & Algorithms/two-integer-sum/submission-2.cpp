class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int > comp;
        for(int i = 0; i<nums.size(); i++){
            auto it = comp.find(nums[i]);
            if(it != comp.end()) return vector<int>{it->second,i};
            comp[target-nums[i]] = i;
        }
        return vector<int>{-1,-1};
    }
};
