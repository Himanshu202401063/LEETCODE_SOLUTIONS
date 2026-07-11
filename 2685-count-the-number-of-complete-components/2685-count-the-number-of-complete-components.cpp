class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis,vector<int>&comp) {
        vis[node] = 1;
         comp.push_back(node);
        for (auto& i : adj[node]) {
            
            if (!vis[i])
            
                dfs(i, adj, vis,comp);
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(n, 0);
      
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
               
  vector<int>comp;
                dfs(i, adj, vis,comp);
                int k = comp.size();
                int sum=0;
                for(auto&i:comp){
                    sum += adj[i].size();
                }
                 ans += (((k-1)*k)/2 == sum/2);
               
            }
        }
        return ans;
    }
};