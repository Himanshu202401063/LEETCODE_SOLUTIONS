class Solution {
public:


bool  dfs(int node,int val,vector<int>&vis,vector<vector<int>>&graph){
vis[node]=val;
for(auto&i:graph[node]){
    if(vis[i]==-1) {if(dfs(i,1-val,vis,graph)) return 1;}
    else if( vis[i]==val) return 1;
}
 return 0;
}
  bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> vis(n, -1);

    for(int i = 0; i < n; i++) {
        if(vis[i] == -1) {
            if(dfs(i, 0, vis, graph))
                return false;
        }
    }

    return true;
}
};