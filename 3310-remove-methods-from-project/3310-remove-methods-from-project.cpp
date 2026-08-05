class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
       
        vector<vector<int>>adj(n);
        vector<int>ind(n,0);
        for(auto&i:invocations){
            adj[i[0]].push_back(i[1]);
            ind[i[1]]++;
        }
        queue<int>q;
        q.push(k);
        vector<int>vis(n,0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(vis[node]) continue;
            vis[node]=1;
            for(auto&i:adj[node]){
                if(!vis[i]) q.push(i);
            }
        }
        bool ok =0;
        for(auto&i:invocations){
            int u = i[0];
            int v =  i[1];
            if(vis[v] && !vis[u]){
                ok= 1;
                break;
            }
        }
        vector<int>ans;
        if(ok) for(int i=0;i<n;i++)ans.push_back(i);
        else {
            for(int i=0;i<n;i++)if(!vis[i]) ans.push_back(i);
        }
         return ans;
    }
};