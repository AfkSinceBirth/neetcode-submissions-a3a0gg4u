class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int l= nums.size();
        while(s<=l){
            int mid = s + (l-s)/2;

            if(target < nums[mid]) l = mid - 1;
            else if(target>nums[mid]) s= mid+1;
            else return mid;
        }
        return -1;
    }
};
