class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;
        
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char val = board[r][c];
                
                if (val != '.') {
                    string rowKey = "row_" + to_string(r) + "_" + val;
                    string colKey = "col_" + to_string(c) + "_" + val;
                    string boxKey = "box_" + to_string(r / 3) + "_" + to_string(c / 3) + "_" + val;
                    
                    if (seen.count(rowKey) || seen.count(colKey) || seen.count(boxKey)) {
                        return false;
                    }
                    
                    seen.insert(rowKey);
                    seen.insert(colKey);
                    seen.insert(boxKey);
                }
            }
        }
        return true;
    }
};