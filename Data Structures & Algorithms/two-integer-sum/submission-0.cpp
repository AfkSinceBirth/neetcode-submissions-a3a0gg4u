class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> complementKey;
        for(int i=0; i<nums.size(); i++){
            auto it = complementKey.find(nums[i]);
            if( it!=complementKey.end()){
                return vector<int>{it->second,i};
            }

            int complement = target - nums[i];
            complementKey[complement] = i;
        }
        return vector<int>{-1,-1};
    }
};
