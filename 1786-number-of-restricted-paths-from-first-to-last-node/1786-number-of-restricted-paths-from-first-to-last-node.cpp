class Solution {
public:

int  dfs(vector<vector<pair<int,int>>>&adj,vector<int>&dp,int node,vector<long long >&dt){
    if(node == adj.size()-1) return 1;
    if(dp[node]!=-1) return dp[node];
  long long ans =0;
  long long mod =1e9 +7;
  for(auto&i:adj[node]){
   if(dt[i.first] < dt[node])  ans  = (ans + dfs(adj,dp,i.first,dt))%mod;
  }
   return  dp[node] =ans%mod;
}
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto&i:edges){
            adj[i[0]-1].push_back({i[1]-1,i[2]});
            adj[i[1]-1].push_back({i[0]-1,i[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,n-1});
        vector<long long >dt(n,INT_MAX);
        dt[n-1] =0;
        while(!pq.empty()){
            int dist = pq.top().first; // dist
             int node = pq.top().second;//node
             pq.pop();

             if(dist > dt[node] ) continue;
              for(auto&i:adj[node]){
                int newwt= i.second;
                int vi =i.first;

                if(dt[vi] > dist +newwt){
                    dt[vi]= dist+newwt;
                    pq.push({dt[vi],vi});
                }
              }

        }
    vector<int>dp(n,-1);
   return   dfs(adj,dp,0,dt);
  


        
     
    }
};
 