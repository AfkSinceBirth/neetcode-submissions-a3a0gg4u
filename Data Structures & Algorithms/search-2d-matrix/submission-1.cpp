class Solution {
public:

    bool binarySearch(vector<int>& nums, int target){
       int s=0;
       int l=nums.size();
       while(s<=l){
        int mid = s+ (l-s)/2;
        if(target > nums[mid]) s = mid +1 ;
        else if(target < nums[mid]) l = mid -1;
        else return true;
       } 
       return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto v : matrix){
            for( int i : v){
                if(i==target) return true;
            }
        }
        return false;
    }
};
