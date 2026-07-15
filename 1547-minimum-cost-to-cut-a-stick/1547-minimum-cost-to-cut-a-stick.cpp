class Solution {
public:


int rec(int st,int en,vector<int>& cuts,vector<vector<long long>>&dp)
{    if(st > en) return 0;

    if(dp[st][en]!=-1) return dp[st][en];
    int ans = INT_MAX;
 
  
    for(int l = st;l<=en;l++)
    {
       
            ans = min(ans,
                               cuts[en+1]-cuts[st-1]+
                      rec(st,l-1,cuts,dp) +
                      rec(l+1,en,cuts,dp));
        
    }

   
    return dp[st][en]= ans;
}
    int minCost(int n, vector<int>& cuts) {
             int c = cuts.size();
             cuts.push_back(n);
             cuts.insert(cuts.begin(),0);
             sort(cuts.begin(),cuts.end());

        vector<vector<long long>>dp(c+1,vector<long long>(c+1,-1));
        return rec(1,c,cuts,dp);

        
    }
};