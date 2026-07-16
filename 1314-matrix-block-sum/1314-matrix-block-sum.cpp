class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> pref(m, vector<int>(n, 0));

        pref[0][0] = mat[0][0];

        for (int j = 1; j < n; j++) {
            pref[0][j] = pref[0][j - 1] + mat[0][j];
        }

        for (int i = 1; i < m; i++) {
            pref[i][0] = pref[i - 1][0] + mat[i][0];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                pref[i][j] = pref[i - 1][j]
                           + pref[i][j - 1]
                           - pref[i - 1][j - 1]
                           + mat[i][j];
            }
        }

        vector<vector<int>> ans(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int x1 = max(0, i - k);
                int y1 = max(0, j - k);

                int x2 = min(m - 1, i + k);
                int y2 = min(n - 1, j + k);

                int sum = pref[x2][y2];

                if (x1 > 0) sum -= pref[x1 - 1][y2];

                if (y1 > 0) sum -= pref[x2][y1 - 1];

                if (x1 > 0 && y1 > 0)
                    sum += pref[x1 - 1][y1 - 1];

                ans[i][j] = sum;
            }
        }

        return ans;
    }
};