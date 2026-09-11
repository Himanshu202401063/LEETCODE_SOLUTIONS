class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[digits[i]]++;
        }

        int ans = 0;

        // First digit
        for (int i = 1; i <= 9; i++) {
            if (mp[i] == 0) continue;

            mp[i]--;

            // Second digit
            for (int j = 0; j <= 9; j++) {
                if (mp[j] == 0) continue;

                mp[j]--;

                // Last digit must be even
                for (int k = 0; k <= 9; k += 2) {
                    if (mp[k] > 0) {
                        ans++;
                    }
                }

                mp[j]++;
            }

            mp[i]++;
        }

        return ans;
    }
};