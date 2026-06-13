class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size(),0);
        long long product1 = 1;
        long long product2 = 1;
        int zeros = 0;
        for(int i : nums) {
            if(i) {
                product1 *= i;
                product2 *= i;
            }
            else{
                zeros++;
                if(zeros >= 2) return output;
                product1 *= i;
            }
            }
        for(int i =0; i< nums.size(); i++){
            if(nums[i]) output[i] = product1/nums[i];
            else output[i] = product2;
        }
        return output;
    }
};
