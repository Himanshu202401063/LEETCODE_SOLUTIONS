class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        int i = 0;
        while (i < n) {
            int x = nums[i] + k;
            auto it = upper_bound(nums.begin(), nums.end(), x) - nums.begin();
            i = it;

            ans++;
            
        }
        return ans;
    }
};