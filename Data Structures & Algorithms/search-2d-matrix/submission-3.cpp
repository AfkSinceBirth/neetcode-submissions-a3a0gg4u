class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        //binary Search
        int s=0;
        int l=m*n-1;
        while(s<=l){
            int mid = s+(l-s)/2;
            int i = mid/n;
            int j= mid%n;

            if(target > matrix[i][j]) s = mid+1;
            else if(target < matrix[i][j]) l = mid-1;
            else return true;
        }
        return false;
    }
};
