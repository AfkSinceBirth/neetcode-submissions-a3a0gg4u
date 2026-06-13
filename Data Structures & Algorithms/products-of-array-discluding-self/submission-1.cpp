class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixProducts(nums.size(),0);
        vector<int> suffixProducts(nums.size(),0);
        int zeros = 0;
        //prefix products
        for(int i=0; i<nums.size(); i++ ){
            if(!nums[i]){
                zeros++;
                if(zeros>=2) return suffixProducts;
            }
            if(!i) prefixProducts[i] = 1;
            else prefixProducts[i] = nums[i-1]*prefixProducts[i-1];
        }
        //suffix products
        for(int i=nums.size()-1; i>=0; i--){
            if(i == nums.size()-1) suffixProducts[i] = 1;
            else suffixProducts[i] = nums[i+1]*suffixProducts[i+1];
        }

        for(int i=0; i<nums.size(); i++){
            suffixProducts[i] = prefixProducts[i] * suffixProducts[i];
        }
        return suffixProducts;
    }
};
