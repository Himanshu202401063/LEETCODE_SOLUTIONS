class Solution {
public:
    const long long MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        int n = s.size();

        // Prefix sum of digits
        vector<long long> sumPref(n + 1, 0);
        for (int i = 0; i < n; i++)
            sumPref[i + 1] = (sumPref[i] + (s[i] - '0')) % MOD;

        // Compressed non-zero digits
        string t;
        vector<int> pos;

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                t += s[i];
                pos.push_back(i);
            }
        }

        int m = t.size();

        // powers of 10
        vector<long long> p10(m + 1, 1);
        for (int i = 1; i <= m; i++)
            p10[i] = (p10[i - 1] * 10) % MOD;

        // Prefix number
        vector<long long> pref(m + 1, 0);
        for (int i = 0; i < m; i++)
            pref[i + 1] = (pref[i] * 10 + (t[i] - '0')) % MOD;

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            long long sum = (sumPref[r + 1] - sumPref[l] + MOD) % MOD;

            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            long long number = 0;

            if (L <= R) {
                int len = R - L + 1;
                number = (pref[R + 1] - pref[L] * p10[len] % MOD + MOD) % MOD;
            }

            ans.push_back((sum * number) % MOD);
        }

        return ans;
    }
};