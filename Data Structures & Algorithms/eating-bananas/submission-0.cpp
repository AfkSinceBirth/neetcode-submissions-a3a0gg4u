class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int l = *max_element(piles.begin(), piles.end());
        int result = l;
        while(s<=l){
            int mid = s + (l-s)/2;
            int hoursSpent = 0;
            for(int pile : piles){
                hoursSpent += ceil((double)pile/mid);
            }

            if(hoursSpent <= h){
                result = mid;
                l = mid -1;
            }
            else s = mid + 1;
        }
        return result;
    }
};
