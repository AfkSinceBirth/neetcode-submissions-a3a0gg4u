class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        h.push_back(0); 
        int n = h.size();
        
        vector<int> stk;
        int maxArea = 0;
        
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && h[stk.back()] > h[i]) {
                int height = h[stk.back()];
                stk.pop_back();
                
                int width = stk.empty() ? i : i - stk.back() - 1;
                
                maxArea = max(maxArea, height * width);
            }
            stk.push_back(i);
        }
        
        return maxArea;
    }
};