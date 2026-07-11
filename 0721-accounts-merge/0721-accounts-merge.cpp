class dsu {
public:
    vector<int> parents, size;

    dsu(int n) {
        parents.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parents[i] = i;
    }

    int find(int node) {
        if (parents[node] == node)
            return node;
        return parents[node] = find(parents[node]);
    }

    void unionsize(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return;

        if (size[pu] < size[pv]) {
            parents[pu] = pv;
            size[pv] += size[pu];
        } else {
            parents[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();

        dsu ds(n);
        map<string, int> mp;

        // Union accounts having same email
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {   // j++, not i++

                if (mp.find(accounts[i][j]) == mp.end())
                    mp[accounts[i][j]] = i;
                else
                    ds.unionsize(i, mp[accounts[i][j]]);
            }
        }

        vector<vector<string>> temp(n);

        // Group emails by parent
        for (auto &it : mp) {
            string mail = it.first;
            int node = it.second;

            int parent = ds.find(node);      // ds.find(), not dsu.find()

            temp[parent].push_back(mail);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {

            if (temp[i].empty())
                continue;

            sort(temp[i].begin(), temp[i].end());

            vector<string> a;
            a.push_back(accounts[i][0]);     // accounts, not account

            for (auto &mail : temp[i])
                a.push_back(mail);

            ans.push_back(a);
        }

        return ans;
    }
};