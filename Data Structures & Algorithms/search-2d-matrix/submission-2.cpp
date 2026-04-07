class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto v : matrix){
            for( int i : v){
                if(i==target) return true;
            }
        }
        return false;
    }
};
