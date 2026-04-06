class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int > comp;
        for(int i = 0; i<nums.size(); i++){
            if(comp.count(nums[i])) return vector<int>{comp[nums[i]],i};
            comp[target-nums[i]] = i;
        }
        return vector<int>{-1,-1};
    }
};
