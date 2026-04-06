class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> counts;
    for (int n : nums) counts[n]++;

    // Index = frequency, Value = list of numbers with that frequency
    vector<vector<int>> buckets(nums.size() + 1);
    for (auto const& [val, freq] : counts) {
        buckets[freq].push_back(val);
    }

    vector<int> result;
    // Start from the largest possible frequency bucket
    for (int i = buckets.size() - 1; i >= 0 && result.size() < k; --i) {
        for (int num : buckets[i]) {
            result.push_back(num);
            if (result.size() == k) break;
        }
    }
    return result;
}
};
